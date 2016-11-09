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
    const char *route_destination_id = "174405709A";

    int ret = route.get_address(route_id, route_destination_id);
    if (ret == 0) {
      cout << "Route address by ID:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
      cout << "Error reading address: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
      ret = -1;
    }
    if (route.duplicate_route(route_id, "none") == 0) {
      cout << "Duplicated route " << endl;
    }
    else {
      cout << "Duplicating problem for route " << route_id << endl;
    }

    ifstream inf("update_route_destination_custom_data.json");
    if(!inf.is_open()) {
      cout << "Cannot find a file with route data" << endl;
      return -1;
    }
    Json::Value input_data;
    inf >> input_data;

    if (route.update_route(route_id, route_destination_id, input_data) == 0) {
       cout << "Route updated:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
       cout << "Error updating route: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
       ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
