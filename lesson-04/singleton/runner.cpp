#include "runner.h"

#include "registry.h"
#include <iostream>

Runner::Runner()
{
    std::cout << "A : " << Registry::instance()->property("A") << std::endl;
}
