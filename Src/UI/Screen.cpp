//
// Created by christian.heusser on 18.02.2020.
//

#include "Screen.h"

sd::Screen::Screen(sf::Vector2u size) : DrawableObject("screen")
{
    texture_ = std::make_shared<sf::RenderTexture>();
    texture_->create(size.x, size.y);

    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture_->getTexture());
}

void sd::Screen::draw_to(Sp<sf::RenderTarget> window) const {
    if (shader_procedure_) {
        //sprite_->setTexture(texture_->getTexture());
        shader_procedure_->process (window.get (), sprite_.get ());
    } else {
        window->draw(*sprite_);
    }
}

sf::Vector2f sd::Screen::get_position() {
    return sf::Vector2f();
}

sf::Vector2f sd::Screen::get_size() {
    return sf::Vector2f();
}

void sd::Screen::handle(sf::Event event) {

}

bool sd::Screen::setup() {
    return DrawableObject::setup();
}

void sd::Screen::clear() {
    texture_->clear();
}

void sd::Screen::display() {
    texture_->display();
}

Sp<sf::RenderTexture> sd::Screen::get_texture() {
    return texture_;
}
