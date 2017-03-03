/**
 *
 * Rout4me API C++ client
 *
 */

#ifndef __cpproute4me_route4me__
#define __cpproute4me_route4me__

#include <string>
//#include <json/json.h>
#include "json/json.h"

class CAddressArray;

struct Member
{
    std::string email;
    std::string password1;
    std::string password2;
    std::string session_guid;
    std::string format;
    std::string plan;
    std::string member_type;
    std::string industry;
    std::string first_name;
    std::string last_name;
    int check_terms;
    std::string device_type;
};

struct MapPoint
{
    double lat;
    double lng;
};

struct AddressData
{
    std::string zipCode;
    std::string houseNumber;
};

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
    struct curl_httppost *formpost;
    bool m_verbose;

public:
    /** \brief Constructs a wrapper by Key
    * \param key A key to use on connect to API ('api_key' field)
    */
    CRoute4Me(const char *key, bool verbose = false);

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

    /** \brief Gets a status update on all
    * optimization problems for a specific API key.
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
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

    /** \brief Gets routes by path points
    * \param route id
    * \param route_path_output
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_path_points(const char* route_id, const char* route_path_output);

    /** \brief Gets routes by directions
    * \param route id
    * \param directions - 1 or 0
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_directions(const char* route_id, int directions);

    /** \brief Gets routes by query
    * \param route id
    * \param query - text pattern
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_query(const char* route_id, const char* query);

    /** \brief Add address to specific route
    * \param route id
    * \param address as JSON object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_route_destinations(const char*, Json::Value&);

    /** \brief Remove address from system
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_address_from_route(const char* route_id, const char* destination_id);

    /** \brief Update route with JSON data
    * \param route id
    * \param destination id
    * \param JSON object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int update_route(const char* route_id, const char* dest_id, const Json::Value& fields);

    /** \brief Update route with JSON data
    * \param route id
    * \param JSON object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int update_route(const char *route_id, const Json::Value& value);

    /** \brief Clone the route
    * \param route id
    * \param to - redirect to page or return JSON for "none"
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int duplicate_route(const char* route_id, const char* to = "none");

    /** \brief Delete a Route by ID.
    * \param route_id route ID
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int delete_route(const char *route_id);

    /** \brief Merge routes
    * \param route_ids - comma separated list of routes
    * \param depot_address
    * \param point - lattitide and longtitude of depot
    * \param remove_origin
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int merge_routes(const char* route_ids, const char* depot_address, MapPoint point, bool remove_origin = false);

    /** \brief Share route
    * \param route_id route ID
    * \param email - send route data there
    * \param format
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int share_routes(const char* route_id, const char* email, const char* format = "json");

    /** \brief Returns route destination details.
    * \param route_id
    * \param destination id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_address(const char* route_id, const char* destination_id);

    /** \brief Add route notes
    * \param route_id
    * \param destination id
    * \param text notes
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_route_notes(const char* route_id, const char* destination_id, const char* notes);

    /** \brief Get route notes
    * \param route_id
    * \param destination id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_route_notes(const char* route_id, const char* destination_id);

    /** \brief Set GPS point.
    * \param props api call parameters
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int set_gps(Json::Value& props);

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

    /** \brief Returns optimization problem.
    * \param optimization problem id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_optimization(const char* optimization_problem_id);

    /** \brief Returns optimization problem.
    * \param states list of addresses for the optimization problem
    * \param offset
    * \param limit
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_optimizations(const char* states, int offset, int limit);

    /** \brief Removes optimization problem.
    * \param fields
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_optimization(const Json::Value& fields);

    /** \brief Removes address from optimization problem.
    * \param address - id of the address
    * \param opt_id - id of the problem
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_address_from_optimization(const char* address, const char* opt_id);

    /** \brief Adds address to optimization problem.
     * * \param opt_id - id of the problem
    * \param body - address data in JSON format
    * \param reoptimize
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_address_to_optimization(Json::Value body, const char* opt_id, bool reoptimize = false);

    /** \brief Add contacts to address book
    * \param props - contact data as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_address_book_contacts(Json::Value& props);

    /** \brief Get contacts from address book
    * \param text - search pattern
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_address_book_contacts_by_text(const char*);

    /** \brief get all contacts from address book
    * \param props - contact data as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_address_book_contacts(const char* text);

    /** \brief get all contacts from address book
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_address_book_contacts();

    /** \brief update contacts in address book
    * \param text - search pattern
    * \param props - new contact data as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int update_address_book_contacts(const char* text, Json::Value& props);

    /** \brief Remove contacts from address book
    * \param text - search pattern
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_address_book_contacts(const char* text);

    /** \brief add avoidance zone
    * \param territory_id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_avoidance_zone(const char* territory_id, Json::Value&);

    /** \brief get all avoidance zones
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_avoidance_zones();

    /** \brief get avoidance zone
    * \param territory_id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_avoidance_zone(const char* territory_id);

    /** \brief update avoidance zone
    * \param territory_id
    * \param new data as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int update_avoidance_zone(const char* territory_id, Json::Value&);

    /** \brief remove avoidance zone
    * \param territory_id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_avoidance_zone(const char* territory_id);

    /** \brief create a territory
    * \param data as JSON object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_territory(Json::Value& data);

    /** \brief get a territory
    * \param territory_id
    * \param int addresses - if 1 then addresses will be included in response
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_territory(const char* territory_id);

    /** \brief get all territories
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_all_territories();

    /** \brief remove a territory
    * \param territory_id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_territory(const char* territory_id);

    /** \brief add order
    * \param new data as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_order(Json::Value&);

    /** \brief add order to route
    * \param route_id
    * \param new data as json object
    * \param redirect
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int add_order_to_route(const char* route_id, Json::Value&, int redirect = 0);

    /** \brief get order by id
    * \param order_id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_order(const char* order_id);

    /** \brief get all orders
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_all_orders();

    /** \brief remove order
    * \param redirect
    * \param request body as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int remove_order(int, Json::Value&);

    /** \brief update order
    * \param redirect
    * \param request body as json object
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int update_order(int, Json::Value&);

    /** \brief get orders inserted on specified date
    * \param redirect
    * \param day added - string in format YYMMDD
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_orders(int, const char*);

    /** \brief get orders scheduled for specified date
    * \param redirect
    * \param day scheduled - string in format YYMMDD
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_scheduled_orders(int, const char*);

    /** \brief get orders with specified custom fields
    * \param fields - comma separated list of fields
    * \param offset
    * \param limit
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_custom_orders(const char* fields, int offset, int limit);

    /** \brief get orders which contain specified text in any field
    * \param query - text to search for in fields
    * \param offset
    * \param limit
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_orders_query(const char* fields, int offset, int limit);

    /** \brief get all activities
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_all_activities();

    /** \brief get activities belonging to one team
    * \param route id
    * \param team
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_team_activities(const char* route_id, const char* team = "true");

    /** \brief log custom activity
    * \param route id
    * \param activity type
    * \param custom message
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int log_custom_activity(const char* route_id, const char* activity_type,
                            const char* activity_message);

    /**
     * @brief get_activities_by_type
     * /param type of activity
     * @return
     */
    int get_activities_by_type(const char* act_type);

    /** \brief get all users
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_users();

    /** \brief authentification of user
     * \param - structure with user credentials
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int authenticate_user(const Member* member);

    /** \brief CRUD operations for member record
     * \param - Json structure with data to be added, edited or deleted
     * \param - http method to apply for this data
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int modify_member(Json::Value& value, ReqType method);

    /** \brief Purchase user license
     * \param - Json structure with user data
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int purchase_user_license(Json::Value& body);

    /** \brief Purchase device license
     * \param - Json structure with device data
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int purchase_device_license(Json::Value& body);

    /**
     * \brief asset_tracking
     * \param id
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int asset_tracking(const char* id);

    /**
     * \brief get_device_location
     * \param route_id
     * \param start_date
     * \param end_date
     * \param period
     * \param format
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int get_device_location(const char* route_id, int start_date, int end_date,
                            const char* period, bool last_position = false, const char* format = "json");

    /**
     * \brief Batch geocoding
     * \param addresses
     * \param format
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int batch_geocoding(const char* addresses, const char* format);

    /**
     * \brief Reverse geocoding
     * \param addresses
     * \param format
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int reverse_geocoding(const char* addresses, const char* format);

    /**
     * \brief Get one street data
     * \param seqno = street sequential number in streets list
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int get_street_address(int seqno);

    /**
     * \brief Get one street data
     * \param address data - zip code and house number
     * \param limit - not used if set to -1
     * \param offset - not used if set to -1
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int get_street_address(const AddressData& data, int limit = -1, int offset = -1);

    /**
     * \brief Get one street data
     * \param offset - not applied if equals -1
     * \param limit - not applied if set to -1
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int get_all_streets(int limit = -1, int offset = -1);

    /**
     * \brief Get sub-users
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int get_subusers();

    /**
     * \brief Validate session
     * \param session id
     * \param member id
     * \param format
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int validate_session(const char* session_id, const char* member_id, const char* format = "json");

    /** \brief Get configuration data
     * \param key - get all configuration data if NULL
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_config(const char* key = NULL);

    /** \brief CRUD operations for configuration settings
     * \param - Json structure with data to be added, edited or deleted
     * \param - http method to apply for this data
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int modify_config(Json::Value& value, ReqType method);

    /** \brief Get vehicles
     * \param - offset
     * \param - limit
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int get_vehicles(int offset, int limit);

    /** \brief Preview file
     * \param - id
     * \param - format - "json" by default
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int preview_file(const char* id, const char* format = "json");

    /** \brief Upload file
     * \param - id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int upload_file(const char* file_name, const char* format = "json");

    /** \brief Upload geocoding
     * \param - id
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int upload_geocoding(const char* id);

    /** \brief Upload JSON geocoding
     * \param - body - JSON data
    * \return \c 0 if the response was successfully received, \c error code if an error occurred.
    */
    int json_geocoding(Json::Value& body);

    // TODO section:
    /**
     * \brief mark address as visited
     * \param route_id
     * \param address_id
     * \param visited
     * \param member
     * \return \c 0 if the response was successfully received, \c error code if an error occurred.
     */
    int mark_address_visited(const char* route_id, const char* address_id, bool visited, int member_id);

    int mark_address_departed(const char* route_id, const char* address_id, bool departed, int member_id);

