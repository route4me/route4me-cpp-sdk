
ENABLE_TESTING()

ADD_EXECUTABLE(ActivitiesTest ActivitiesTest)
TARGET_LINK_LIBRARIES(ActivitiesTest route4me)
TARGET_LINK_LIBRARIES(ActivitiesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(ActivitiesTest ActivitiesTest)

ADD_EXECUTABLE(TrackingTest TrackingTest)
TARGET_LINK_LIBRARIES(TrackingTest route4me)
TARGET_LINK_LIBRARIES(TrackingTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(TrackingTest TrackingTest)

ADD_EXECUTABLE(AvoidanceZonesTest AvoidanceZonesTest)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest route4me)
TARGET_LINK_LIBRARIES(AvoidanceZonesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(AvoidanceZonesTest AvoidanceZonesTest)

ADD_EXECUTABLE(AddressBookTest AddressBookTest)
TARGET_LINK_LIBRARIES(AddressBookTest route4me)
TARGET_LINK_LIBRARIES(AddressBookTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(AddressBookTest AddressBookTest)

ADD_EXECUTABLE(StreetsTest StreetsTest)
TARGET_LINK_LIBRARIES(StreetsTest route4me)
TARGET_LINK_LIBRARIES(StreetsTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(StreetsTest StreetsTest)

ADD_EXECUTABLE(RoutesTest RoutesTest)
TARGET_LINK_LIBRARIES(RoutesTest route4me)
TARGET_LINK_LIBRARIES(RoutesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(RoutesTest RoutesTest)

ADD_EXECUTABLE(NotesTest NotesTest)
TARGET_LINK_LIBRARIES(NotesTest route4me)
TARGET_LINK_LIBRARIES(NotesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(NotesTest NotesTest)

ADD_EXECUTABLE(ConfigTest ConfigTest)
TARGET_LINK_LIBRARIES(ConfigTest route4me)
TARGET_LINK_LIBRARIES(ConfigTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(ConfigTest ConfigTest)

ADD_EXECUTABLE(TerritoriesTest TerritoriesTest)
TARGET_LINK_LIBRARIES(TerritoriesTest route4me)
TARGET_LINK_LIBRARIES(TerritoriesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(TerritoriesTest TerritoriesTest)

ADD_EXECUTABLE(OrdersTest OrdersTest)
TARGET_LINK_LIBRARIES(OrdersTest route4me)
TARGET_LINK_LIBRARIES(OrdersTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(OrdersTest OrdersTest)

ADD_EXECUTABLE(GeocoderTest GeocoderTest)
TARGET_LINK_LIBRARIES(GeocoderTest route4me)
TARGET_LINK_LIBRARIES(GeocoderTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(GeocoderTest GeocoderTest)

ADD_EXECUTABLE(UsersTest UsersTest)
TARGET_LINK_LIBRARIES(UsersTest route4me)
TARGET_LINK_LIBRARIES(UsersTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(UsersTest UsersTest)

ADD_EXECUTABLE(OptimizationTest OptimizationTest)
TARGET_LINK_LIBRARIES(OptimizationTest route4me)
TARGET_LINK_LIBRARIES(OptimizationTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(OptimizationTest OptimizationTest)

ADD_EXECUTABLE(SessionTest SessionTest)
TARGET_LINK_LIBRARIES(SessionTest route4me)
TARGET_LINK_LIBRARIES(SessionTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(SessionTest SessionTest)
