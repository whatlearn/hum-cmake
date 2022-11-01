#include "factory.h"

#include <iostream>

Factory::Factory() {}

Factory::~Factory() {}

void Factory::show(const std::string& str) {
    std::cout << str << std::endl;
}
