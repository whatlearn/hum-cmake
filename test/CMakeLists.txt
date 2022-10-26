project(hum-cmake_test)

add_executable("${PROJECT_NAME}" "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

target_link_libraries("${PROJECT_NAME}"
                    ${Factory_LIBS}
                    Threads::Threads)

add_test(NAME "${PROJECT_NAME}"
         COMMAND hum-cmake)