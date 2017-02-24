
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(TrackingTest, AssetTrackingPositive)
{
    const char *id = "Q7G9P1L9";
    int ret = pRoute->asset_tracking(id);
    ASSERT_EQ(0, ret);
}

TEST(TrackingTest, AssetTrackingNegative)
{
    int ret = pRoute->asset_tracking("fake");
    ASSERT_EQ(-9, ret);
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
