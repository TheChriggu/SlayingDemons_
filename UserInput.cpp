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

sf::Vector2i sd::UserInput::GetMousePosition() {
    std::cout << "get mouse Position" << std::endl;

    auto mousePos = sf::Mouse::getPosition();
    std::cout << "has mouse Position" << std::endl;
    return mousePos;
}

sd::UserInput *sd::UserInput::GetInstance() {
    std::cout << "get Instance" << std::endl;
    return instance;
}

sd::UserInput* sd::UserInput::instance = nullptr;
