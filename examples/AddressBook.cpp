////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "../include/route4me.h"

#define KEY "11111111111111111111111111111111"

using namespace std;

int main()
{
    // global init
    CRoute4Me::init();

    CRoute4Me route(KEY);
    Json::Value props(Json::objectValue);
    props["first_name"] = "John";
    props["last_name"] = "Smith";
    props["address_1"] = "Wall Street";
    props["cached_lat"] = 100500;
    props["cached_lng"] = 23450;

    if (route.add_address_book_contacts(props) == 0) {
      cout << "Address book:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
      cout << "Address book not added " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }

    if (route.get_address_book_contacts_by_text("Wall") == 0) {
      cout << "Found address:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
      cout << "Address not found: " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_address_book_contacts("4621569") == 0) {
      cout << "Found address:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
      cout << "Address book not found : " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    if (route.get_address_book_contacts("") == 0) {
      cout << "All contacts:" << endl << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    else {
      cout << "No contacts " << Json::FastWriter().write(route.get_json_resp()) << endl;
    }
    // global cleanup
    CRoute4Me::cleanup();

    return 0;
}
