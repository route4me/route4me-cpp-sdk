////////////////////////////////////////////////////////////////////////////////
// Reoptimize the problem
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    const char *id = "c46648541ca5d716a31ffae6f405a37d";
    int ret = 0;
    if(route.reoptimize(id) == 0)
    {
        Json::Value state = route.get_json_resp()["state"];
        if(state.isNull())
            cout << "Unknown response format" << endl;
        else
            cout << "The problem is reoptimized Ok, state is " << state;
    }
    else
    {
        cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
        ret = -1;
    }

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
