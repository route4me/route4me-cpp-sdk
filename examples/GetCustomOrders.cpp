#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main(int argc, char* argv[])
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);

    int ret = route.get_custom_orders("order_id,member_id", 0, 100);
    if (ret == 0)
        cout << "Orders with custom fields: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "No order with custom fields: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
    return 0;
}

