//
// Created by felix on 27.11.19.
//

#include "SFML/Graphics.hpp"
#include <iostream>
#include "UserInput.h"

sd::UserInput::UserInput(sf::RenderWindow *window)
    : window_(window) {
    sd::UserInput::instance = this;
}

sd::UserInput::~UserInput() {
    // UserInput doesn't owns the window
    window_ = nullptr;
}

sf::Vector2f sd::UserInput::get_mouse_position() {

    auto mouse_pos = sf::Mouse::getPosition(*window_);

    return window_->mapPixelToCoords(mouse_pos);
}

sd::UserInput *sd::UserInput::GetInstance() {
    return instance;
}

sd::UserInput* sd::UserInput::instance = nullptr;
