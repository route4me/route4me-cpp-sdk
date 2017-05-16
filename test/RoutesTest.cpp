
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;
const char *route_id = "CA902292134DBC134EAF8363426BD247";

TEST(RoutesTest, GetByDirections)
{    
    int ret = pRoute->get_route_directions(route_id, 1);
    ASSERT_EQ(0, ret);
}

TEST(RoutesTest, GetByPointPath)
{
    int ret = pRoute->get_route_path_points(route_id, "Points");
    ASSERT_EQ(0, ret);
}

TEST(RoutesTest, GetById)
{
    int ret = pRoute->get_route_by_id(route_id);
    ASSERT_EQ(0, ret);
}

TEST(RoutesTest, GetMultipleRoutes)
{
    int ret = pRoute->get_multiple_routes();
    ASSERT_EQ(0, ret);
}

TEST(RoutesTest, AddRouteDestinationsInvalidBody)
{
    const char *route_id = "CA902292134DBC134EAF8363426BD247";
    Json::Value addr;
    int ret = pRoute->add_route_destinations(route_id, addr);
    ASSERT_EQ(-9, ret);

}

TEST(RoutesTest, GetRouteManifest)
{
    Json::Value params(Json::objectValue);
    params["route_id"] = "AC16E7D338B551013FF34266FE81A5EE";
    params["directions"] = 1;
    params["route_path_output"] = CRoute4Me::Points;
    params["device_tracking_history"] = 1;
    params["limit"] = 10;
    params["offset"] = 5;
    int ret = pRoute->get_route(params);
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
