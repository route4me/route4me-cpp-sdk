/**
 *
 * Rout4me API C++ client
 *
 */

#include <cstdlib>
#include <cstring>
#include <curl/curl.h>
#include "../include/route4me.h"

///////////////////////////////////////////////////////////////////////////////
// Constants

const char *CRoute4Me::R4_API_HOST = "http://www.route4me.com/api.v4/optimization_problem.php";
const char *CRoute4Me::R4_SHOW_ROUTE_HOST = "https://www.route4me.com/route4me.php";
const char *CRoute4Me::R4_ROUTE_HOST = "https://www.route4me.com/api.v4/route.php";
const char *CRoute4Me::R4_SET_GPS_HOST = "https://www.route4me.com/track/set.php";

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

///////////////////////////////////////////////////////////////////////////////
// Construction

CRoute4Me::CRoute4Me(const char *key) :
    m_key(key), m_err_code(0), m_curl(0)
{
    m_curl = curl_easy_init();
}

CRoute4Me::~CRoute4Me()
{
    if(m_curl) curl_easy_cleanup(m_curl);
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
    if(!validate(props, CRoute4Me::get_route_q_req, sizeof(CRoute4Me::get_route_q_req)/sizeof(CRoute4Me::key2tp), m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_ROUTE_HOST, props, null);
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

int CRoute4Me::set_gps(Json::Value& props)
{
    static const char *m[] = {"format", "member_id", "route_id", "course", "speed", "lat", "lng", "device_type", "device_guid"};
    props["api_key"] = m_key;
    if(!validate(props, CRoute4Me::set_gps_req, sizeof(CRoute4Me::set_gps_req)/sizeof(CRoute4Me::key2tp), m, sizeof(m)/sizeof(const char*)))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_GET, CRoute4Me::R4_SET_GPS_HOST, props, null);
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

int CRoute4Me::reoptimize(const char *opt_id)
{
    Json::Value props;
    props["api_key"] = m_key;
    props["optimization_problem_id"] = opt_id;
    props["reoptimize"] = 1;
    if(!validate(props))
        return m_err_code;
    Json::Value null;
    request(CRoute4Me::REQ_PUT, CRoute4Me::R4_API_HOST, props, null);
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
    mem->memory = (char*) std::realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) return 0;
    std::memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

bool CRoute4Me::request(CRoute4Me::ReqType method, const char *url, Json::Value& props, Json::Value& content)
{
    long http_code = 0;
    std::string payload;
    struct CRoute4Me::http_resp chunk; // prepare buffer for lubcurl http response
    chunk.memory = (char*) malloc(1);
    chunk.size = 0;
    std::string req = make_arg(m_curl, url, props); // prepare url with parameters
    curl_easy_reset(m_curl);
    curl_easy_getinfo(m_curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_setopt(m_curl, CURLOPT_URL, req.c_str());
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, read_http_resp);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(m_curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    //curl_easy_setopt(m_curl, CURLOPT_FOLLOWLOCATION, 1L);
    //curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);
    if(!content.isNull())
        payload = Json::FastWriter().write(content);
    switch(method)
    {
        //case REQ_GET:
        //    break;
        case REQ_DELETE:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "DELETE");
            break;
        case REQ_PUT:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PUT");
            break;
        case REQ_POST:
            curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, payload.c_str());
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

///////////////////////////////////////////////////////////////////////////////
