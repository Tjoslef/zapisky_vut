##======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============##
##
## Purpose:     IVS Project 1 - CMakeFile (fetch GTest from GIT).
##
## $NoKeywords: $ivs_project_1 $CMakeLists.txt
## $Authors:    Filip Vaverka <ivaverka@fit.vutbr.cz>
##              David Grochol <igrochol@fit.vutbr.cz>
## $Date:       $2017-01-05
##============================================================================##

cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           main
    SOURCE_DIR        "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest-master"
    BINARY_DIR        "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest-build"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND     ""
    INSTALL_COMMAND   ""
    TEST_COMMAND      ""
)
