list(APPEND CMAKE_PREFIX_PATH "~/github/hum-cmake/include")
list(APPEND CMAKE_PREFIX_PATH "~/github/hum-cmake/lib")

find_path(Factory_INCLUDE_DIR
    NAMES factory.h
)

find_library(Factory_LIBS
    NAMES factory
)

if (Factory_INCLUDE_DIR)
    message(STATUS ${Factory_LIBS})
endif()