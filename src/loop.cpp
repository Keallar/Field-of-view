#include <iostream>
#include <string>
#include "loop.h"

const sf::Time loop::TimePerFrame = sf::seconds(1.f/60.f);

loop::loop()
    : winMain(sf::VideoMode(1200, 720), "UNIGINE_test_exercise"){
    winMain.setVerticalSyncEnabled(true);
    mController = new mainController(&winMain);
    mController->init();
}

loop::~loop() {
}

void loop::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(winMain.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }

        render();
    }
}

void loop::update(sf::Time deltaTime) {
    mController->update(deltaTime);
}

void loop::render() {
    winMain.clear(sf::Color::Black);
    mController->render();
    winMain.display();
}

void loop::processEvents() {
    sf::Event event;
    while (winMain.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            winMain.close();
            break;
        default:
            break;
        }
    }
}

