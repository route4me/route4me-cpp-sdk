SET(CPPROUTE4ME_SOURCE
  route4me.cpp
  jsoncpp/json_reader.cpp
  jsoncpp/json_value.cpp
  jsoncpp/json_writer.cpp
)

ADD_LIBRARY(route4me STATIC ${CPPROUTE4ME_SOURCE})
TARGET_LINK_LIBRARIES(route4me ${CURL_LIBRARY})
