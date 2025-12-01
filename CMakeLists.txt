cmake_minimum_required(VERSION 4.0)
project(cango_nstd)

set(CMAKE_CXX_STANDARD 26)

add_library(cango_nstd STATIC src/nstd.cpp)
target_include_directories(cango_nstd BEFORE PUBLIC include)

add_executable(gen_header app/gen_header.cpp)
add_executable(gen_includes app/gen_includes.cpp)

if(${CANGO_ENABLE_TEST_FOR_CANGO_NSTD})
    enable_testing()
    add_subdirectory(test)
endif()
