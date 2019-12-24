//
// Created by christian.heusser on 28.11.2019.
//

#include "Player.h"

//sd::Player::Player() {
    //actions = new std::vector<sf::String>();
    //AddAction("honk");
    //AddAction("smash");

    //modifiers = new std::vector<sf::String>();
    //AddModifier("flirty");
    //AddModifier("heavy");

    //world = new std::vector<sf::String>();
    //AddWorld("walk to");
    //AddWorld("jump over");
//}

sd::Player::~Player() {
   // delete (actions);
    //delete (modifiers);
    //delete (world);
    //actions = nullptr;
    //modifiers = nullptr;
    //world = nullptr;
}

bool sd::Player::HasWord(sf::String word) {
    //if(std::count(actions->begin(),actions->end(),word))
    //{
    //    return true;
    //}
    //if(std::count(modifiers->begin(),modifiers->end(),word))
    //{
    //    return true;
    //}
    //if(std::count(world->begin(),world->end(),word))
    //{
    //    return true;
    //}
    return false;
}

void sd::Player::AddAction(sf::String action) {
    //actions->emplace_back(action);
}

void sd::Player::AddModifier(sf::String modifier) {
    //modifiers->emplace_back(modifier);
}

void sd::Player::AddWorld(sf::String word) {
    //world->emplace_back(word);
}
