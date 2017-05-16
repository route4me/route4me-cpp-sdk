
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(GPSTest, SetPosition)
{
    Json::Value params(Json::objectValue);
    params["route_id"] = "AC16E7D338B551013FF34266FE81A5EE";
    params["format"] = CRoute4Me::Csv;
    params["lat"] = 33.14384;
    params["lng"] = -83.22466;
    params["course"] = 1;
    params["speed"] = 120;
    params["device_type"] = CRoute4Me::IPhone;
    params["device_guid"] = "TEST_GPS";
    params["device_timestamp"] = "2014-06-14 17:43:35";
    params["member_id"] = 1;
    int ret = pRoute->set_gps(params);
    ASSERT_EQ(0, ret);
}

int main(int argc, char** argv)
{
    CRoute4Me::init();
    pRoute = new CRoute4Me(KEY, true);

    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    pRoute->cleanup();
    delete pRoute;

    return 0;
}
