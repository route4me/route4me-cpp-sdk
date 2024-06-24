
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

//TODO: Make this test really positive
TEST(AvoidanceZonesTest, GetZonePositive)
{
    const char *id = "A1";
    int ret = pRoute->get_avoidance_zone(id);
    ASSERT_EQ(-9, ret);
}

TEST(AvoidanceZonesTest, GetZoneNegative)
{
    int ret = pRoute->get_avoidance_zone("fake");
    ASSERT_EQ(-9, ret);
}

TEST(AvoidanceZonesTest, GetZones)
{
    int ret = pRoute->get_avoidance_zones();
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
