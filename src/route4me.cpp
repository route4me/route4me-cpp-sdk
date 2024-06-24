
/**
 *
 * Rout4me API C++ client
 *
 */

#include <cstdlib>
#include <cstring>
#include <curl/curl.h>
#include <sstream>
#include "../include/route4me.h"

///////////////////////////////////////////////////////////////////////////////
// Constants
const char *CRoute4Me::MAIN_HOST = "https://www.route4me.com/";
const char *CRoute4Me::RAPID_HOST = "https://rapid.route4me.com/";

const char *CRoute4Me::R4_API_HOST = "api.v4/optimization_problem.php";
const char *CRoute4Me::R4_SHOW_ROUTE_HOST = "route4me.php";
const char *CRoute4Me::R4_ROUTE_HOST = "api.v4/route.php";
const char *CRoute4Me::R4_SET_GPS_HOST = "track/set.php";
const char *CRoute4Me::R4_ADDRESS_HOST = "api.v4/address.php";
const char *CRoute4Me::R4_DUPLICATE_ROUTE_HOST = "actions/duplicate_route.php";
const char *CRoute4Me::R4_ADD_ROUTE_NOTES = "actions/addRouteNotes.php";
const char *CRoute4Me::R4_ADDRESS_BOOK = "api.v4/address_book.php";
const char *CRoute4Me::R4_AVOIDANCE_HOST = "api.v4/avoidance.php";
const char *CRoute4Me::R4_ORDER_HOST = "api.v4/order.php";
const char *CRoute4Me::R4_ACTIVITIES = "api/get_activities.php";
const char *CRoute4Me::R4_USERS = "api/member/view_users.php";
const char *CRoute4Me::R4_TERRITORY_HOST = "api.v4/territory.php";
const char *CRoute4Me::AUTHENTICATION_SERVICE = "actions/authenticate.php";
const char *CRoute4Me::REGISTRATION_SERVICE = "actions/register_action.php";
const char *CRoute4Me::TRACKING_SERVICE = "api.v4/status.php";
const char *CRoute4Me::LOCATION_SERVICE = "api/track/get_device_location.php";
const char *CRoute4Me::MERGE_SERVICE = "actions/merge_routes.php";
const char *CRoute4Me::SHARE_SERVICE = "actions/route/share_route.php";
const char *CRoute4Me::ADDRESS_VISITED_SERVICE = "api/address/update_address_visited.php";
const char *CRoute4Me::GEOCODER = "api/geocoder.php";
const char *CRoute4Me::STREET_SERVICE = "street_data/";
const char *CRoute4Me::USER_LICENSE_SERVICE = "api/member/user_license.php";
const char *CRoute4Me::DEVICE_LICENSE_SERVICE = "api/device/verify_device_license.php";
const char *CRoute4Me::USER_SERVICE = "api.v4/user.php";
const char *CRoute4Me::VALIDATE_SESSION = "datafeed/session/validate_session.php";
const char *CRoute4Me::CONFIG_SERVICE = "api.v4/configuration-settings.php";
const char *CRoute4Me::VEHICLES_SERVICE = "api/vehicles/view_vehicles.php";
const char *CRoute4Me::PREVIEW_SERVICE = "actions/upload/csv-xls-preview.php";
const char *CRoute4Me::UPLOAD_SERVICE = "actions/upload/upload.php";
const char *CRoute4Me::UPLOAD_GEOCODING = "actions/upload/csv-xls-geocode.php";
const char *CRoute4Me::JSON_GEOCODING = "actions/upload/json-geocode.php";
const char *CRoute4Me::DEPARTED_SERVICE = "api/route/mark_address_departed.php";
const char *CRoute4Me::HYBRID_SERVICE = "api.v4/hybrid_date_optimization.php";

const char *CRoute4Me::Driving = "Driving";
const char *CRoute4Me::Walking = "Walking";
const char *CRoute4Me::Trucking = "Trucking";
const char *CRoute4Me::MI = "mi";
const char *CRoute4Me::KM = "km";

const char *CRoute4Me::Highways = "Highways";
const char *CRoute4Me::Tolls = "Highways";
const char *CRoute4Me::MinimizeHighways = "minimizeHighways";
const char *CRoute4Me::MinimizeTolls = "minimizeTolls";
const char *CRoute4Me::None = "";

