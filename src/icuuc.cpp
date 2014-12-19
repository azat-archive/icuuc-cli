#include <iostream>
#include <cstdlib>
#include <string>

#include "ops.h"
#include "options.h"

int main(int argc, char **argv)
{
    std::string buffer;
    Ops ops;
    Options options(argc, argv);

    while (std::getline(std::cin, buffer)) {
        if (options.getValue("normalize")) {
            std::cout << ops.normalize(buffer) << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
