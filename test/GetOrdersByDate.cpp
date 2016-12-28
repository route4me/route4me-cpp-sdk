#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cerr << "Pass date in format YYMMDD" << endl;
        return -1;
    }
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);

    int ret = route.get_orders(0, argv[1]);
    if (ret == 0)
        cout << "Orders on 27 Dec 2016: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "No order inserted on this date: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    ret = route.get_scheduled_orders(0, argv[1]);
    if (ret == 0)
        cout << "Orders on 11 Nov 2016: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "No order scheduled for this date: " << Json::FastWriter().write(route.get_json_resp()) << endl;


    CRoute4Me::cleanup();
    return 0;
}

