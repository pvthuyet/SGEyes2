cmake_minimum_required (VERSION 3.8 FATAL_ERROR)

project(SGyes2 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set name
set(GSL_NAME "GSL-3.1.0")
set(FMT_NAME "fmt-7.1.3")
set(LIBZMQ_NAME "libzmq-4.3.4")
SET(CPPZMQ_NAME "cppzmq-4.7.1")
SET(ZMQPP_NAME "zmqpp-develop")
SET(VLD_NAME "vld")
SET(DATE_NAME "date-3.0.1")
SET(SPDLOG_NAME "spdlog-1.8.5")
SET(NLOHMANN_NAME "nlohmann-3.9.1")

##### saigonlib ROOT
set(WINDOWS_LIBRARIES "Ws2_32.lib;IPHLPAPI.lib")
set(SGLIB_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../saigonlib")

## Boost library
set(BOOST_ROOT "${SGLIB_ROOT}/boost_1_74_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         ON)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
# Note boost 1.75.0 error
find_package(Boost 1.74.0 REQUIRED COMPONENTS date_time regex thread filesystem context coroutine)
if(NOT Boost_FOUND)
	message(FATAL_ERROR "Not found Boost version 1.74.0")
endif()

# Result
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
message(STATUS "Boost_VERSION: ${Boost_VERSION}")
message(STATUS "Boost_LIB_VERSION: ${Boost_LIB_VERSION}")
message(STATUS "Boost_MAJOR_VERSION: ${Boost_MAJOR_VERSION}")
message(STATUS "Boost_MINOR_VERSION: ${Boost_MINOR_VERSION}")
message(STATUS "Boost_SUBMINOR_VERSION: ${Boost_SUBMINOR_VERSION}")
message(STATUS "Boost_LIB_DIAGNOSTIC_DEFINITIONS: ${Boost_LIB_DIAGNOSTIC_DEFINITIONS}")

## set include
set(LIBZMQ_INCLUDEDIR "${SGLIB_ROOT}/${LIBZMQ_NAME}/include")
set(CPPZMQ_INCLUDEDIR "${SGLIB_ROOT}/${CPPZMQ_NAME}/include")
set(GSL_INCLUDEDIR "${SGLIB_ROOT}/${GSL_NAME}/include")
set(FMT_INCLUDEDIR "${SGLIB_ROOT}/${FMT_NAME}/include")
set(VLD_INCLUDEDIR "${SGLIB_ROOT}/${VLD_NAME}/include")
set(DATE_INCLUDEDIR "${SGLIB_ROOT}/${DATE_NAME}/include")
set(ZMQPP_INCLUDEDIR "${SGLIB_ROOT}/${ZMQPP_NAME}/include")
set(SPDLOG_INCLUDEDIR "${SGLIB_ROOT}/${SPDLOG_NAME}/include")
set(NLOHMANN_INCLUDEDIR "${SGLIB_ROOT}/${NLOHMANN_NAME}/include")

## set lib
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(LIBZMQ_DIR "${SGLIB_ROOT}/${LIBZMQ_NAME}/lib/x64")
	set(FMT_LIBDIR "${SGLIB_ROOT}/${FMT_NAME}/lib/x64")
	set(VLD_LIBDIR "${SGLIB_ROOT}/${VLD_NAME}/lib/Win64")
	set(ZMQPP_LIBDIR "${SGLIB_ROOT}/${ZMQPP_NAME}/lib/x64")
else()
	set(LIBZMQ_DIR "${SGLIB_ROOT}/${LIBZMQ_NAME}/lib/win32")
	set(FMT_LIBDIR "${SGLIB_ROOT}/${FMT_NAME}/lib/win32")
	set(VLD_LIBDIR "${SGLIB_ROOT}/${VLD_NAME}/lib/Win32")
	set(ZMQPP_LIBDIR "${SGLIB_ROOT}/${ZMQPP_NAME}/lib/Win32")
endif()

## SG library
set(SGLIB_INCLUDEDIR "${GSL_INCLUDEDIR};${FMT_INCLUDEDIR};${LIBZMQ_INCLUDEDIR};${CPPZMQ_INCLUDEDIR};${VLD_INCLUDEDIR};${Boost_INCLUDE_DIRS};${DATE_INCLUDEDIR};${ZMQPP_INCLUDEDIR};${SPDLOG_INCLUDEDIR};${NLOHMANN_INCLUDEDIR}")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(SGLIB_LIBRARIES "${FMT_LIBDIR}/fmtd.lib;${LIBZMQ_DIR}/libzmq-staticd.lib;${VLD_LIBDIR}/vld.lib;${ZMQPP_LIBDIR}/zmqpp-staticd.lib")
else()
	set(SGLIB_LIBRARIES "${FMT_LIBDIR}/fmt.lib;${LIBZMQ_DIR}/libzmq-static.lib;${VLD_LIBDIR}/vld.lib;${ZMQPP_LIBDIR}/zmqpp-static.lib")
endif()
message(STATUS "SGLIB_INCLUDEDIR: ${SGLIB_INCLUDEDIR}")
message(STATUS "SGLIB_LIBRARIES: ${SGLIB_LIBRARIES}")

### watcher
add_subdirectory(controller)
add_subdirectory(watcher)