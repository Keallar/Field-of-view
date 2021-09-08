#pragma once
#include <vector>
#include <map>
#include <string>
#include "unit.h"
#include "unitfactory.h"

class mainController
{
public:
    mainController(sf::RenderWindow* window);
    ~mainController();
    void init();
    void update(sf::Time deltaTime);
    void render();
    void addUnit(unit* unitObj);
    unit* getUnit(std::string id);
private:
    std::map<std::string, unit*> units;
    sf::RenderWindow* renWindow;
    unitFactory* uFactory;
    unit* firstUnit;

};

