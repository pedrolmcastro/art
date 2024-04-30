cmake_minimum_required(VERSION 3.15)

project(art_tests CXX)
message(STATUS "Generating art tests")

include(../cmake/warnings.cmake)


if(NOT TARGET art)
    find_package(art REQUIRED)
endif()


if(NOT WIN32)
    set(CMAKE_EXECUTABLE_SUFFIX_CXX ".out")
endif()


file(GLOB_RECURSE ART_TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

foreach(ART_TEST_SOURCE ${ART_TEST_SOURCES})
    get_filename_component(ART_TEST ${ART_TEST_SOURCE} NAME_WLE)

    add_executable(${ART_TEST} ${ART_TEST_SOURCE})
    target_link_libraries(${ART_TEST} PRIVATE art::art)

    cppmake_enable_warnings(TARGET ${ART_TEST} AS_ERRORS)
endforeach()
