#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    const char* addrs = "Los20%Angeles20%International20%Airport,20%CA";
    const char* format = "json";

    if(route.batch_geocoding(addrs, format) == 0)
    {
        cout << "Geocoding done:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Geocoding failed: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
