#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    ifstream inf("add_order_to_route_data.json");
    if(!inf.is_open())
    {
        cout << "cannot find a file with addresses" << endl;
        return -1;
    }
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *route_id = "CA902292134DBC134EAF8363426BD247";

    if(route.get_route_by_id(route_id) == 0)
    {
        cout << "Route " << route_id << " info by ID:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
        Json::Value order;
        inf >> order;

        int ret = route.add_order_to_route(route_id, order);
        if (ret == 0)
            cout << "Order added to route" << route_id << endl;
        else
            cout << "Error adding order" << endl;
    }
    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}

