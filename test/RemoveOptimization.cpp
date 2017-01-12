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
    ifstream inf("delete_optimization_data.json");
    if(!inf.is_open()) {
      cout << "Cannot find a file with route data" << endl;
      return -1;
    }
    Json::Value input_data;
    inf >> input_data;
    int ret = route.remove_optimization(input_data);

    if (ret == 0)
      cout << "Optimization removed: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
      cout << "Optimization not removed: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
