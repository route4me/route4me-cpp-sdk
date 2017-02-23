ADD_EXECUTABLE(RouteManifest RouteManifest.cpp)
TARGET_LINK_LIBRARIES(RouteManifest route4me)

ADD_EXECUTABLE(GetRoute GetRoute.cpp)
TARGET_LINK_LIBRARIES(GetRoute route4me)

ADD_EXECUTABLE(DuplicateRoute DuplicateRoute.cpp)
TARGET_LINK_LIBRARIES(DuplicateRoute route4me)

ADD_EXECUTABLE(GetRouteByPoints GetRouteByPoints.cpp)
TARGET_LINK_LIBRARIES(GetRouteByPoints route4me)

ADD_EXECUTABLE(GetRouteByDirections GetRouteByDirections.cpp)
TARGET_LINK_LIBRARIES(GetRouteByDirections route4me)

ADD_EXECUTABLE(GetRouteByText GetRouteByText.cpp)
TARGET_LINK_LIBRARIES(GetRouteByText route4me)

ADD_EXECUTABLE(UpdateRoute UpdateRoute.cpp)
TARGET_LINK_LIBRARIES(UpdateRoute route4me)

ADD_EXECUTABLE(RouteDestinations RouteDestinations.cpp)
TARGET_LINK_LIBRARIES(RouteDestinations route4me)

ADD_EXECUTABLE(AddressBook AddressBook.cpp)
TARGET_LINK_LIBRARIES(AddressBook route4me)

ADD_EXECUTABLE(Notes Notes.cpp)
TARGET_LINK_LIBRARIES(Notes route4me)

ADD_EXECUTABLE(Users Users.cpp)
TARGET_LINK_LIBRARIES(Users route4me)

ADD_EXECUTABLE(Orders Orders.cpp)
TARGET_LINK_LIBRARIES(Orders route4me)

ADD_EXECUTABLE(GetOrders GetOrdersByDate.cpp)
TARGET_LINK_LIBRARIES(GetOrders route4me)

ADD_EXECUTABLE(GetCustomOrders GetCustomOrders.cpp)
TARGET_LINK_LIBRARIES(GetCustomOrders route4me)

ADD_EXECUTABLE(GetOrdersQuery GetOrdersQuery.cpp)
TARGET_LINK_LIBRARIES(GetOrdersQuery route4me)

ADD_EXECUTABLE(AddOrder AddOrder.cpp)
TARGET_LINK_LIBRARIES(AddOrder route4me)

ADD_EXECUTABLE(TeamActivities TeamActivities.cpp)
TARGET_LINK_LIBRARIES(TeamActivities route4me)

ADD_EXECUTABLE(LogActivities LogActivities.cpp)
TARGET_LINK_LIBRARIES(LogActivities route4me)

ADD_EXECUTABLE(Activities Activities.cpp)
TARGET_LINK_LIBRARIES(Activities route4me)

ADD_EXECUTABLE(Zones AvoidanceZones.cpp)
TARGET_LINK_LIBRARIES(Zones route4me)

ADD_EXECUTABLE(Territory Territory.cpp)
TARGET_LINK_LIBRARIES(Territory route4me)

ADD_EXECUTABLE(GetAllRoutes GetMultipleRoutes.cpp)
TARGET_LINK_LIBRARIES(GetAllRoutes route4me)

ADD_EXECUTABLE(RouteStatus RouteStatus.cpp)
TARGET_LINK_LIBRARIES(RouteStatus route4me)

ADD_EXECUTABLE(DeleteRoute DeleteRoute.cpp)
TARGET_LINK_LIBRARIES(DeleteRoute route4me)

ADD_EXECUTABLE(SetGPSPosition SetGPSPosition.cpp)
TARGET_LINK_LIBRARIES(SetGPSPosition route4me)

ADD_EXECUTABLE(TrackDeviceLastLocationHistory TrackDeviceLastLocationHistory.cpp)
TARGET_LINK_LIBRARIES(TrackDeviceLastLocationHistory route4me)

ADD_EXECUTABLE(SingleDriverRoundTrip SingleDriverRoundTrip.cpp)
TARGET_LINK_LIBRARIES(SingleDriverRoundTrip route4me)

ADD_EXECUTABLE(SingleDriverRoute10Stops SingleDriverRoute10Stops.cpp)
TARGET_LINK_LIBRARIES(SingleDriverRoute10Stops route4me)

ADD_EXECUTABLE(MultipleDepotMultipleDriver MultipleDepotMultipleDriver.cpp)
TARGET_LINK_LIBRARIES(MultipleDepotMultipleDriver route4me)

ADD_EXECUTABLE(MultipleDepotMultipleDriverTimeWindows MultipleDepotMultipleDriverTimeWindows.cpp)
TARGET_LINK_LIBRARIES(MultipleDepotMultipleDriverTimeWindows route4me)

ADD_EXECUTABLE(ReOptimization ReOptimization.cpp)
TARGET_LINK_LIBRARIES(ReOptimization route4me)

ADD_EXECUTABLE(GetOptimization GetOptimization.cpp)
TARGET_LINK_LIBRARIES(GetOptimization route4me)

ADD_EXECUTABLE(GetOptimizations GetOptimizations.cpp)
TARGET_LINK_LIBRARIES(GetOptimizations route4me)

