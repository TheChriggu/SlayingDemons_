//
// Created by felix on 26.11.19.
//

#include "Panel.h"

sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject(position, size) {
    //auto shape = sf::RectangleShape(size);
    //shape.setFillColor(color);

    //sprite->setTexture(*shape.getTexture());
}

sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Texture texture)
    : DrawableObject(position, size) {
    sprite->setTexture(texture);
}

void sd::Panel::Handle(sf::Event event) {

}
