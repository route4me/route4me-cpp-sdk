
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(OrdersTest, GetAllOrders)
{
    int ret = pRoute->get_all_orders();
    ASSERT_EQ(0, ret);
}

TEST(OrdersTest, GetCustomOrders)
{
    int ret = pRoute->get_custom_orders("order_id,member_id", 0, 100);
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
