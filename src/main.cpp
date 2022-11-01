#include <iostream>

#include "factory.h"
#include "sample.h"

using namespace hum;

int main(int argc, char** argv) {
    std::cout << "hello hum-cmake" << std::endl;
    std::cout << "fork  hum-cmake" << std::endl;

    Factory* factory = new Factory();
    factory->show("my factory");
    delete factory;
    
    Sample::TestSample();
    
    return 0;
}
