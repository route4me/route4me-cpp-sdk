
ENABLE_TESTING()

ADD_EXECUTABLE(ActivitiesTest ActivitiesTest.cpp)
TARGET_LINK_LIBRARIES(ActivitiesTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(ActivitiesTest ActivitiesTest)

ADD_EXECUTABLE(TrackingTest TrackingTest.cpp)
TARGET_LINK_LIBRARIES(TrackingTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(TrackingTest TrackingTest)

ADD_EXECUTABLE(AvoidanceZonesTest AvoidanceZonesTest.cpp)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(AvoidanceZonesTest AvoidanceZonesTest)

ADD_EXECUTABLE(AddressBookTest AddressBookTest.cpp)
TARGET_LINK_LIBRARIES(AddressBookTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(AddressBookTest AddressBookTest)

ADD_EXECUTABLE(StreetsTest StreetsTest.cpp)
TARGET_LINK_LIBRARIES(StreetsTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(StreetsTest StreetsTest)

ADD_EXECUTABLE(RoutesTest RoutesTest.cpp)
TARGET_LINK_LIBRARIES(RoutesTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(RoutesTest RoutesTest)

ADD_EXECUTABLE(NotesTest NotesTest.cpp)
TARGET_LINK_LIBRARIES(NotesTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(NotesTest NotesTest)

ADD_EXECUTABLE(ConfigTest ConfigTest.cpp)
TARGET_LINK_LIBRARIES(ConfigTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(ConfigTest ConfigTest)

ADD_EXECUTABLE(TerritoriesTest TerritoriesTest.cpp)
TARGET_LINK_LIBRARIES(TerritoriesTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(TerritoriesTest TerritoriesTest)

ADD_EXECUTABLE(OrdersTest OrdersTest.cpp)
TARGET_LINK_LIBRARIES(OrdersTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(OrdersTest OrdersTest)

ADD_EXECUTABLE(GeocoderTest GeocoderTest.cpp)
TARGET_LINK_LIBRARIES(GeocoderTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(GeocoderTest GeocoderTest)

ADD_EXECUTABLE(UsersTest UsersTest.cpp)
TARGET_LINK_LIBRARIES(UsersTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(UsersTest UsersTest)

ADD_EXECUTABLE(OptimizationTest OptimizationTest.cpp)
TARGET_LINK_LIBRARIES(OptimizationTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(OptimizationTest OptimizationTest)

ADD_EXECUTABLE(SessionTest SessionTest.cpp)
TARGET_LINK_LIBRARIES(SessionTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(SessionTest SessionTest)

ADD_EXECUTABLE(GPSTest GPSTest.cpp)
TARGET_LINK_LIBRARIES(GPSTest route4me ${GTEST_LIBRARIES} pthread)
ADD_TEST(GPSTest GPSTest)

# No neeed to run valgrind tests for each build. Line below added for example.
# ADD_TEST(GPSTest_valgrind valgrind --read-var-info=yes --leak-check=full --show-leak-kinds=all ./GPSTest)
