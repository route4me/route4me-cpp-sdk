#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    const char* route_id = "5C15E83A4BE005BCD1537955D28D51D7";
    const char* address_id = "5C15E83A4BE005BCD1537955D28D51D7";

    if(route.mark_address_visited(route_id, address_id, true,1) == 0)
    {
        cout << "Marked:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to mark: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
