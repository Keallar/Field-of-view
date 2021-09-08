#pragma once
#include <map>
#include <string>
#include "unit.h"

class unitFactory
{
public:
    unitFactory(const unitFactory&) = delete;
    void operator = (const unitFactory&) = delete;
    static unitFactory* getInstance();
    static unit* initUnit();
    static unit* createUnit();
    static void readFile(unit* unitObj);
protected:
    unitFactory() = default;
    static unitFactory* instance;
private:
    std::map<std::string, unit*> units;
};

