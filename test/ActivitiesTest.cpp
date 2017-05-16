
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(ActivitiesTest, GetAll)
{
    int ret = pRoute->get_all_activities();
    ASSERT_EQ(0, ret);
}

TEST(ActivitiesTest, GetByType )
{
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
        if (pRoute->get_activities_by_type(type) == 0)
            foundActivities.push_back(type);
        else
            missingActivities.push_back(type);
    }

    ASSERT_EQ(22, foundActivities.size());
    ASSERT_EQ(0, missingActivities.size());
}

TEST(ActivitiesTest, GetByTeam)
{
    const char *route_id = "CA902292134DBC134EAF8363426BD247";
    int ret = pRoute->get_team_activities(route_id);
    ASSERT_EQ(0, ret);
}

int main(int argc, char** argv)
{
    CRoute4Me::init();
    pRoute = new CRoute4Me(KEY);

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    pRoute->cleanup();
    delete pRoute;

    return 0;
}
