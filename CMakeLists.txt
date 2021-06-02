cmake_minimum_required(VERSION 3.5)

project(sfinae)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(sfinae main.cpp print_ip.hpp)
add_executable(test tests.cpp print_ip.hpp)

set_target_properties(sfinae test PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
