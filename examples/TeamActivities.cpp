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

    int ret = route.get_team_activities(route_id);

    if (ret == 0)
        cout << "Activities by team: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
        cout << "No activities by team: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    CRoute4Me::cleanup();
}


