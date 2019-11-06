//
// Created by christian.heusser on 06.11.2019.
//

#include "DisplayArea.h"

DisplayArea::DisplayArea(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    backgroundImage = new sf::RectangleShape(size);
    backgroundImage->setPosition(position);
    backgroundImage->setFillColor(color);
}

DisplayArea::~DisplayArea() {

}

void DisplayArea::drawTo(sf::RenderWindow *window) {
    window->draw(*backgroundImage);
}


