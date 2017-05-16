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
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "Single driver round trip:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
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