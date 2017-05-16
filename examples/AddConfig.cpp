#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    ifstream inf("add_account_data.json");
    if(!inf.is_open())
    {
        cout << "cannot find data file" << endl;
        return -1;
    }
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);

    int ret = 0;

    Json::Value account;
    inf >> account;

    if(route.modify_config(account, CRoute4Me::REQ_POST) == 0)
    {
        cout << "Config added:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to add config " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
