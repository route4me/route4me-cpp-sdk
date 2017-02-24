
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
