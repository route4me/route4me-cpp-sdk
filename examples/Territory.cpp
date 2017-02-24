
#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    ifstream inf("territory.json");
    if(!inf.is_open()) {
        cout << "Cannot find a file with territory" << endl;
        return -1;
    }

    Json::Value territory_data;
    inf >> territory_data;
    CRoute4Me route(KEY);

     if (route.add_territory(territory_data) == 0) {
        cout << "Added territory:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Failed adding territory: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_territory("DCBBBF90D8E9399B99C4D6FF11ED999F") == 0) {
        cout << "Found territories:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "No territories found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.remove_territory("DCBBBF90D8E9399B99C4D6FF11ED999F") == 0) {
        cout << "Remove territory:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "Failed to remove territory: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_all_territories() == 0) {
        cout << "Found territories:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
        cout << "No territories found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    CRoute4Me::cleanup();
}

