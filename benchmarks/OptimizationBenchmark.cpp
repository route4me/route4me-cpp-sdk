#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(OptimizationFixture, GetOptimization, 10, 10)
{
    const char *id = "2FB5F91365317758045DB9F19DF5A522";
    pRoute->get_optimization(id);
}

BENCHMARK(OptimizationFixture, Reoptimize, 10, 10)
{
    const char *id = "c46648541ca5d716a31ffae6f405a37d";
    int ret = pRoute->reoptimize(id);
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
