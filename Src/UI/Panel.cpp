//
// Created by felix on 26.11.19.
//

#include "Panel.h"
#include <iostream>

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("panel")
{
    sf::Texture texture;
    if (!texture.create(size.x,size.y))
    {

    }

    sprite = new sf::Sprite();
    sprite->setTexture(texture);
    sprite->setColor(color);
    sprite->setPosition(position);
}

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Texture* texture)
    : DrawableObject("Panel")
{
    sprite = new sf::Sprite();

    sprite->setTexture(*texture, false);

    sprite->setPosition(position);
}

sd::Panel::~Panel() {
    delete sprite;
    sprite = nullptr;
}



void sd::Panel::Handle(sf::Event event) {

}

sf::Vector2f sd::Panel::GetPosition() {
    return sprite->getPosition();
}

sf::Vector2f sd::Panel::GetSize() {
    sf::Vector2f size;
    size.x = sprite->getTexture()->getSize().x;
    size.y = sprite->getTexture()->getSize().y;
    sf::Vector2f scale = sprite->getScale();
    size.x *= scale.x;
    size.y *= scale.y;
    return size;
}

void sd::Panel::DrawTo(sf::RenderTarget *window) const{
    if (shaderProcedure_) {

        shaderProcedure_->Process(window, sprite);
    } else {
        window->draw(*sprite);
    }

}


