# using static library of zero mq
add_compile_definitions(ZMQ_STATIC ZMQPP_STATIC_DEFINE) ## or #define ZMQ_STATIC beofre include zmq.hpp

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions(IS_DEBUG)
endif()
# watcher
add_executable(watcher 
"main.cpp" 
"define.hpp" 
"watcher_manager.hpp" 
"watcher_manager.cpp" 
"logger/logger_define.hpp" 
"logger/logger.hpp" 
"logger/logger.cpp"
"peripherals/usb_manager.hpp" 
"peripherals/usb_manager.cpp")
target_include_directories(watcher PRIVATE ${SGLIB_INCLUDEDIR};${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(watcher PRIVATE ${WINDOWS_LIBRARIES} ${SGLIB_LIBRARIES})