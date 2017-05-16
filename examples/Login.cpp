#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY, true);

    int ret = 0;

    Member member;
    member.email = "apitester@gmail.com";
    member.password1 = "123456";
    member.format = "json";

    if(route.authenticate_user(&member) == 0)
    {
        cout << "Login attempted:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        cout << "Failed to login: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
