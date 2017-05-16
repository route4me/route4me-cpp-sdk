#include <iostream>
#include <vector>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

static void feedback(const std::vector<std::string>& data, const char* message)
{
    std::cout << message << std::endl;
    for (int i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << std::endl;
    }
}

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    std::vector<std::string> types;
    types.push_back("area-added");
    types.push_back("area-removed");
    types.push_back("area-updated");
    types.push_back("delete-destination");
    types.push_back("destination-out-sequence");
    types.push_back("driver-arrived-early");
    types.push_back("driver-arrived-late");
    types.push_back("driver-arrived-on-time");
    types.push_back("geofence-entered");
    types.push_back("geofence-left");
    types.push_back("insert_destination");
    types.push_back("mark-destination-departed");
    types.push_back("mark-destination-visited");
    types.push_back("member-created");
    types.push_back("member-deleted");
    types.push_back("member-modified");
    types.push_back("move-destination");
    types.push_back("note-insert");
    types.push_back("route-delete");
    types.push_back("route-optimized");
    types.push_back("route-owner-changed");
    types.push_back("update-destinations");

    std::vector<std::string> foundActivities, missingActivities;

    for (int i = 0; i < types.size(); ++i) {
        const char* type = types[i].c_str();
        if (route.get_activities_by_type(type) == 0)
            foundActivities.push_back(type);
        else
            missingActivities.push_back(type);
    }

    feedback(foundActivities, "Activities found for types:");
    feedback(missingActivities, "Activities missing for types:");

    CRoute4Me::cleanup();
    return 0;
}


