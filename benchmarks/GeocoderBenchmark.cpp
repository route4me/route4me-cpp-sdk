#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(GeocoderFixture, BatchGeocoding, 10, 10)
{
    const char* addrs = "Los20%Angeles20%International20%Airport,20%CA";
    const char* format = "json";
    int ret = pRoute->batch_geocoding(addrs, format);
}

BENCHMARK(GeocoderFixture, ReverseGeocoding, 10, 10)
{
    const char* addrs = "33.945705,-118.391105";
    const char* format = "json";
    int ret = pRoute->reverse_geocoding(addrs, format);
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
