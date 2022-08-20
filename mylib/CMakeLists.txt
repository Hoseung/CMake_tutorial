# Add definition for math library
add_library(math math.cpp)

# <NEW>
# require the INTERFACE(=user) of this library
# to include this library's source files. 
target_include_directories(math
            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
            )  