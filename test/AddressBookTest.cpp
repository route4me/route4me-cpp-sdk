
#include <route4me.h>
#include <gtest/gtest.h>

#define KEY "11111111111111111111111111111111"

CRoute4Me* pRoute;

TEST(AddressBookTest, GetAllContacts)
{
    int ret = pRoute->get_address_book_contacts();
    ASSERT_EQ(0, ret);
}

TEST(AddressBookTest, GetOneContact)
{
    int ret = pRoute->get_address_book_contacts_by_text("Wall");
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
