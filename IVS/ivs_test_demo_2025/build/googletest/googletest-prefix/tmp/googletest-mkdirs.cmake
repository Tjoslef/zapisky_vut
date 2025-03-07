# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest-master")
  file(MAKE_DIRECTORY "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest-master")
endif()
file(MAKE_DIRECTORY
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest-build"
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix"
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/tmp"
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/src/googletest-stamp"
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/src"
  "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tjoslef/skola/vut/IVS/ivs_test_demo_2025/build/googletest/googletest-prefix/src/googletest-stamp${cfgdir}") # cfgdir has leading slash
endif()