ADD_EXECUTABLE(RemoveOptimization RemoveOptimization.cpp)
TARGET_LINK_LIBRARIES(RemoveOptimization route4me)

ADD_EXECUTABLE(OptimizeAndReoptimize OptimizeAndReoptimize.cpp)
TARGET_LINK_LIBRARIES(OptimizeAndReoptimize route4me)

ADD_EXECUTABLE(Login Login.cpp)
TARGET_LINK_LIBRARIES(Login route4me)

ADD_EXECUTABLE(Register Register.cpp)
TARGET_LINK_LIBRARIES(Register route4me)

ADD_EXECUTABLE(EditMember EditMember.cpp)
TARGET_LINK_LIBRARIES(EditMember route4me)

ADD_EXECUTABLE(DeleteMember DeleteMember.cpp)
TARGET_LINK_LIBRARIES(DeleteMember route4me)

ADD_EXECUTABLE(ActivitiesByType ActivitiesByType.cpp)
TARGET_LINK_LIBRARIES(ActivitiesByType route4me)

ADD_EXECUTABLE(AssetTracking AssetTracking.cpp)
TARGET_LINK_LIBRARIES(AssetTracking route4me)

ADD_EXECUTABLE(GetLocationHistory GetLocationHistory.cpp)
TARGET_LINK_LIBRARIES(GetLocationHistory route4me)

ADD_EXECUTABLE(AddAddressToOptimization AddAddressToOptimization.cpp)
TARGET_LINK_LIBRARIES(AddAddressToOptimization route4me)

ADD_EXECUTABLE(MergeRoutes MergeRoutes.cpp)
TARGET_LINK_LIBRARIES(MergeRoutes route4me)

ADD_EXECUTABLE(ShareRoutes ShareRoutes.cpp)
TARGET_LINK_LIBRARIES(ShareRoutes route4me)

ADD_EXECUTABLE(BatchGeocoding BatchGeocoding.cpp)
TARGET_LINK_LIBRARIES(BatchGeocoding route4me)

ADD_EXECUTABLE(ReverseGeocoding ReverseGeocoding.cpp)
TARGET_LINK_LIBRARIES(ReverseGeocoding route4me)

ADD_EXECUTABLE(GetSingleStreet GetSingleStreet.cpp)
TARGET_LINK_LIBRARIES(GetSingleStreet route4me)

ADD_EXECUTABLE(GetAllStreets GetAllStreets.cpp)
TARGET_LINK_LIBRARIES(GetAllStreets route4me)

ADD_EXECUTABLE(GetStreetsLimited GetStreetsLimited.cpp)
TARGET_LINK_LIBRARIES(GetStreetsLimited route4me)

ADD_EXECUTABLE(GetStreetsZipHouse GetStreetsZipHouse.cpp)
TARGET_LINK_LIBRARIES(GetStreetsZipHouse route4me)

ADD_EXECUTABLE(PurchaseLicense PurchaseLicense.cpp)
TARGET_LINK_LIBRARIES(PurchaseLicense route4me)

ADD_EXECUTABLE(GetSubUsers GetSubUsers.cpp)
TARGET_LINK_LIBRARIES(GetSubUsers route4me)

ADD_EXECUTABLE(ValidateSession ValidateSession.cpp)
TARGET_LINK_LIBRARIES(ValidateSession route4me)

ADD_EXECUTABLE(AddConfig AddConfig.cpp)
TARGET_LINK_LIBRARIES(AddConfig route4me)

ADD_EXECUTABLE(GetConfig GetConfig.cpp)
TARGET_LINK_LIBRARIES(GetConfig route4me)

ADD_EXECUTABLE(GetVehicles GetVehicles.cpp)
TARGET_LINK_LIBRARIES(GetVehicles route4me)

ADD_EXECUTABLE(PreviewFile PreviewFile.cpp)
TARGET_LINK_LIBRARIES(PreviewFile route4me)

ADD_EXECUTABLE(UploadFile UploadFile.cpp)
TARGET_LINK_LIBRARIES(UploadFile route4me)

ENABLE_TESTING()

ADD_TEST(DuplicateRoute DuplicateRoute)
ADD_TEST(GetRouteByPoints GetRouteByPoints)
ADD_TEST(GetRouteByDirections GetRouteByDirections)
ADD_TEST(GetRouteByText GetRouteByText)
ADD_TEST(UpdateRoute UpdateRoute)
ADD_TEST(AddressBook AddressBook)
ADD_TEST(Notes Notes)
ADD_TEST(Users Users)
ADD_TEST(Orders Orders)
ADD_TEST(TeamActivities TeamActivities)
ADD_TEST(Zones Zones)
ADD_TEST(Territory Territory)
ADD_TEST(GetAllRoutes GetAllRoutes)
ADD_TEST(RouteStatus RouteStatus)
ADD_TEST(SingleDriverRoundTrip SingleDriverRoundTrip)
ADD_TEST(ActivitiesByType ActivitiesByType)
ADD_TEST(AssetTracking AssetTracking)
ADD_TEST(GetLocationHistory GetLocationHistory)
ADD_TEST(GetOptimization GetOptimization)
ADD_TEST(BatchGeocoding BatchGeocoding)
ADD_TEST(GetConfig GetConfig)
