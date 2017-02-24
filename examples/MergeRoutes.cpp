#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    const char* route_ids="075594D31563C05ACCEBCAA77D026B2D";
            //6AF79B603C1B6C5AAC714CDD76687CC6";
    const char* depot_address="11921 N Dickinson Dr, Fredericksburg, VA 22407, USA";

    MapPoint point;
    point.lat = 38.285804;
    point.lng=-77.555054;

    if(route.merge_routes(route_ids, depot_address, point) == 0)
    {
        cout << "Routes merged:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to merge routes: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
