#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(AddressBookFixture, GetAllContacts, 10, 10)
{
    const char *route_id = "CA902292134DBC134EAF8363426BD247";
    const char *route_destination_id = "174405709A";
    pRoute->get_route_notes(route_id, route_destination_id);
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
