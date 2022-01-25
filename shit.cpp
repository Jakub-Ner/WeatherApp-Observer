#include "shit.h"


int Factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

//void shit() {
//    std::string path = "./";
//    using std::filesystem::directory_iterator;
//
//    for (const auto & file : directory_iterator(path))
//        std::cout << file.path() << std::endl;
//
////    return EXIT_SUCCESS;
//}
