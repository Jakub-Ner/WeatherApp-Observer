#include "shit.h"

void shit() {
    std::string path = "./";
    using std::filesystem::directory_iterator;

    for (const auto & file : directory_iterator(path))
        std::cout << file.path() << std::endl;

//    return EXIT_SUCCESS;
}
