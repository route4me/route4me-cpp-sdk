
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;
const char *route_id = "CA902292134DBC134EAF8363426BD247";
const char *route_destination_id = "174405709A";

TEST(NotesTest, GetRouteNotes)
{
    int ret = pRoute->get_route_notes(route_id, route_destination_id);
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
