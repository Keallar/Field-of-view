#pragma once
#include <cmath>
#include "unit.h"

unit::~unit() {

}

void unit::init() {
    angle = 0;
    rectUnit.setSize(sf::Vector2f(5, 5));
    posX = 50;
    posY = 50;
    rectUnit.setPosition(sf::Vector2f(posX, posY));

    distance = 20;
    sector = 135.5f;
    radiusVec = {1, 1};
    rectDir.setPosition(posX + 2.0f, posY + 2.0f);
    rectDir.setSize(sf::Vector2f(distance, 1));
    angle = calculateAngle();
    rectDir.rotate(angle);
    //calculateSector();
}

void unit::update(sf::Time time) {

}

void unit::render() {
    renWin->draw(rectUnit);
    renWin->draw(rectDir);
}

void unit::isCollide(float _x, float _y) {

}

void unit::calculateSector() {
    auto areaSector = (float)(M_PI/360.0f) * (distance) * sector;
}

float unit::calculateAngle() {
    auto xAxis = sf::Vector2f(1, 0);
    auto scalar = xAxis.x * radiusVec.x + xAxis.y * radiusVec.y;
    auto aVec = std::sqrt(std::pow(xAxis.x, 2) + std::pow(xAxis.y, 2));
    auto bVec = std::sqrt(std::pow(radiusVec.x, 2) + std::pow(radiusVec.y, 2));
    auto radian = std::acos(scalar / (aVec * bVec));
    auto finalAngle = (radian * 180.0f) / M_PI;
    return finalAngle/2;
}

std::string unit::getName() noexcept {
    return name;
}

void unit::setName(std::string id) {
    name = id;
}

void unit::setWindow(sf::RenderWindow *_window) {
    renWin = _window;
}

sf::Vector2f unit::getPosition() noexcept {
    return sf::Vector2f(posX, posY);
}

void unit::setPosition(float _x, float _y) {
    posX = _x;
    posY = _y;
    rectUnit.setPosition(posX, posY);
}

sf::Vector2f unit::getDirection() noexcept {
    return radiusVec;
}

void unit::setDirection(float _x, float _y) {
    radiusVec = {_x, _y};
}

float unit::getDistance() noexcept {
    return distance;
}

void unit::setDistance(float _distance) {
    distance = _distance;
}

float unit::getSector() noexcept {
    return sector;
}

void unit::setSector(float _sector) {
    sector = _sector;
}
