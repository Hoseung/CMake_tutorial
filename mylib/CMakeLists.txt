# Add definition for math library
add_library(math math.cpp)

# require the INTERFACE(=user) of this library
# to include this library's source files. 
target_include_directories(math
            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
            )  

# <NEW>
# rules for "install" 
# install files under /usr/local/lib and /usr/local/include
install(TARGETS math DESTINATION lib)
install(FILES math.h DESTINATION include)