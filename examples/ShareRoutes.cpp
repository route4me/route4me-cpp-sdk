#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    const char* route_id = "CA902292134DBC134EAF8363426BD247";
    const char* email = "apitester@gmail.com";

    if(route.share_routes(route_id, email) == 0)
    {
        cout << "Delivered:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
