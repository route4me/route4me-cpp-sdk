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

    Json::Value addr;
    inf >> addr;

    int ret = route.add_route_destinations(route_id, addr);
    if (ret == 0)
      cout << "Address added" << endl;
    else
      cout << "Error adding address" << endl;
    ret = route.add_route_notes(route_id, route_destination_id, "info");
    if (ret == 0)
      cout << "Note added" << endl;
    else
      cout << "Error adding note" << endl;
    ret = route.remove_address_from_route(route_id, route_destination_id);
    if (ret == 0)
      cout << "Address removed" << endl;
    else
      cout << "Error removing address :"  << Json::FastWriter().write(route.get_json_resp()) << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
