cmake_minimum_required(VERSION 3.12)

project(Tutorial)

# Add definition for math library
add_library(math math.cpp)

add_executable(Tutorial tutorial.cpp)

# Let project "Tutorial" link to the library 'math'
target_link_libraries(Tutorial math)