cmake_minimum_required(VERSION 3.1)

#include(utils/functions.cmake)

project(github-api-parser C CXX ASM)

set(ENABLE_COVERAGE FALSE CACHE BOOL "Enable code coverage" )

set(OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

#set(REPORTS_PATH ${OUTPUT_PATH}/reports)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_PATH}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_PATH}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}/bin)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
else()
    set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)
endif()

message(STATUS "Using C compiler from ${CMAKE_C_COMPILER}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Code coverage: ${ENABLE_COVERAGE}")

include_directories(../json/src)

add_subdirectory(src)
#add_subdirectory(libs)
#add_subdirectory(doc)
#add_subdirectory(unit_tests)
#add_subdirectory(integration_tests)
#add_subdirectory(utils)
#add_subdirectory(test)
