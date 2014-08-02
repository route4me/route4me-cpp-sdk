////////////////////////////////////////////////////////////////////////////////
// Single driver round trip
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    ifstream inf("addr.json");
    if(!inf.is_open())
    {
        cout << "cannot find a file with addresses" << endl;
        return -1;
    }

    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    Json::Value params(Json::objectValue);
    params["route_name"] = "Single Driver Round Trip";
    params["algorithm_type"] = CRoute4Me::TSP;
    params["remote_ip"] = 0;
    params["member_id"] = 1;
    params["route_time"] = 0;
    params["route_max_duration"] = 86400;
    params["optimize"] = CRoute4Me::Distance;
    params["distance_unit"] = CRoute4Me::MI;
    params["travel_mode"] = CRoute4Me::Driving;
    params["store_route"] = 1;
    params["device_type"] = CRoute4Me::Web;
    params["vehicle_capacity"] = 1;
    params["vehicle_max_distance_mi"] = 10000;
    params["directions"] = 1;
    int ret = 0;
    Json::Value addr;
    inf >> addr;
    if(route.run_optimization(addr, params) == 0)
    {
        Json::Value id = route.get_json_resp()["optimization_problem_id"];
        if(!id.isNull())
        {
            cout << "Optimized problem ID is " << id.asString() << " => reoptimizing..." << endl;
            if(route.reoptimize(id.asCString()) == 0)
            {
                cout << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
                Json::Value state = route.get_json_resp()["state"];
                if(state.isNull())
                    cout << "Unknown response format" << endl;
                else
                    cout << "The problem is reoptimized Ok, state is " << state;
            }
            else
            {
                cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
                ret = -1;
            }
        }
    }
    else
    {
        cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}