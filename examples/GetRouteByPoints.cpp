////////////////////////////////////////////////////////////////////////////////
// Gets a Route info by ID
////////////////////////////////////////////////////////////////////////////////

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

    if (route.get_route_path_points(route_id, "Points")) {
        cout << "Route :"  << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Route not found :"  << Json::FastWriter().write(route.get_json_resp()) << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
