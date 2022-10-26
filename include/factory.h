#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>

class Factory {
public:
    Factory();
    ~Factory();

    void show(const std::string& str);
private:
    std::string name_;
};

#endif // __FACTORY_H_