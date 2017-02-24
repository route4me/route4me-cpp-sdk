
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(StreetsTest, GetAllStreets)
{
    int ret = pRoute->get_all_streets();
    ASSERT_EQ(0, ret);
}

TEST(StreetsTest, GetOneStreet )
{
    int seqno = 1;
    int ret = pRoute->get_street_address(seqno);
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
