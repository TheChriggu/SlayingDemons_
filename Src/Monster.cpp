//
// Created by christian.heusser on 03.12.2019.
//

#include "Monster.h"
#include <iostream>

sd::Monster::Monster(std::string _pathToPortrait) {
    actions = new std::vector<sf::String>();
    //AddAction("Kick");
    //AddAction("Slash");

    modifiers = new std::vector<sf::String>();
    //AddModifier("Frost");
    //AddModifier("Virtual");

    pathToPortrait = _pathToPortrait;
}

sd::Monster::~Monster() {
    delete(actions);
    actions = nullptr;

    delete(modifiers);
    modifiers = nullptr;
}

sf::String sd::Monster::GetAction() {
    std::cout << "getting enemy_ action\n";
    int i = rand()%(actions->size());
    //std::cout << "enemy_ move is: " << std::string(actions->at(i)) << "\n";
    sf::String retVal = actions->at(i);
    //std::string strg = std::string(retVal);
    return retVal;
}

sf::String sd::Monster::GetModifier() {
    int i = rand()%(modifiers->size());

    return modifiers->at(i);
}

void sd::Monster::AddAction(sf::String action) {
    actions->emplace_back(action);
}

void sd::Monster::AddModifier(sf::String modifier) {
    modifiers->emplace_back(modifier);
}

std::string sd::Monster::GetPathToPortrait() {
    return pathToPortrait;
}
