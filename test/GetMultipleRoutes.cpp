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
   /* ifstream inf("addr.json");
    if(!inf.is_open())
    {
        cout << "cannot find a file with addresses" << endl;
        return -1;
    }*/
    // global init
    CRoute4Me::init();
    CRoute4Me route(KEY);

    int ret = 0;
    if(route.get_multiple_routes() == 0)
    {
        /*Json::Value addr;
        inf >> addr;*/
        cout << "All routes:" << endl << Json::StyledWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }
    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}

