cmake_minimum_required(VERSION 3.0)

project(hum-dp)

option(${PROJECT_NAME}_BUILD_TEST "project build test option" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

message(${CMAKE_MODULE_PATH})

include(utils)

set(MAJOR_VERSION 0)
set(MINOR_VERSION 0)
set(PATCH_VERSION 1)

if (${PROJECT_NAME}_BUILD_TEST)
    message(STATUS "open project build test")
else()
    message(STATUS "close project build test")
endif()

if (UNIX)
    message(STATUS "os UNIX")
endif()

set(USE_LINUX NO CACHE BOOL "USE LINUX")
if (USE_LINUX)
    message(STATUS "use linux")
endif()

file(GLOB dp_header include/*.h)
file(GLOB dp_source src/*.cpp)
file(GLOB all_dir ${CMAKE_SOURCE_DIR}/*)

message(STATUS "${dp_header}")
message(STATUS "${dp_source}")
message(STATUS "${all_dir}")

foreach(child ${all_dir})
    file(RELATIVE_PATH child_name ${CMAKE_SOURCE_DIR} ${child})
    if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${child_name})
        message(STATUS ${child_name})
    endif()
endforeach()

set(list_var "abcd" "bcda" "cdab" "dabc")
list(APPEND list_var "acba")
list(SORT list_var)

message(STATUS "${list_var}")

set(src_str "namespace::class::member")
string(REPLACE "::" "//" dst_str ${src_str})
message(STATUS "${dst_str}")

set(str1 "cmake learn")
set(str2 "cmake cake")

list(LENGTH str2 RES)
message(STATUS "${str2}")

string(REGEX MATCHALL "[A-Za-z]*ke[A-Za-z]*" S_out_var ${str2})
message(STATUS "${S_out_var}")

set(str1 "beijing")
set(str2 "china")
set(str3 "haidian")

string(REGEX MATCH "[A-Za-z]*in[A-Za-z]*" out_var ${str1} ${str2} ${str3})

string(JOIN "_" res_var ${str1} ${str2} ${str3})

message(STATUS "${out_var}")


# list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/src")
# message(STATUS "${CMAKE_PREFIX_PATH}")
# find_path(SIMPLE_FACTORY_INCLUDE
#     NAMES main.cc 
#     PATHS "${CMAKE_SOURCE_DIR}/code/creator/simple-factory"
# )

# find_library(SIMPLE_FACTORY_LIBRARY
#     NAMES simple-factory
#     PATHS "${CMAKE_BINARY_DIR}/code/creator"
# )

# CMAKE_PREFIX_PATH is additional search path of find_package find_path
# find_library find_program find_file
# is used to find executable, headers, and library file.


find_path(INCLUDE_DIRS NAMES "factory.cpp")
message(STATUS "${INCLUDE_DIRS}")

find_package(Threads REQUIRED)
if (Threads_FOUND)
    message(STATUS ${CMAKE_THREAD_LIBS_INIT})
endif()

add_executable("${PROJECT_NAME}" "./src/main.cpp")

target_link_libraries("${PROJECT_NAME}"
            Threads::Threads)