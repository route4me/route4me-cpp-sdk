////////////////////////////////////////////////////////////////////////////////
// Single driver route 10 stops
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
    params["route_name"] = "Single driver route 10 stops";
    params["algorithm_type"] = CRoute4Me::TSP;
    params["share_route"] = 0;
    params["optimize"] = CRoute4Me::Distance;
    params["distance_unit"] = CRoute4Me::MI;
    params["device_type"] = CRoute4Me::Web;
    int ret = 0;
    Json::Value addr0, addr;
    inf >> addr0;
    for(int i = 0; i < 10; i++)
        addr[i] = addr0[i];
    if(route.run_optimization(addr, params) == 0)
    {
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "Single driver route 10 stops:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
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