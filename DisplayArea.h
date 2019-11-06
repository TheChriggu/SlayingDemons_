//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_DISPLAYAREA_H
#define UNTITLED_DISPLAYAREA_H
#include "SFML\Graphics.hpp"

class DisplayArea {
    sf::RectangleShape* backgroundImage;

public:
    DisplayArea(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~DisplayArea();

    virtual void drawTo(sf::RenderWindow* window);
};


#endif //UNTITLED_DISPLAYAREA_H
