#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{    
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);

    int ret = 0;

    if(route.get_vehicles(5,10) == 0)
    {
        cout << "Vehicles data:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to get vehicles " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
