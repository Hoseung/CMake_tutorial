cmake_minimum_required(VERSION 3.12)

project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Optional library
option(USE_MYLIB "Use my library" ON)

if(USE_MYLIB)
    add_subdirectory(mylib)
    list(APPEND EXTRA_LIBS math)
    # Extra include dir is no longer needed.
    # The requirement is imposed by the rule in mylib/CMakeLists.txt
endif()

# Add configured header file
# configure_file(input output)
# CMake will process the {input} into {output}
# In this case, 
# @Tutorial_VERSION_MAJOR@ will be replaced by "1"
configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial tutorial.cpp)

# Let project "Tutorial" link to the library 'math'
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add configured header path
target_include_directories(Tutorial PUBLIC
                   "${PROJECT_BINARY_DIR}") 

# <NEW>
# install executable under /usr/local/bin
install(TARGETS Tutorial DESTINATION bin)
# put auto-generated TutorialConfig.h under /usr/local/include
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)