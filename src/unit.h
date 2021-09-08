#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class unit {
public:
    unit() = default;
    ~unit();
    std::string getName() noexcept;
    void setName(std::string id);
    void setWindow(sf::RenderWindow* _window);
    sf::Vector2f getPosition() noexcept;
    void setPosition(float _x, float _y);
    sf::Vector2f getDirection() noexcept;
    void setDirection(float _x, float _y);
    float getDistance() noexcept;
    void setDistance(float _distance);
    float getSector() noexcept;
    void setSector(float _sector);
    void init();
    void update(sf::Time time);
    void render();
    void spawn();
    void isCollide(float _x, float _y);
    void calculateSector();
    float calculateAngle();
private:
    sf::RenderWindow* renWin;
    sf::RectangleShape rectUnit;
    sf::RectangleShape rectDir;
    sf::CircleShape circSector;
    std::string name;
    float posX;
    float posY;
    float sector;
    float distance;
    sf::Vector2f radiusVec;
    float angle;
};

