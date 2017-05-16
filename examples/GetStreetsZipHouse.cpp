
#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    AddressData addr;
    addr.zipCode = "00601";
    addr.houseNumber = "17";
    int offset = 5, limit = 10;

    if(route.get_street_address(addr,offset,limit) == 0)
    {
        cout << "Address:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
