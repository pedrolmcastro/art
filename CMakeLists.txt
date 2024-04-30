cmake_minimum_required(VERSION 3.15)

project(
    art
    VERSION 0.1.0
    DESCRIPTION "C++20 concepts library"
    HOMEPAGE_URL "https://github.com/pedrolmcastro/art"
    LANGUAGES CXX
)

message(STATUS "Generating art ${PROJECT_VERSION}")


# Library

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)


# Tests

option(ART_BUILD_TESTS "Build Art tests" OFF)

if(ART_BUILD_TESTS)
    add_subdirectory(tests)
endif()
