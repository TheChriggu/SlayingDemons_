//
// Created by christian.heusser on 06.11.2019.
//

#include "DrawableObject.h"

sd::DrawableObject::DrawableObject(sf::Vector2f position, sf::Vector2f size) {
    sprite = new sf::Sprite();
    sprite->setPosition(position);
    sprite->setScale(size);
}

sd::DrawableObject::~DrawableObject() {
    delete sprite;
    sprite = nullptr;
}

void sd::DrawableObject::Draw(sf::RenderWindow *window) const {
    window->draw(*sprite);
}


