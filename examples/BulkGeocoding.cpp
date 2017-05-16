#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    ifstream inf("bulk_geocoding_data.json");
    if(!inf.is_open()) {
        cout << "Cannot find file bulk_geocoding_data.json" << endl;
        return -1;
    }
    Json::Value data;
    inf >> data;

    if(route.json_geocoding(data) == 0)
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
