cmake_minimum_required(VERSION 3.14.5)
project(CB_JL_Project3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CB_JL_Project3 main.cpp Store.h Store.cpp Isle.h Isle.cpp Customer.h Grocery.h Grocery.cpp Customer.cpp)
add_executable(Project3_Testing testing.cpp Store.h Store.cpp Isle.h Isle.cpp Customer.h Grocery.h Grocery.cpp Customer.cpp)