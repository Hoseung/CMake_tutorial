# Add definition for math library
add_library(MathFunctions mysqrt.cpp)

# require the INTERFACE(=user) of this library
# to include this library's source files. 
target_include_directories(MathFunctions
            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
            )  

# <NEW>
# Check for system dependency
# run a test code and save the results 
# to variables HAVE_LOG and HAVE_EXP. 
include(CheckCXXSourceCompiles)
check_cxx_source_compiles("
    #include <cmath>
    int main() {
        std::log(1.0);
        return 0;
    }
" HAVE_LOG)
check_cxx_source_compiles("
    #include <cmath>
    int main() {
        std::exp(1.0);
        return 0;
    }
" HAVE_EXP)

# If exp and log re available,
# define compile definitions (referred by math.cpp)
if(HAVE_EXP AND HAVE_LOG)
    target_compile_definitions(MathFunctions
                        PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()



# rules for "install" 
# install files under /usr/local/lib and /usr/local/include
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

