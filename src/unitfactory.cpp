#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "unitfactory.h"

unitFactory* unitFactory::instance = nullptr;

unitFactory* unitFactory::getInstance() {
    if (instance == nullptr) {
        instance = new unitFactory{};
    }
    return instance;
}

unit* unitFactory::createUnit() {
    return new unit{};
}

unit* unitFactory::initUnit() {
    auto createdUnit = createUnit();
    createdUnit->init();
    readFile(createdUnit);
    return createdUnit;
}

void unitFactory::readFile(unit *unitObj) {
    std::fstream file;
    file.open("data/unitsInfo.txt");
    if (!file.is_open()) {
        std::cout << "File wasn't open!" << std::endl;
    }
    while (file) {
        std::string type;
        float sector;
        float distance;
        std::string name;
        file >> type;
        if (type == "Sector:") {
            std::cout << type << std::endl;
            file >> sector;
        }
        file >> type;
        if (type == "Distance:") {
            std::cout << type << std::endl;
            file >> distance;
        }
        file >> name;
        if (name == "Unit_1") {
            std::cout << name <<std::endl;
            unitObj->setName(name);
        }
    }
}
