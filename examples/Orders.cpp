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

    ifstream inf("add_order_data.json");
    if(!inf.is_open())
    {
        cout << "cannot find a file with addresses" << endl;
        return -1;
    }

    Json::Value body;
    inf >> body;
    int ret = route.add_order(body);
    if (ret == 0)
        cout << "Order added: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "Error adding order: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    Json::Value orders;
    orders.append("1247");
    orders.append("1248");
    ret = route.remove_order(1, orders);
    if (ret == 0)
       cout << "Order removed: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
       cout << "Error removing order: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
}