protected:
    bool validate(const Json::Value& v, const CRoute4Me::key2tp *p = 0, int n = 0, const char **required = 0, int rn = 0);
    bool request(CRoute4Me::ReqType method, const char *serviceURL, Json::Value& props, Json::Value& content, const char* altURL = NULL);

public:
    static key2tp get_route_q_req[], set_gps_req[], get_route_address_req[],\
            get_address_notes_req[], get__multiple_routes_req[], update_route_req[], update_route_data_req[], \
            duplicate_route_req[], delete_route_req[], add_address_req[], add_address_notes_req[],\
            get_address_book_contact_req[];
    static const char *MAIN_HOST, *RAPID_HOST, *R4_API_HOST, *R4_SHOW_ROUTE_HOST, *R4_DUPLICATE_ROUTE_HOST, *R4_ROUTE_HOST, *R4_SET_GPS_HOST,
    *R4_ADDRESS_HOST, *R4_ADD_ROUTE_NOTES, *R4_ADDRESS_BOOK, *R4_AVOIDANCE_HOST, *R4_ORDER_HOST, *R4_ACTIVITIES, *R4_USERS,
    *R4_TERRITORY_HOST, *AUTHENTICATION_SERVICE, *REGISTRATION_SERVICE, *TRACKING_SERVICE, *LOCATION_SERVICE,
    *MERGE_SERVICE, *SHARE_SERVICE, *ADDRESS_VISITED_SERVICE, *GEOCODER, *STREET_SERVICE, *USER_LICENSE_SERVICE,
    *DEVICE_LICENSE_SERVICE, *USER_SERVICE, *VALIDATE_SESSION, *CONFIG_SERVICE, *VEHICLES_SERVICE,
    *PREVIEW_SERVICE, *UPLOAD_SERVICE, *UPLOAD_GEOCODING, *JSON_GEOCODING;
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
private:
    template <class T> void append_url(std::string& url, T arg) const;
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
