# Rout4me API C++ client

## Pre-requisites

Rout4me API C++ client depends on `libcurl` library, needed for client-side URL transfers. Before you can build the source, you need to install `libcurl`, e.g.: for Ubuntu it would be advisable to update your repositories and then proceed with

```bash
sudo apt-get install libcurl4-openssl-dev
```

If you want to know a bit more about `libcurl`, you should go on the official website and read about interfaces that cURL implements: http://curl.haxx.se/

Rout4me API C++ client uses `jsoncpp` library to manipulate with JSON; all needed source files are already inserted into the project of Rout4me API C++ client, and no additional actions are expected from the user.

## Build

To build Rout4me API C++ client as a standalone library

```bash
cd build
cmake ..
make
```

This will create a library in lib/ and build examples from test/

Then add `<Rout4me API C++ root>/lib/` to your library path and `<Rout4me API C++ root>/include/` to your include path.

When linking, link against `route4me` (e.g.: g++ example.cpp -o example -lroute4me).

Rout4me API C++ client comprises 2 core files:

* src/route4me.cpp - api calls/wrappers
* include/route4me.h - defines and class interfaces

and additional source files test/*.cpp containing exhaustive samples for each section of Rout4me API:

## Creating a Simple Route

```c++
    // global init
    CRoute4Me::init(); // need this to use libcurl global init
    // create an api wrapper object
    CRoute4Me route("11111111111111111111111111111111");
    // define a problem that we are to solve
    Json::Value params(Json::objectValue);
    params["route_name"] = "Single Driver Round Trip";
    params["algorithm_type"] = CRoute4Me::TSP;
    params["remote_ip"] = 0;
    params["member_id"] = 1;
    params["route_time"] = 0;
    params["route_max_duration"] = 86400;
    params["optimize"] = "Distance";
    params["distance_unit"] = "mi";
    params["travel_mode"] = "Driving";
    params["store_route"] = 1;
    params["device_type"] = "web";
    params["vehicle_capacity"] = 1;
    params["vehicle_max_distance_mi"] = 10000;
    params["directions"] = 1;
    // read addresses from a json file
    Json::Value addr;
    ifstream inf("addr.json");
    inf >> addr;
    // query to solve the optimization problem, defined in params
    if(route.run_optimization(addr, params) == 0)
    {
        // use Json::StyledWriter instead of Json::FastWriter for a human friendly output
        cout << "Single driver round trip:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else
    {
        // there is an error code and an error message in a human friendly format
        cout << "Err: " << route.get_err_code() << ": " << route.get_err_msg() << endl;
    }
    // global cleanup
    CRoute4Me::cleanup(); // need this to use libcurl global cleanup
```

## Receive status of the pending optimization problems

```c++
    const char *KEY = "11111111111111111111111111111111";
    // global init
    CRoute4Me::init();
    // create an api wrapper object
    CRoute4Me route(KEY);
    if(route.get_route_q() == 0)
    {
        Json::Value opt_lst = route.get_json_resp()["optimizations"];
        if(opt_lst.isArray())
        {
            std::cout << "Key = " << KEY << "; Optimization problems are:" << endl;
            for(unsigned i = 0; i < opt_lst.size(); i++)
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
    }
    // global cleanup
    CRoute4Me::cleanup();
```

### More examples

Please see test/*.cpp for more examples, which are to demonstrate examples of Route & GPS calls and some optimization problems (single driver, round trip, multiple driver, time window, re-optimization).
