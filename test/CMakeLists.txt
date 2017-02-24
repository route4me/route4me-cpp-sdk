
ENABLE_TESTING()
ADD_EXECUTABLE(ActivitiesTest ActivitiesTest)
TARGET_LINK_LIBRARIES(ActivitiesTest route4me)
TARGET_LINK_LIBRARIES(ActivitiesTest ${GTEST_LIBRARIES} pthread)
ADD_TEST(ActivitiesTest ActivitiesTest)

