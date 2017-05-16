
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

    const char* session_id="4552222222";
    const char* member_id="787544566";

    int ret = route.validate_session(session_id, member_id);
    if (ret == 0)
      cout << "Session validated:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    else
      cout << "Validation failed :" << route.get_err_code() << ": " << route.get_err_msg() << endl;

    // global cleanup
    CRoute4Me::cleanup();

    return ret;
}
