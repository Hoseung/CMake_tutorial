#include <iostream>
#include "math.h"

#include "TutorialConfig.h"

using namespace std;

int main(int argc, char **argv) {
    int result;

    if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
    }

#ifdef USE_MYLIB
    result = math::add(1, 2);
    cout << "add 1 + 2 : " << result << endl;

    result = math::add(4, 2);
    cout << "add 4 + 2 : " << result << endl;

    result = math::sub(1, 2);
    cout << "sub 1 - 2 : " << result << endl;

    result = math::sub(4, 2);
    cout << "sub 4 - 2 : " << result << endl;

    result = math::mul(1, 2);
    cout << "mul 1 * 2 : " << result << endl;

    result = math::mul(4, 2);
    cout << "mul 4 * 2 : " << result << endl;
#else
    cout << "No math library!" << endl;
#endif
    return 0;
}
