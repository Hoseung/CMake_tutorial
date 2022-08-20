cmake_minimum_required(VERSION 3.12)

project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# <NEW>
# library under a subdirectory
# add_subdirectory(source_dir)
#
# expects a "CMake-valid" library
# with its own CMakeLists.txt file
add_subdirectory(mylib)

# Add configured header file
# configure_file(input output)
# CMake will process the {input} into {output}
# In this case, 
# @Tutorial_VERSION_MAJOR@ will be replaced by "1"
configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial tutorial.cpp)

# Let project "Tutorial" link to the library 'math'
target_link_libraries(Tutorial math)

# add configured header path
target_include_directories(Tutorial PUBLIC
                   "${PROJECT_BINARY_DIR}"
                   "${PROJECT_SOURCE_DIR}/mylib") # <NEW>