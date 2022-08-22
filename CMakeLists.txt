cmake_minimum_required(VERSION 3.12)

project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Optional library
option(USE_MYLIB "Use my library" ON)

if(USE_MYLIB)
    add_subdirectory(mylib)
    list(APPEND EXTRA_LIBS MathFunctions)
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

# Let project "Tutorial" link to the library 'MathFunctions'
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add configured header path
target_include_directories(Tutorial PUBLIC
                   "${PROJECT_BINARY_DIR}") 

# install executable under /usr/local/bin
install(TARGETS Tutorial DESTINATION bin)
# put auto-generated TutorialConfig.h under /usr/local/include
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)


# TESTING
enable_testing()
# add a rule for test (and perform the test)
add_test(NAME Runs COMMAND Tutorial 25)

add_test(NAME Usage COMMAND Tutorial)
# "manually" set the *answer* to check the output against
set_tests_properties(Usage 
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# a convenience function to run test
function(do_test target arg result) 
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

# scrypt to run tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is (-nan|nan|0)")
do_test(Tutorial 0.0001 "0.0001 is 0.01")