const char *CRoute4Me::Distance = "Distance";
const char *CRoute4Me::Time = "Time";
const char *CRoute4Me::TimeWithTraffic = "timeWithTraffic";

const char *CRoute4Me::Web = "web";
const char *CRoute4Me::IPhone = "iphone";
const char *CRoute4Me::IPad = "ipad";
const char *CRoute4Me::AndroidPhone = "android_phone";
const char *CRoute4Me::AndroidTablet = "android_tablet";

const char *CRoute4Me::Csv = "csv";
const char *CRoute4Me::Serialized = "serialized";
const char *CRoute4Me::Xml = "xml";

const char *CRoute4Me::PathNone = "None";
const char *CRoute4Me::Points = "Points";

CRoute4Me::key2tp CRoute4Me::get_route_q_req[] = {
    {"state", Json::uintValue},
    {"limit", Json::uintValue},
    {"offset", Json::uintValue},
    {"device_tracking_history", Json::uintValue},
    {"route_path_output", Json::stringValue},
    {"route_id", Json::stringValue},
    {"directions", Json::uintValue}
};

CRoute4Me::key2tp CRoute4Me::set_gps_req[] = {
    {"format", Json::stringValue},
    {"member_id", Json::intValue},
    {"route_id", Json::stringValue},
    {"course", Json::intValue},
    {"speed", Json::realValue},
    {"lat", Json::realValue},
    {"lng", Json::realValue},
    {"device_type", Json::stringValue},
    {"device_guid", Json::stringValue},
    {"device_timestamp", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::get_route_address_req[] = {

    {"route_id", Json::stringValue},
    {"route_destination_id", Json::stringValue},
    {"notes", Json::booleanValue}

};

CRoute4Me::key2tp CRoute4Me::get_address_notes_req[] = {
    {"route_id", Json::stringValue},
    {"address_id", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::get__multiple_routes_req[] = {
    {"state", Json::uintValue},
    {"limit", Json::uintValue},
    {"offset", Json::uintValue}
};

CRoute4Me::key2tp CRoute4Me::get_address_book_contact_req[] = {
    {"address_id", Json::stringValue},
    {"limit", Json::uintValue},
    {"offset", Json::uintValue},
    {"start", Json::uintValue},
    {"query", Json::stringValue},
    {"fields", Json::stringValue},
    {"display", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::update_route_req[] = {
    {"route_id", Json::stringValue},
    {"route_destination_id", Json::stringValue}
  //  {"custom_fields", Json::arrayValue}
};

CRoute4Me::key2tp CRoute4Me::update_route_data_req[] = {
    {"route_id", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::duplicate_route_req[] = {
    {"route_id", Json::stringValue},
    {"to", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::delete_route_req[] = {
    {"route_id", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::add_address_notes_req[] = {
      {"route_id", Json::stringValue},
      {"address_id", Json::stringValue},
      {"dev_lat", Json::uintValue},
      {"dev_lng", Json::uintValue},
      {"device_type", Json::stringValue}
};

CRoute4Me::key2tp CRoute4Me::add_address_req[] = {
    {"route_id", Json::stringValue},
    {"route_destination_id", Json::stringValue}
};
///////////////////////////////////////////////////////////////////////////////
// Construction

CRoute4Me::CRoute4Me(const char *key, bool verbose) :
    m_key(key), m_err_code(0), m_curl(0), formpost(NULL), m_verbose(verbose)
{
    m_curl = curl_easy_init();
}

CRoute4Me::~CRoute4Me()
{
    if(m_curl)
        curl_easy_cleanup(m_curl);
    if (formpost)
        curl_formfree(formpost);
}

///////////////////////////////////////////////////////////////////////////////
// API calls

int CRoute4Me::get_route_q()
{
    Json::Value props(Json::objectValue);
    props["limit"] = 10;
    props["offset"] = 0;
    return get_route_q(props);
}

int CRoute4Me::get_route_q(Json::Value& props)
{
    props["api_key"] = m_key;
    if(!validate(props, CRoute4Me::get_route_q_req, sizeof(CRoute4Me::get_route_q_req)/sizeof(CRoute4Me::key2tp)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_API_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_multiple_routes()
{
    static const char* m[] = {"limit", "offset", "api_key"};
    Json::Value props(Json::objectValue);
    props["limit"] = 10;
    props["offset"] = 0;
    props["api_key"] = m_key;
    if(!validate(props, CRoute4Me::get__multiple_routes_req, sizeof(CRoute4Me::get__multiple_routes_req)/sizeof(CRoute4Me::key2tp)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_route_by_id(const char *route_id)
{
    Json::Value props(Json::objectValue);
    props["route_id"] = route_id;
    return get_route(props);
}

int CRoute4Me::get_route(Json::Value& props)
{
    static const char *m[] = {"route_id"};
    props["api_key"] = m_key;
    if(!validate(props, CRoute4Me::get_route_q_req, sizeof(CRoute4Me::get_route_q_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::update_route(const char* route_id, const char* dest_id, const Json::Value& fields)
{
    static const char *m[] = {"api_key", "route_id", "route_destination_id"};
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_destination_id"] = dest_id;

    if(!validate(props, CRoute4Me::update_route_req,
                 sizeof(CRoute4Me::update_route_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value body(fields);
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ROUTE_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::update_route(const char* route_id, const Json::Value& input_data)
{
    static const char *m[] = {"api_key", "route_id"};
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;

    if(!validate(props, CRoute4Me::update_route_data_req,
                 sizeof(CRoute4Me::update_route_data_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value body(input_data);
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ROUTE_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::duplicate_route(const char *route_id, const char* to)
{
    static const char *m[] = {"api_key", "route_id", "to"};
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["to"] = to;
    if(!validate(props, CRoute4Me::duplicate_route_req, sizeof(CRoute4Me::duplicate_route_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_DUPLICATE_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::delete_route(const char *route_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_route_path_points(const char *route_id, const char *route_path_output)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_path_output"] = route_path_output;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_route_directions(const char *route_id, int directions)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["directions"] = directions;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_route_query(const char *route_id, const char *query)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["query"] = query;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::add_route_destinations(const char* route_id, Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;

    if (!validate(props))
        return m_err_code;

    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ROUTE_HOST, props, body);

    return m_err_code;
}

int CRoute4Me::remove_address_from_route(const char* route_id, const char* route_destination_id)
{
    Json::Value props(Json::objectValue);

    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_destination_id"] = route_destination_id;

   if (!validate(props))
       return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_ADDRESS_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::merge_routes(const char *route_ids, const char *depot_address, MapPoint point, bool remove_origin)
{
    Json::Value props(Json::objectValue);

    props["api_key"] = m_key;
    struct curl_httppost *lastptr=NULL;

    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "route_ids",
                   CURLFORM_COPYCONTENTS, route_ids,
                   CURLFORM_END);

    curl_formadd(&formpost,
                  &lastptr,
                  CURLFORM_COPYNAME, "depot_address",
                  CURLFORM_COPYCONTENTS, depot_address,
                  CURLFORM_END);

    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "depot_lat",
                 CURLFORM_COPYCONTENTS, &point.lat,
                 CURLFORM_END);

    curl_formadd(&formpost,
                 &lastptr,
                 CURLFORM_COPYNAME, "depot_lng",
                 CURLFORM_COPYCONTENTS, &point.lng,
                 CURLFORM_END);


    if (!validate(props))
        return m_err_code;
     Json::Value null;
         request(CRoute4Me::REQ_POST, CRoute4Me::MERGE_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::share_routes(const char *route_id, const char *email, const char *format)
{
    Json::Value props(Json::objectValue);

    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["response_format"] = format;

    struct curl_httppost *lastptr=NULL;

    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "recipient_email",
                   CURLFORM_COPYCONTENTS, email,
                   CURLFORM_END);

    if (!validate(props))
        return m_err_code;
     Json::Value null;
     request(CRoute4Me::REQ_POST, CRoute4Me::SHARE_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::add_address_book_contacts(Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;   
    if (!validate(props))
        return m_err_code;
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_ADDRESS_BOOK, props, body);
    return m_err_code;
}

int CRoute4Me::get_address_book_contacts_by_text(const char* searchText)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["limit"] = 10;
    props["offset"] = 0;
    props["query"] = searchText;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ADDRESS_BOOK, props, null);
    return m_err_code;
}

int CRoute4Me::get_address_book_contacts(const char * address_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["address_id"] = address_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ADDRESS_BOOK, props, null);
    return m_err_code;
}

int CRoute4Me::get_address_book_contacts()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["limit"] = 10;
    props["offset"] = 0;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ADDRESS_BOOK, props, null);
    return m_err_code;
}

int CRoute4Me::update_address_book_contacts(const char* address_id, Json::Value &body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["address_id"] = address_id;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ADDRESS_BOOK, props, body);
    return m_err_code;
}

int CRoute4Me::remove_address_book_contacts(const char * address_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["address_id"] = address_id;
    if (!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_ADDRESS_BOOK, props, null);
    return m_err_code;
}

int CRoute4Me::add_route_notes(const char* route_id, const char* address_id, const char* input_data)
{
    static const char *m[] = {"route_id", "address_id", "dev_lat", "dev_lng", "device_type"};
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["address_id"] = address_id;
    props["dev_lat"] = 0;
    props["dev_lng"] = 1;
    props["device_type"] = "iphone";
    if(!validate(props, CRoute4Me::add_address_notes_req, sizeof(CRoute4Me::add_address_notes_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value body(input_data);
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_ADD_ROUTE_NOTES, props, body);
    return m_err_code;
}

int CRoute4Me::get_route_notes(const char* route_id, const char* route_destination_id)
{
    Json::Value props(Json::objectValue);
    static const char *m[] = {"route_id", "route_destination_id"};
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_destination_id"] = route_destination_id;
    if(!validate(props, CRoute4Me::get_route_address_req, sizeof(CRoute4Me::get_route_address_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ADDRESS_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::set_gps(Json::Value& props)
{
    static const char *m[] = {"format", "member_id", "route_id", "course", "speed", "lat", "lng", "device_type", "device_guid"};
    props["api_key"] = m_key;
    if(!validate(props, CRoute4Me::set_gps_req, sizeof(CRoute4Me::set_gps_req)/sizeof(CRoute4Me::key2tp), m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_SET_GPS_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::add_avoidance_zone(const char * territory_id, Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;

    if (!validate(props)) {
        return m_err_code;
    }

    request(CRoute4Me::REQ_POST, CRoute4Me::R4_AVOIDANCE_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::get_avoidance_zone(const char * territory_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_AVOIDANCE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_avoidance_zones()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_AVOIDANCE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::update_avoidance_zone(const char * territory_id, Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_AVOIDANCE_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::remove_avoidance_zone(const char * territory_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_AVOIDANCE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::add_territory(Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }

    request(CRoute4Me::REQ_POST, CRoute4Me::R4_TERRITORY_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::get_territory(const char * territory_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;

    if (!validate(props)) {
        return m_err_code;
    }

    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_TERRITORY_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_all_territories() {
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }

    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_TERRITORY_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::remove_territory(const char* territory_id) {
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["territory_id"] = territory_id;

    if (!validate(props)) {
        return m_err_code;
    }

    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_TERRITORY_HOST, props, null);
    return m_err_code;
}


int CRoute4Me::add_order(Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_ORDER_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::add_order_to_route(const char* route_id, Json::Value& body, int redirect)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["redirect"] = redirect;
    props["route_id"] = route_id;    
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ROUTE_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::get_order(const char * order_id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["order_id"] = order_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_all_orders()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::remove_order(int redirect, Json::Value& order_ids)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["redirect"] = redirect;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value body;
    body["order_ids"] = order_ids;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_ORDER_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::update_order(int redirect, Json::Value &body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["redirect"] = redirect;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ORDER_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::get_orders(int redirect, const char *date)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["redirect"] = redirect;
    props["day_added_YYMMDD"] = date;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_scheduled_orders(int redirect, const char *date)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["redirect"] = redirect;
    props["scheduled_for_YYMMDD"] = date;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_custom_orders(const char *fields, int offset, int limit)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["fields"] = fields;
    props["offset"] = offset;
    props["limit"] = limit;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_orders_query(const char *query, int offset, int limit)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["query"] =  query;
    props["offset"] = offset;
    props["limit"] = limit;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ORDER_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::run_optimization(const CAddressArray& addr, Json::Value& content)
{
    if(!validate(content))
        return m_err_code;
    Json::Value props;
    props["api_key"] = m_key;
    static const int N = 2;
    static const char *m[N] = {"directions", "optimized_callback_url"};
    for(int i = 0; i < N; i++)
    {
        if(content.isMember(m[i]))
        {
            props[m[i]] = content[m[i]];
            content.removeMember(m[i]);
        }
    }
    Json::Value byformat;
    byformat["addresses"] = addr.m_list;
    byformat["parameters"] = content;
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_API_HOST, props, byformat);
    return m_err_code;
}

int CRoute4Me::get_optimization(const char* optimization_problem_id)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["optimization_problem_id"] = optimization_problem_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_API_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_optimizations(const char* states, int limit, int offset)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["state"] = states;
    props["limit"] = limit;
    props["offset"] = offset;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_API_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::remove_optimization(const Json::Value& fields)
{
    Json::Value props;
    props["api_key"] = m_key;
    if (!validate(props)) {

        return m_err_code;
    }
    Json::Value body(fields);
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_API_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::remove_address_from_optimization(const char* address_id, const char * optimization_id)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["optimization_problem_id"] = optimization_id;
    props["route_destination_id"] = address_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_DELETE, CRoute4Me::R4_API_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::add_address_to_optimization(Json::Value body, const char *opt_id, bool reoptimize)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["optimization_problem_id"] = opt_id;
    props["reoptimize"] = reoptimize;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_API_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::reoptimize(const char *opt_id)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["optimization_problem_id"] = opt_id;
    props["reoptimize"] = 1;
    if(!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_API_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::get_all_activities()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["offset"] = 10;
    props["limit"] = 0;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ACTIVITIES, props, null);
    return m_err_code;
}

int CRoute4Me::get_team_activities(const char *route_id, const char *team)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["team"] = team;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ACTIVITIES, props, null);
    return m_err_code;
}

int CRoute4Me::log_custom_activity(const char *route_id, const char *activity_type,
                                   const char *activity_message)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value body(Json::objectValue);
    body["activity_type"] = activity_type;
    body["activity_message"] = activity_message;
    request(CRoute4Me::REQ_POST, CRoute4Me::R4_ACTIVITIES, props, body);
    return m_err_code;
}

int CRoute4Me::get_activities_by_type(const char *act_type)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["activity_type"] = act_type;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ACTIVITIES, props, null);
    return m_err_code;
}

int CRoute4Me::get_users()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_USERS, props, null);
    return m_err_code;
}

int CRoute4Me::authenticate_user(const Member* pMember)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    struct curl_httppost *lastptr=NULL;

    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "strEmail",
                   CURLFORM_COPYCONTENTS, pMember->email.c_str(),
                   CURLFORM_END);
    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "strPassword",
                   CURLFORM_COPYCONTENTS, pMember->password1.c_str(),
                   CURLFORM_END);
    curl_formadd(&formpost,
                   &lastptr,
                   CURLFORM_COPYNAME, "format",
                   CURLFORM_COPYCONTENTS, pMember->format.c_str(),
                   CURLFORM_END);

    Json::Value null;
    request(CRoute4Me::REQ_POST, CRoute4Me::AUTHENTICATION_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::modify_member(Json::Value& body, ReqType method)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }
    request(method, CRoute4Me::R4_USERS, props, body);
    return m_err_code;
}

int CRoute4Me::purchase_user_license(Json::Value &body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_POST, CRoute4Me::USER_LICENSE_SERVICE, props, body);
    return m_err_code;
}

int CRoute4Me::purchase_device_license(Json::Value &body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_POST, CRoute4Me::DEVICE_LICENSE_SERVICE, props, body);
    return m_err_code;
}

int CRoute4Me::asset_tracking(const char *id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["tracking"] = id;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::TRACKING_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::get_device_location(const char *route_id, int start_date, int end_date,
                                   const char *period, bool last_position, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["format"] = format;
    props["last_position"] = last_position;
    props["time_period"] = period;
    props["start_date"] = start_date;
    props["end_date"] = end_date;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::LOCATION_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::batch_geocoding(const char *addresses, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["addresses"] = addresses;
    props["format"] = format;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_POST, CRoute4Me::GEOCODER, props, null);
    return m_err_code;
}

int CRoute4Me::reverse_geocoding(const char *addresses, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["addresses"] = addresses;
    props["format"] = format;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_POST, CRoute4Me::GEOCODER, props, null);
    return m_err_code;
}

template <class T> void CRoute4Me::append_url(std::string& url, T arg) const
{
    std::stringstream ss;
    ss << arg;
    url += ss.str() + "/";
}

int CRoute4Me::get_street_address(int seqno)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }

    std::string url = std::string(CRoute4Me::STREET_SERVICE );
    append_url(url, seqno);
    Json::Value null;
    request(CRoute4Me::REQ_GET, url.c_str(), props, null, url.c_str());
    return m_err_code;
}

int CRoute4Me::get_street_address(const AddressData& addr, int offset, int limit)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }

    std::string url = std::string(CRoute4Me::STREET_SERVICE) +
                                  ((addr.houseNumber.empty()) ? "zipcode/" : "service/");
    url += addr.zipCode + "/";
    if (!addr.houseNumber.empty()) {
        url += addr.houseNumber + "/";
    }
    if (offset >= 0) {
        append_url(url, offset);
        append_url(url, limit);
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, url.c_str(), props, null);
    return m_err_code;
}

int CRoute4Me::get_all_streets(int limit, int offset)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }

    std::string url = std::string(CRoute4Me::STREET_SERVICE );

    if (offset >= 0) {
       append_url(url, offset);
       append_url(url, limit);
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, url.c_str(), props, null);
    return m_err_code;
}

int CRoute4Me::get_subusers()
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::USER_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::validate_session(const char *session_id, const char *member_id, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["session_guid"] = session_id;
    props["member_id"] = member_id;
    props["format"] = format;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::VALIDATE_SESSION, props, null);
    return m_err_code;

}

int CRoute4Me::get_config(const char *key)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (key)
    {
        props["config_key"] = key;
    }

    if (!validate(props)) {
        return m_err_code;
    }

    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::CONFIG_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::modify_config(Json::Value &value, ReqType method)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;

    if (!validate(props)) {
        return m_err_code;
    }

    request(method, CRoute4Me::CONFIG_SERVICE, props, value);
    return m_err_code;
}

int CRoute4Me::get_vehicles(int offset, int limit)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["offset"] = offset;
    props["limit"] = limit;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::VEHICLES_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::preview_file(const char *id, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["strUploadID"] = id;
    props["format"] = format;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::PREVIEW_SERVICE, props, null);
    return m_err_code;
}

int CRoute4Me::upload_file(const char *file_name, const char *format)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["format"] = format;

    if (!validate(props)) {
        return m_err_code;
    }
    Json::Value body;
    body["strFilename"] = file_name;
    request(CRoute4Me::REQ_POST, CRoute4Me::UPLOAD_SERVICE, props, body);
    return m_err_code;
}

int CRoute4Me::upload_geocoding(const char *id)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["strUploadID"] = id;

    if (!validate(props)) {
        return m_err_code;
    }

    Json::Value null;
    request(CRoute4Me::REQ_POST, CRoute4Me::UPLOAD_GEOCODING, props, null);
    return m_err_code;
}

int CRoute4Me::json_geocoding(Json::Value &body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    if (!validate(props)) {
        return m_err_code;
    }
    request(CRoute4Me::REQ_POST, CRoute4Me::JSON_GEOCODING, props, body);
    return m_err_code;
}

///////////////////////////////////////////////////////////////////////////////
// CURL wrapper

void CRoute4Me::init()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

void CRoute4Me::cleanup()
{
    curl_global_cleanup();
}

// make full URL from api entry point and parameters
static std::string make_arg(CURL *curl, const char *url, Json::Value& props)
{
    std::string ret(url);
    bool first = true;
    if(props.isObject())
    {
        Json::Value::Members keys(props.getMemberNames());
        for(Json::Value::Members::iterator it = keys.begin(); it != keys.end(); it++)
        {
            char *tmp = 0;
            const std::string &name = *it;
            std::string val;
            Json::Value v = props[name];
            switch(v.type())
            {
            case Json::intValue:
                val = Json::valueToString(v.asInt());
                break;
            case Json::uintValue:
                val = Json::valueToString(v.asUInt());
                break;
            case Json::realValue:
                val = Json::valueToString(v.asDouble());
                break;
            case Json::stringValue:
                tmp = curl_easy_escape(curl, v.asCString(), 0);
                if(tmp)
                {
                    val = tmp;
                    curl_free(tmp);
                }
                else
                    val = "";
                break;
            case Json::booleanValue:
                val = v.asBool() ? "1" : "0";
                break;
            default:
                val = "";
            }
            if(val.length() > 0)
            {
                ret += first ? "?" : "&";
                ret += name + "=" + val;
                first = false;
            }
        }
    }
    return ret;
}

// callback for libcurl to read response
static size_t read_http_resp(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct CRoute4Me::http_resp *mem = (struct CRoute4Me::http_resp *)userp;
    char* upd_memory = (char*) std::realloc(mem->memory, mem->size + realsize + 1);
    if(upd_memory == NULL)
        return 0;
    else
        mem->memory = upd_memory;
    std::memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

bool CRoute4Me::request(CRoute4Me::ReqType method, const char *serviceURL, Json::Value& props, Json::Value& content,
                        const char* altUrl)
{
    long http_code = 0;
    std::string payload;
    struct CRoute4Me::http_resp chunk; // prepare buffer for lubcurl http response
    chunk.memory = (char*) malloc(1);
    chunk.size = 0;
    std::string url;
    if (altUrl)
    {
        url = std::string(altUrl);
    }
    else
    {
        url = std::string(MAIN_HOST) + std::string(serviceURL);
    }
    std::string req = make_arg(m_curl, url.c_str(), props); // prepare url with parameters
    curl_easy_reset(m_curl);
    curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_setopt(m_curl, CURLOPT_URL, req.c_str());
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, read_http_resp);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    //curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
    if (m_verbose)
        curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);
    if(!content.isNull())
        payload = Json::FastWriter().write(content);
    switch(method)
    {
        //case REQ_GET:
        //    break;
        case REQ_DELETE:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "DELETE");
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, payload.c_str());
            break;
        case REQ_PUT:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, payload.c_str());
            break;
        case REQ_POST:

            curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, payload.c_str());
            if (formpost) {
                struct curl_slist *headerlist=NULL;
                static const char buf[] = "Content-Type: multipart/form-data;";
                headerlist = curl_slist_append(headerlist, buf);
                curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, headerlist);
                curl_easy_setopt(m_curl, CURLOPT_HTTPPOST, formpost);                
            }
            break;
    }
    CURLcode res = curl_easy_perform(m_curl);
    if(res != CURLE_OK)
    {
        free(chunk.memory);
        m_err_code = ERR_CURL_RESP;
        m_err_msg = std::string(curl_easy_strerror(res));
        return false;
    }
    if(method == REQ_PUT)
    {
		// if server responds with HTTP 303, we should use GET and CURLOPT_FOLLOWLOCATION does not help
        char *redirect_url = 0;
        if(curl_easy_getinfo(m_curl, CURLINFO_REDIRECT_URL, &redirect_url) == CURLE_OK && redirect_url)
        {
            free(chunk.memory);
            chunk.memory = (char*) malloc(1);
            chunk.size = 0;
            curl_easy_setopt(m_curl, CURLOPT_URL, redirect_url);
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, NULL);
            CURLcode res = curl_easy_perform(m_curl);
            if(res != CURLE_OK)
            {
                free(chunk.memory);
                m_err_code = ERR_CURL_RESP;
                m_err_msg = std::string(curl_easy_strerror(res));
                return false;
            }
        }
    }
    if(chunk.size == 0)
    {
        free(chunk.memory);
        m_err_code = ERR_CURL_EMPTY;
        m_err_msg = "empty http response";
        return false;
    }
    m_raw_resp = std::string(chunk.memory, chunk.size);
    free(chunk.memory);
    Json::Reader reader;
    if(!reader.parse(m_raw_resp, m_json_resp, false))
    {
        m_json_resp = Json::Value(Json::nullValue);
        m_err_code = ERR_JSON;
        m_err_msg = "json parse error(s):\n" + reader.getFormatedErrorMessages();
		return false;
    }
    if(m_json_resp.isObject() && m_json_resp.isMember("errors"))
    {
        m_err_code = ERR_API;
        m_err_msg = "route4me api errors:\n" + Json::StyledWriter().write(m_json_resp["errors"]);
		return false;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// Validation of parameters and general state

bool CRoute4Me::validate(const Json::Value& v, const CRoute4Me::key2tp *p, int n, const char **required, int rn)
{
    m_err_code = 0;
    if(!m_curl)
    {
        m_err_code = ERR_CURL;
        m_err_msg = std::string("cannot init curl lib");
        return false;
    }
    if(!v.isObject())
    {
        m_err_code = ERR_SYNTAX;
        m_err_msg = std::string("expect valid json object");
        return false;
    }
    if(p && n)
    {
        for(int i = 0; i < n; i++)
        {
            if(v.isMember(p[i].key) && !v[p[i].key].isConvertibleTo(p[i].tp))
            {
                m_err_code = ERR_PARAM_TP;
                m_err_msg = std::string("wrong type of param: ") + p[i].key;
                return false;
            }
        }
    }
    if(required && rn)
    {
        for(int i = 0; i < rn; i++)
        {
            if(!v.isMember(required[i]))
            {
                m_err_code = ERR_PARAM;
                m_err_msg = std::string("expect param: ") + required[i];
                return false;
            }
        }
    }
    return true;
}

int check_required(const Json::Value& v, const char *params[], int n)
{
    for(int i = 0; i < n; i++) if(!v.isMember(params[i])) return i+1;
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// Addresses

CAddressArray::CAddressArray() :
    m_list(Json::arrayValue)
{}

CAddressArray::CAddressArray(const Json::Value& addr_list) :
    m_list(addr_list)
{
    if(!m_list.isArray())
        m_list = Json::Value(Json::arrayValue);
}

bool CAddressArray::add_address(const Json::Value& value)
{
    static const char *required[] = {"address", "lat", "lng"};
    bool valid = value.isObject() && !check_required(value, required, sizeof(required)/sizeof(const char*));
    if(valid) m_list.append(value);
    return valid;
}

int CRoute4Me::get_address(const char* route_id, const char* dest_id)
{
    static const char *m[] = {"api_key", "route_id", "route_destination_id"};
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_destination_id"] = dest_id;
    if(!validate(props, CRoute4Me::get_route_address_req, sizeof(CRoute4Me::get_route_address_req)/sizeof(CRoute4Me::key2tp),
                 m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
    return m_err_code;
}

int CRoute4Me::mark_address_departed(const char *route_id, const char *address_id, bool departed, int member_id,
                                     Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["address_id"] = address_id;
    props["is_departed"] = departed;
    props["member_id"] = member_id;

    request(CRoute4Me::REQ_PUT, CRoute4Me::DEPARTED_SERVICE, props, body);
    return m_err_code;
}

int CRoute4Me::mark_address_visited(const char *route_id, const char *address_id, bool visited, int member_id,
                                    Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["address_id"] = address_id;
    props["is_visited"] = visited;
    props["member_id"] = member_id;

    request(CRoute4Me::REQ_PUT, CRoute4Me::ADDRESS_VISITED_SERVICE, props, body);
    return m_err_code;
}

int CRoute4Me::mark_address_detected(const char *route_id, const char *route_destination_id,
                                     Json::Value& body)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["route_id"] = route_id;
    props["route_destination_id"] = route_destination_id;

    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_ADDRESS_HOST, props, body);
    return m_err_code;
}

int CRoute4Me::get_hybrid_route(const char *target_date_string, int tz_offset)
{
    Json::Value props(Json::objectValue);
    props["api_key"] = m_key;
    props["target_date_string"] = target_date_string;
    props["timezone_offset_minutes"] = tz_offset;

    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::HYBRID_SERVICE, props, null);
    return m_err_code;
}

///////////////////////////////////////////////////////////////////////////////
