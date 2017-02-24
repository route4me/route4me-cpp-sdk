////////////////////////////////////////////////////////////////////////////////
// Track device location history
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
    const int POINTS = 3;
    const char *t[POINTS] = {"2014-07-28 17:23:35", "2014-07-28 17:33:35", "2014-07-28 17:43:35"};
    double speed0 = 120;
    double lng0 = -83.22466;
    const char *route_id = "AC16E7D338B551013FF34266FE81A5EE";
    Json::Value params(Json::objectValue);
    params["route_id"] = route_id;
    params["format"] = CRoute4Me::Csv;
    params["lat"] = 33.14384;
    params["course"] = 1;
    params["device_type"] = CRoute4Me::IPhone;
    params["device_guid"] = "TEST_GPS";
    params["member_id"] = 1;
    int ret = 0;
    for(int i = 0; i < POINTS; i++)
    {
        params["lng"] = lng0 - (double)i / 10;
        params["speed"] = speed0 + i * 10;
        params["device_timestamp"] = t[i];
        if(route.set_gps(params) != 0)
        {
            cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
            ret = -1;
            break;
        }
    }
    if(ret == 0)
    {
        Json::Value params2(Json::objectValue);
        params2["route_id"] = route_id;
        params2["device_tracking_history"] = 1;
        if(route.get_route(params2) == 0)
        {
            cout << "Track device location history:" << endl << Json::StyledWriter().write(route.get_json_resp()) << endl;
        }
        else
        {
            cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
            ret = -1;
        }
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}