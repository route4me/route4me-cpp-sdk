#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    ifstream inf("member_delete_data.json");
    if(!inf.is_open())
    {
        cout << "cannot find data file" << endl;
        return -1;
    }
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);

    int ret = 0;

    Json::Value member;
    inf >> member;

    if(route.modify_member(member, CRoute4Me::REQ_DELETE) == 0)
    {
        cout << "User data deleted:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to delete user data " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
