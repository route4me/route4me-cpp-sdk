////////////////////////////////////////////////////////////////////////////////
// Gets a status update on the pending optimization problems
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
    int ret = 0;
    if(route.get_route_q() == 0)
    {
        //cout << "Status update for the key " << KEY << " is:" << endl << route.get_raw_resp() << endl;
        //cout << "Status update for the key " << KEY << " is:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
        Json::Value opt_lst = route.get_json_resp()["optimizations"];
        if(opt_lst.isArray())
        {
            std::cout << "Key = " << KEY << "; Optimization problems are:" << endl;
            unsigned optListSize = opt_lst.size();
            for(unsigned i = 0; i < optListSize ; ++i)
            {
                string id = opt_lst[i]["optimization_problem_id"].asString();
                int state = opt_lst[i]["state"].asInt();
                cout << "    " << id << " in state " << state << endl;
            }
        }
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
