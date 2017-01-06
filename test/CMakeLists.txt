ADD_EXECUTABLE(RouteManifest RouteManifest.cpp)
TARGET_LINK_LIBRARIES(RouteManifest route4me)

ADD_EXECUTABLE(GetRoute GetRoute.cpp)
TARGET_LINK_LIBRARIES(GetRoute route4me)

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

ADD_EXECUTABLE(OptimizeAndReoptimize OptimizeAndReoptimize.cpp)
TARGET_LINK_LIBRARIES(OptimizeAndReoptimize route4me)

ADD_EXECUTABLE(AddOrder AddOrder.cpp)
TARGET_LINK_LIBRARIES(AddOrder route4me)

ADD_EXECUTABLE(DuplicateRoute DuplicateRoute.cpp)
TARGET_LINK_LIBRARIES(DuplicateRoute route4me)


