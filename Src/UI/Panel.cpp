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

    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture);
    sprite_->setColor(color);
    sprite_->setPosition(position);
}

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, const char* texture_path)
    : DrawableObject("Panel")
{
    texture_ = std::make_shared<sf::Texture>();
    texture_->loadFromFile(texture_path);
    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(*texture_);
    sprite_->setPosition(position);
}


void sd::Panel::handle(sf::Event event) {

}

sf::Vector2f sd::Panel::get_position() {
    return sprite_->getPosition();
}

sf::Vector2f sd::Panel::get_size() {
    sf::Vector2f size;
    size.x = sprite_->getTexture()->getSize().x;
    size.y = sprite_->getTexture()->getSize().y;
    sf::Vector2f scale = sprite_->getScale();
    size.x *= scale.x;
    size.y *= scale.y;
    return size;
}

void sd::Panel::draw_to(Sp<sf::RenderTarget> window) const{
    if (shader_procedure_) {

        shader_procedure_->process (window.get (), sprite_.get ());
    } else {
        window->draw(*sprite_);
    }

}

bool sd::Panel::setup() {
    return DrawableObject::setup ();
}


