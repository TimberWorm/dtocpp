set(PROJECT_NAME testlib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(${PROJECT_NAME})

set(SRC_LIST
    test.cpp
   )

set(HEADER_LIST
    test.h
    )

add_library(${PROJECT_NAME} STATIC
    ${SRC_LIST}
    ${HEADER_LIST}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)
