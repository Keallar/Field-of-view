#include "maincontroller.h"

mainController::mainController(sf::RenderWindow* window)
    : renWindow(window){
    uFactory = unitFactory::getInstance();
}

mainController::~mainController() {
}

void mainController::init() {
    auto tempUnit = uFactory->initUnit();
    tempUnit->init();
    tempUnit->setWindow(renWindow);
    addUnit(tempUnit);
}

void mainController::update(sf::Time deltaTime) {
    firstUnit->update(deltaTime);
}

void mainController::render() {
    for (const auto unObj : units) {
        unObj.second->render();
    }
}

void mainController::addUnit(unit *unitObj) {
    units.insert(std::pair<std::string, unit*>(unitObj->getName(), unitObj));
}
unit* mainController::getUnit(std::string id) {
    auto foundUnit = units.find(id);
    return foundUnit->second;
}
