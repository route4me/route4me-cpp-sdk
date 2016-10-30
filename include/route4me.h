/**
 *
 * Rout4me API C++ client
 *
 */

#ifndef __cpproute4me_route4me__
#define __cpproute4me_route4me__

#include <string>
#include <json/json.h>

class CAddressArray;
class User;
class Activity;
class AddressBookContact;
class CArrayWrapper;
///////////////////////////////////////////////////////////////////////////////

/** \brief Rout4me API C++ wrapper
*
*/
class CRoute4Me
{
protected:
    void *m_curl;
    std::string m_key;
    std::string m_raw_resp;
    Json::Value m_json_resp;
    std::string m_err_msg;
    int m_err_code;

public:
    /** \brief Constructs a wrapper by Key
    * \param key A key to use on connect to API ('api_key' field)
    */
    CRoute4Me(const char *key);

    /** \brief Deconstructs a wrapper
    *
    */
    ~CRoute4Me();

    /** \brief Global init
    *
    */
    static void init();

    /** \brief Global cleanup
    *
    */
    static void cleanup();

    /** \brief Error code of the last request.
    * \return diagnostic error code
    */
    int get_err_code() { return m_err_code; }

    /** \brief Error message for the last error occurred in requests.
    * \return diagnostic error message
    */
    std::string get_err_msg() { return m_err_msg; }

    /** \brief Returns raw response on the last request.
    * \return raw response string
    */
    std::string get_raw_resp() { return m_raw_resp; }

    /** \brief Returns parsed response on the last request.
    * \return parsed as json response string
    */
    const Json::Value& get_json_resp() { return m_json_resp; }

public:
    ///////////////////
    // actual api calls

