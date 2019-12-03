//
// Created by christian.heusser on 28.11.2019.
//

#include "Player.h"

sd::Player::Player() {
    actions = new std::vector<sf::String>();
    actions->emplace_back("honk");
    actions->emplace_back("smash");

    modifiers = new std::vector<sf::String>();
    modifiers->emplace_back("flirty");
    modifiers->emplace_back("heavy");

    world = new std::vector<sf::String>();
    world->emplace_back("walk to");
    world->emplace_back("jump over");
}

sd::Player::~Player() {
    delete (actions);
    delete (modifiers);
    delete (world);
    actions = nullptr;
    modifiers = nullptr;
    world = nullptr;
}

bool sd::Player::HasWord(sf::String word) {
    if(std::count(actions->begin(),actions->end(),word))
    {
        return true;
    }
    if(std::count(modifiers->begin(),modifiers->end(),word))
    {
        return true;
    }
    if(std::count(world->begin(),world->end(),word))
    {
        return true;
    }
    return false;
}
