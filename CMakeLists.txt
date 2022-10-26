cmake_minimum_required(VERSION 3.10)

project(hum-cmake)

option(BUILD_TEST "whether or not build test" ON)

set(CMAKE_CXX_STANDARD 11)
# add_compile_options(-std=c++11)

set(CMAKE_BUILD_TYPE Debug)
# add_compile_definitions(Debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

message(STATUS "CMAKE_CXX_COMPILER:       ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_C_COMPILER:         ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_SOURCE_DIR:         ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR:         ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_INSTALL_PREFIX:     ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_MODULE_PATH:        ${CMAKE_MODULE_PATH}")
message(STATUS "PROJECT_SOURCE_DIR:       ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR:       ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR:     ${CMAKE_INSTALL_LIBDIR}")
message(STATUS "CMAKE_RUNTIME_OUTPUT_DIRECOTRY: ${CMAKE_RUNTIME_OUTPUT_DIRECOTRY}")
message(STATUS "CMAKE_LIBRARY_OUTPUT_DIRECOTRY: ${CMAKE_LIBRARY_OUTPUT_DIRECOTRY}")
message(STATUS "CMAKE_ARCHIVE_OUTPUT_DIRECOTRY: ${CMAKE_ARCHIVE_OUTPUT_DIRECOTRY}")

include_directories("${CMAKE_SOURCE_DIR}/include")

find_package(Threads)
if(NOT Threads_FOUND)
    message(FATAL_ERROR "Not Found Thread Library")
endif()

find_package(Factory)
include_directories(${Factory_INCLUDE_DIR})

add_executable(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/src/main.cpp")

target_link_libraries("${PROJECT_NAME}"
            ${Factory_LIBS}
            Threads::Threads)

# add_custom_target(TARGET copy-include
#                 COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/include ${CMAKE_BINARY_DIR}/output/include)

# install(FILES "${CMAKE_SOURCE_DIR}/include/factory.h"
#         DESTINATION "${CMAKE_BINARY_DIR}/output/${PROJECT_NAME}/include")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/include"
        DESTINATION "${CMAKE_BINARY_DIR}/output/${PROJECT_NAME}")

add_custom_target(echo-pwd
                COMMAND "pwd")

add_custom_target(echo-file
                COMMAND "touch" "temp.txt"
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/output"
                BYPRODUCTS "temp.txt")

# add_custom_command(OUTPUT ${SRC_LISTS}
#                 COMMAND thrift --gen ${PROJECT_SOURCE_DIR}/thrift_myserver.thrift --out ${PROJECT_SOURCE_DIR}/thrift
#                 COMMAND rm -f ${PROJECT_BINARY_DIR}/thrift/xxx.skeleton
#                 DEPENDS ${PROJECT_BINARY_DIR}/thrift/my_server.thrift
#                 COMMENT "Now Generating Thrift Files ...")

if(BUILD_TEST)
    message(STATUS "Build Testing")
    enable_testing()
    add_subdirectory(test)
endif()