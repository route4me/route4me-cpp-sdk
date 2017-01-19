#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *id = "Q7G9P1L9";

    int ret = route.asset_tracking(id);
    if (ret == 0)
        cout << "Tracking: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "Tracking error: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
}


