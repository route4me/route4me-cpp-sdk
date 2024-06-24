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
    ifstream inf("add_address_to_route.json");
    if(!inf.is_open())
    {
        cout << "cannot find a file with addresses" << endl;
        return -1;
    }
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *route_id = "CA902292134DBC134EAF8363426BD247";
    const char *route_destination_id = "174405709A";

    int ret = route.add_route_notes(route_id, route_destination_id, "info");
    if (ret == 0)
      cout << "Note added" << endl;
    else
      cout << "Error adding note :" << route.get_err_code() << ": " << route.get_err_msg() << endl;

    ret = route.get_route_notes(route_id, route_destination_id);
    if (ret == 0)
      cout << "Notes:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
      cout << "No notes: " << route.get_err_code() << ": " << route.get_err_msg() << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
