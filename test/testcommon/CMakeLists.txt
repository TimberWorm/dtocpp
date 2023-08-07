set(PROJECT_NAME testcommon)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(${PROJECT_NAME})

set(SRC_LIST
    testcommon.cpp
    main.cpp
   )

set(HEADER_LIST
    testcommon.h
    )

add_executable(${PROJECT_NAME}
    ${SRC_LIST}
    ${HEADER_LIST}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    .
)

target_link_libraries(${PROJECT_NAME}
    testlib
)
