#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(ActivitiesFixture, ActivitiesTest, 10, 10)
{
    pRoute->get_all_activities();
}

BENCHMARK(ActivitiesFixture, ActivitiesByTeam, 10, 10)
{
    const char *route_id = "CA902292134DBC134EAF8363426BD247";
    pRoute->get_team_activities(route_id);
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
