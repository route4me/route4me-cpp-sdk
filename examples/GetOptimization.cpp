#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;


int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *id = "2FB5F91365317758045DB9F19DF5A522";

    int ret = route.get_optimization(id);
    if (ret == 0)
       cout << "Optimization: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
       cout << "Optimization not found: " << Json::FastWriter().write(route.get_json_resp()) << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
