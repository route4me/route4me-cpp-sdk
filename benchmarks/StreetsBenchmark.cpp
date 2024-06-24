#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(StreetsFixture, GetAllStreets, 10, 10)
{
    pRoute->get_all_streets();
}

BENCHMARK(StreetsFixture, GetOneStreet, 10, 10)
{
    int seqno = 1;
    int ret = pRoute->get_street_address(seqno);
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
