##======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============##
##
## Purpose:     IVS Project 1 - Solution CMakeFile
##
## $NoKeywords: $ivs_project_1 $CMakeLists.txt
## $Authors:    Filip Vaverka <ivaverka@fit.vutbr.cz>
##              David Grochol <igrochol@fit.vutbr.cz>
## $Date:       $2017-01-04
##============================================================================##

cmake_minimum_required(VERSION 2.8.2)
project(ivs_proj_1)

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage.cmake)
    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage -std=c++11")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
endif()

include(GoogleTest.cmake)

# Test targets
enable_testing()

#find_library(BLACK_BOX_LIBS black_box_lib REQUIRED PATHS libs NO_DEFAULT_PATH)
#include_directories("libs")


add_executable(ivs_example ivs_example.cpp ivs_example_test.cpp)
target_link_libraries(ivs_example gtest_main)
GTEST_ADD_TESTS(ivs_example "" ivs_example.cpp)
if(CMAKE_COMPILER_IS_GNUCXX)
    SETUP_TARGET_FOR_COVERAGE(ivs_example_coverage ivs_example ivs_example_coverage)
endif()

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

add_executable(person person_main.cpp person.cpp)
add_executable(person_struct person_struct.c)
add_executable(exception_example exception_example.cpp)
