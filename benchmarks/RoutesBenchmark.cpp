#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;
const char *route_id = "CA902292134DBC134EAF8363426BD247";

BENCHMARK(RoutesFixture, GetAllRoutes, 10, 10)
{
    pRoute->get_multiple_routes();
}

BENCHMARK(RoutesFixture, ByPointPath, 10, 10)
{
    int ret = pRoute->get_route_path_points(route_id, "Points");
}

BENCHMARK(RoutesFixture, ByiD, 10, 10)
{
    int ret = pRoute->get_route_by_id(route_id);
}

BENCHMARK(RoutesFixture, ByDirection, 10, 10)
{
    int ret = pRoute->get_route_directions(route_id, 1);
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
