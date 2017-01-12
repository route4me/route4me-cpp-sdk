#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;


int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    int ret = route.get_optimizations("1,2,3", 10, 5);
    if (ret == 0)
       cout << "Optimizations: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
       cout << "Optimizations not found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
