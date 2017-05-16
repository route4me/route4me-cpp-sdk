////////////////////////////////////////////////////////////////////////////////
// Set GPS
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);
    Json::Value params(Json::objectValue);
    params["route_id"] = "AC16E7D338B551013FF34266FE81A5EE";
    params["format"] = CRoute4Me::Csv;
    params["lat"] = 33.14384;
    params["lng"] = -83.22466;
    params["course"] = 1;
    params["speed"] = 120;
    params["device_type"] = CRoute4Me::IPhone;
    params["device_guid"] = "TEST_GPS";
    params["device_timestamp"] = "2014-06-14 17:43:35";
    params["member_id"] = 1;
    int ret = 0;
    if(route.set_gps(params) == 0)
    {
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "GPS point is set:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
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
