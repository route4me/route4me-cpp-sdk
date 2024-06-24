#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(AvoidanceZonesFixture, GetAllZones, 10, 10)
{
    pRoute->get_avoidance_zones();
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
