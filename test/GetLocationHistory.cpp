#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main(int argc, char* argv[])
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    const char *route_id = "AC16E7D338B551013FF34266FE81A5EE";

    // Dates are in Unix format
    int start_date = 1476910800;
    int end_date = 1477515540;

    const char* period = "custom";

    int ret = route.get_device_location(route_id, start_date, end_date, period);
    if (ret == 0)
        cout << "Device location history: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "No history for device found: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
    return 0;
}

