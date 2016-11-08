
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
    ifstream inf("poly.json");
    if(!inf.is_open()) {
        cout << "Cannot find a file with avoidance zone" << endl;
        return -1;
    }
    Json::Value poly_data;
    inf >> poly_data;
    if (route.add_avoidance_zone("ABC", poly_data) == 0) {
        cout << "Added poly:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Failed adding poly: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_avoidance_zones() == 0) {
        cout << "All zones:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "No zones found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }

    if (route.get_avoidance_zone("") == 0) {
        cout << "Zone:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "No zone: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.update_avoidance_zone("ABC", poly_data) == 0) {
        cout << "Zone updated:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Zone update failed: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.remove_avoidance_zone("ABC") == 0) {
        cout << "Zone removed:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Zone removal failed: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_avoidance_zone("ABC") == 0) {
        cout << "Zone:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "No zone found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }

    CRoute4Me::cleanup();
}



