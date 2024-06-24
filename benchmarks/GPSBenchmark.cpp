#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(GPSFixture, Set, 10, 10)
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
}

int main()
{
    CRoute4Me::init();
    pRoute = new CRoute4Me(KEY);

    hayai::ConsoleOutputter consoleOutputter;

    hayai::Benchmarker::AddOutputter(consoleOutputter);
    hayai::Benchmarker::RunAllTests();

    pRoute->cleanup();
    return 0;
}
