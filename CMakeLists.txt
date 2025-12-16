cmake_minimum_required(VERSION 3.28)
project(cango.nstd
    VERSION 0.1.0
    LANGUAGES CXX
)

set(cango.lib.namespace "cango")
set(cango.lib.name "nstd")
set(cango.lib.fullname "${cango.lib.namespace}_${cango.lib.name}")
set(cango.lib.alias "${cango.lib.namespace}::${cango.lib.name}")

set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_SCAN_FOR_MODULES_OUTPUT_DIR "${CMAKE_BINARY_DIR}/modules")
file(GLOB_RECURSE cango.lib.modules
    "${CMAKE_CURRENT_SOURCE_DIR}/module/*.cppm"
    "${CMAKE_CURRENT_SOURCE_DIR}/module/*.ixx"
)
file(GLOB_RECURSE cango.lib.sources
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

option(CANGO_NSTD_AS_SHARED "将 cango.nstd 构建为动态链接库" NO)
if (${CANGO_NSTD_AS_SHARED})
    set(cango.lib.build_type "SHARED")
else()
    set(cango.lib.build_type "STATIC")
endif()

add_library(${cango.lib.fullname} ${cango.lib.build_type})
target_sources(${cango.lib.fullname}
    PUBLIC ${cango.lib.sources}
    PUBLIC FILE_SET CXX_MODULES FILES ${cango.lib.modules}
)
add_library(${cango.lib.alias} ALIAS ${cango.lib.fullname})
target_include_directories(${cango.lib.fullname} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(${cango.lib.fullname} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    CXX_STANDARD 26
    EXPORT_NAME ${cango.lib.fullname}
    CXX_MODULES_DIRECTORY ${CMAKE_CXX_SCAN_FOR_MODULES_OUTPUT_DIR}
)

#include(GNUInstallDirs)

add_executable(pather app/pather.cpp)

if(${CANGO_NSTD_BUILD_TESTING})
    enable_testing()
    add_subdirectory(test)
endif()
