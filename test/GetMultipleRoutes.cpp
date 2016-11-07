////////////////////////////////////////////////////////////////////////////////
// Gets a Route info by ID
////////////////////////////////////////////////////////////////////////////////

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

    int ret = 0;
    if(route.get_multiple_routes() == 0)
    {
        cout << "All routes:" << endl << Json::StyledWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Error: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }
    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}

