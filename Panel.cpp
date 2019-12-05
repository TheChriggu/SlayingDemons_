//
// Created by felix on 26.11.19.
//

#include "Panel.h"
#include <iostream>
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color){
    sf::Texture texture;
    if (!texture.create(size.x,size.y))
    {

    }

    sprite = new sf::Sprite();
    sprite->setTexture(texture);
    sprite->setColor(color);
    sprite->setPosition(position);
}

sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Texture texture)
{
    sprite = new sf::Sprite();
    sprite->setTexture(texture);

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
    window->draw(*sprite);
}


