
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(GeocoderTest, BatchGeocoding)
{
    const char* addrs = "Los20%Angeles20%International20%Airport,20%CA";
    const char* format = "json";
    int ret = pRoute->batch_geocoding(addrs, format);
    ASSERT_EQ(0, ret);
}

TEST(GeocoderTest, ReverseGeocoding)
{
    const char* addrs = "33.945705,-118.391105";
    const char* format = "json";
    int ret = pRoute->reverse_geocoding(addrs, format);
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
