#include <hayai/hayai.hpp>
#include <route4me.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

BENCHMARK(AddressBookFixture, GetAllContacts, 10, 10)
{
    pRoute->get_address_book_contacts();
}

BENCHMARK(AddressBookFixture, GetOneContact, 10, 10)
{
    const char *id = "Wall";
    int ret = pRoute->get_address_book_contacts_by_text(id);
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
