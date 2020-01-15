//
// Created by felix on 26.11.19.
//

#include "Panel.h"

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("panel")
{
    sf::Texture texture;
    if (!texture.create(size.x,size.y))
    {

    }

    sprite = std::make_shared<sf::Sprite>();
    sprite->setTexture(texture);
    sprite->setColor(color);
    sprite->setPosition(position);
}

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, const char* texture_path)
    : DrawableObject("Panel")
{
    texture = std::make_shared<sf::Texture>();
    texture->loadFromFile(texture_path);
    sprite = std::make_shared<sf::Sprite>();
    sprite->setTexture(*texture, false);
    sprite->setPosition(position);
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

void sd::Panel::DrawTo(sp<sf::RenderTarget> window) const{
    if (shaderProcedure_) {

        shaderProcedure_->Process(window.get(), sprite.get());
    } else {
        window->draw(*sprite);
    }

}

bool sd::Panel::Setup() {
    return DrawableObject::Setup();
}


