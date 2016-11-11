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

    int ret = route.get_users();
    if (ret == 0)
      cout << "Users:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
      cout << "Error reading users :" << route.get_err_code() << ": " << route.get_err_msg() << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