    /** \brief Gets a status update on all the pending (queued) 
    * optimization problems for a specific API key.
    * \param props api call parameters
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_q(Json::Value& props);
    int get_route_q();

    int get_multiple_routes();

    /** \brief Gets a Route by ID.
    * \param route_id route ID
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_by_id(const char *route_id);

    /** \brief Gets info about a Route.
    * \param props api call parameters
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route(Json::Value& props);

    int add_route_destinations(const char*, Json::Value&);
    int remove_route_destination();
    int move_destination_to_route();

    //int add_multiple_addresses_to_route(const char* route_id, ...);
    int remove_address_from_route(const char* route_id, const char* destination_id);
    int move_address_to_another_route(const char* from_route_id, const char* to_route_id);

    int update_route(const char* route_id, const char* dest_id, const Json::Value& fields
                     /*CArrayWrapper wrapper*/);
    int update_route(const char *route_id, const Json::Value& value);
    int duplicate_route(const char* route_id, const char* to = "none");
    /** \brief Delete a Route by ID.
    * \param route_id route ID
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int delete_route(const char *route_id);

    int get_address(const char*, const char*);
    int add_route_notes(const char*, const char*, const char*);

    int get_route_notes(const char*, const char*);

    /** \brief Set GPS point.
    * \param props api call parameters
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_last_location();
    int set_gps(Json::Value& props);

    int get_users();
    int get_activity_feed();
    int log_custom_activity();

    /** \brief Reoptimize the problem.
    * \param opt_id optimization problem ID
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int reoptimize(const char *opt_id);

    /** \brief Solve optimization problem.
    * \param addr list of addresses for the optimization problem
    * \param props api call parameters
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int run_optimization(const CAddressArray& addr, Json::Value& props);
    int get_optimization(const char*, int, int);
    int remove_optimization(const char*);
    int remove_address_from_optimization(const char*, const char*);

    int add_address_book_contacts(Json::Value& props);
    int get_address_book_contacts_by_text(const char*);
    int get_address_book_contacts(const char*);
    int get_address_book_contacts();
    int update_address_book_contacts(const char*, Json::Value& props);
    int remove_address_book_contacts(const char*);

    int add_avoidance_zone(const char*, Json::Value&);
    int get_avoidance_zones();
    int get_avoidance_zone(const char*);
    int update_avoidance_zone(const char*, Json::Value&);
    int remove_avoidance_zone(const char*);

    int add_order(Json::Value&);
    int add_order_to_route(const char*, Json::Value&, int);
    int get_order(const char*);
    int get_all_orders();
    int remove_order(int, Json::Value&);
    int update_order(int, Json::Value&);
public:
    enum ReqType
    {
        REQ_GET,
        REQ_DELETE,
        REQ_PUT,
        REQ_POST
    };
    struct key2tp
    {
        const char *key;
        Json::ValueType tp;
    };
    struct http_resp
    {
        char *memory;
        size_t size;
    };
protected:
    bool validate(const Json::Value& v, const CRoute4Me::key2tp *p = 0, int n = 0, const char **required = 0, int rn = 0);
    bool request(CRoute4Me::ReqType method, const char *url, Json::Value& props, Json::Value& content);

public:
    static key2tp get_route_q_req[], set_gps_req[], get_route_address_req[],\
            get_address_notes_req[], get__multiple_routes_req[], update_route_req[], update_route_data_req[], \
            duplicate_route_req[], delete_route_req[], add_address_req[], add_address_notes_req[],\
            get_address_book_contact_req[];
    static const char *R4_API_HOST, *R4_SHOW_ROUTE_HOST, *R4_DUPLICATE_ROUTE_HOST, *R4_ROUTE_HOST, *R4_SET_GPS_HOST,
    *R4_ADDRESS_HOST, *R4_ADD_ROUTE_NOTES, *R4_ADDRESS_BOOK, *R4_AVOIDANCE_HOST, *R4_ORDER_HOST;
    static const char *Driving, *Walking, *Trucking; // TravelMode
    static const char *MI, *KM; // DistanceUnit
    static const char *Highways, *Tolls, *MinimizeHighways, *MinimizeTolls, *None; // Avoid
    static const char *Distance, *Time, *TimeWithTraffic; // Optimize
    static const char *Web, *IPhone, *IPad, *AndroidPhone, *AndroidTablet; // DeviceType
    static const char *Csv, *Serialized, *Xml; // Format
    static const char *PathNone, *Points; // RoutePathOutput
	enum
	{
        ERR_HTTP = -1,
        ERR_PARAM = -2,
        ERR_SYNTAX = -3,
        ERR_PARAM_TP = -4,
        ERR_CURL = -5,
        ERR_CURL_RESP = -6,
        ERR_CURL_EMPTY = -7,
        ERR_JSON = -8,
        ERR_API = -9,

        OPTIMIZATION_STATE_INITIAL = 1,
        OPTIMIZATION_STATE_MATRIX_PROCESSING = 2,
        OPTIMIZATION_STATE_OPTIMIZING = 3,
        OPTIMIZATION_STATE_OPTIMIZED = 4,
        OPTIMIZATION_STATE_ERROR = 5,
        OPTIMIZATION_STATE_COMPUTING_DIRECTIONS = 6,

        ROUTE4ME_METRIC_EUCLIDEAN = 1,
        ROUTE4ME_METRIC_MANHATTAN = 2,
        ROUTE4ME_METRIC_GEODESIC = 3,
        ROUTE4ME_METRIC_MATRIX = 4,
        ROUTE4ME_METRIC_EXACT_2D = 5,

        TSP = 1,
        VRP = 2,
        CVRP_TW_SD = 3,
        CVRP_TW_MD = 4,
        TSP_TW = 5,
        TSP_TW_CR = 6,
        BBCVRP = 7
	};
};

class CArrayWrapper {
//private:
public:
    Json::Value m_list;
public:
    CArrayWrapper();
    CArrayWrapper(const Json::Value& list);
    void add_item(const Json::Value& value);
};

class CAddressBookContact {
    friend class CRoute4Me;

protected:
    Json::Value m_list;
public:
    CAddressBookContact();

    /** \brief Constructs a list of addresses by json array
    * \param addr_list An array of addresses
    */
    CAddressBookContact(const Json::Value& addr_list);

    /** \brief Append an address to the list by json object
    * \param value An json object that holds address fields
    * \return \c true if the address was successfully added, \c false if an error occurred.
    */
    bool add_contact(const Json::Value& value);
};

class User {

};

class Activity {

};

///////////////////////////////////////////////////////////////////////////////

/** \brief Rout4me address
*
*/
class CAddressArray
{
    friend class CRoute4Me;

protected:
    Json::Value m_list;
public:
    /** \brief Constructs an empty list of addresses
    *
    */
    CAddressArray();

    /** \brief Constructs a list of addresses by json array
    * \param addr_list An array of addresses
    */
    CAddressArray(const Json::Value& addr_list);

    /** \brief Append an address to the list by json object
    * \param value An json object that holds address fields
    * \return \c true if the address was successfully added, \c false if an error occurred.
    */
    bool add_address(const Json::Value& value);
};

#endif
