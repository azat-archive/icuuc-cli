#include <iostream>
#include <cstdlib>
#include <string>

#include "ops.h"

int main(int argc, char **argv)
{
    std::string buffer;
    Ops ops;

    while (std::getline(std::cin, buffer)) {
        std::cout << ops.normalize(buffer) << std::endl;
    }

    return EXIT_SUCCESS;
}
