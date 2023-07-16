set(PROJECT_NAME dtocpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(${PROJECT_NAME})

#file(GLOB_RECURSE SRC_FILES_CORE core/*.cpp core/*.h)

set(SRC_LIST
    dtocpp_led.cpp
    )

set(HEADER_LIST
    dtocpp.h
    dtocpp_led.h
    )

add_library(${PROJECT_NAME} STATIC
    ${SRC_LIST}
    ${HEADER_LIST}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)
