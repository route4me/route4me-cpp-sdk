
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(OptimizationTest, ReOptimize)
{
    const char *id = "c46648541ca5d716a31ffae6f405a37d";
    int ret = pRoute->reoptimize(id);
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
