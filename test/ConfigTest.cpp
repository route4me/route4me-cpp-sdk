
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(NotesTest, GetRouteNotes)
{
    int ret = pRoute->get_config();
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
