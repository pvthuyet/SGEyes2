# using static library of zero mq
add_compile_definitions(ZMQ_STATIC ZMQPP_STATIC_DEFINE) ## or #define ZMQ_STATIC beofre include zmq.hpp

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions(IS_DEBUG)
endif()
# watcher
add_executable(controller
	"main.cpp" 
	"request_manager.hpp" 
	"request_manager.cpp" 
	"server.hpp" 
	"server.cpp"
	)
target_include_directories(controller PRIVATE ${SGLIB_INCLUDEDIR};${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(controller PRIVATE ${WINDOWS_LIBRARIES} ${SGLIB_LIBRARIES})