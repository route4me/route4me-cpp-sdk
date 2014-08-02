////////////////////////////////////////////////////////////////////////////////
// Gets Route manifest
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    Json::Value params(Json::objectValue);
    params["route_id"] = "AC16E7D338B551013FF34266FE81A5EE";
    params["directions"] = 1;
    params["route_path_output"] = CRoute4Me::Points;
    params["device_tracking_history"] = 1;
    params["limit"] = 10;
    params["offset"] = 5;
    int ret = 0;
    if(route.get_route(params) == 0)
    {
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "Route manifest:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
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