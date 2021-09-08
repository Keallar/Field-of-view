#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "mainController.h"

class loop {
public:
    loop();
    ~loop();
    void run();
    void update(sf::Time deltaTime);
    void render();
    void processEvents();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
private:
    static const sf::Time TimePerFrame;
    sf::RenderWindow winMain;
    mainController* mController;
};

