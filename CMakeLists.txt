cmake_minimum_required(VERSION 3.5)

project(print_ip)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_executable(print_ip main.cpp print_ip.hpp)
add_executable(test tests.cpp print_ip.hpp)

set_target_properties(print_ip test PROPERTIES CXX_STANDARD 14 CXX_STANDARD_REQUIRED ON)
