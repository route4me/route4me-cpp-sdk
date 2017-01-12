#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *route_id = "CA902292134DBC134EAF8363426BD247";

    int ret = route.log_custom_activity(route_id, "test", "test2");
    if (ret == 0)
        cout << "Writing log: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "Error writing log: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
}


