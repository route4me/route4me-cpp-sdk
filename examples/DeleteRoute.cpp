////////////////////////////////////////////////////////////////////////////////
// Gets a Route info by ID
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *route_id = "AC16E7D338B551013FF34266FE81A5EEXXX";
    int ret = 0;
    if(route.delete_route(route_id) == 0)
    {
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "Response of delete route " << route_id << " is:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Error when delete route: code = " << route.get_err_code() << ", msg:" << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}