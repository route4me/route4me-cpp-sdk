
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

TEST(ActvitiesTest, GetAll)
{
    CRoute4Me::init();
    CRoute4Me route(KEY);
    int ret = route.get_all_activities();
    ASSERT_EQ(0, ret);
    route.cleanup();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
