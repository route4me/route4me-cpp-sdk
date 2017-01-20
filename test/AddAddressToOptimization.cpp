

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
    const char *opt_id = "07372F2CF3814EC6DFFAFE92E22771AA";

    ifstream inf("address_for_optimization.json");
    if(!inf.is_open()) {
      cout << "Cannot find a file with address data" << endl;
      return -1;
    }
    Json::Value input_data;
    inf >> input_data;

    if (route.add_address_to_optimization(input_data, opt_id) == 0) {
       cout << "Route updated:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
       cout << "Error updating route: " << route.get_err_code() << ": " << route.get_err_msg() << endl;       
    }

    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
