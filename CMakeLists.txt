cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -Werror")
SET(CMAKE_CXX_FLAGS_DEBUG "-g -fno-inline -Wall -Werror")

project(dtocpp)

add_subdirectory( src/dtocpp )
add_subdirectory( test/testlib)
add_subdirectory( test/testcommon)
