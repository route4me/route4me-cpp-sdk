#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    ifstream inf("member_edit_data.json");
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

    if(route.modify_member(member, CRoute4Me::REQ_PUT) == 0)
    {
        cout << "User edited:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to modify member data " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
