//
// Created by christian.heusser on 08.01.2020.
//

#include <memory>
#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include "Sofa.h"

sd::Sofa::Sofa(std::string _name, int *_layout, sf::Vector2i _size, sf::Vector2i _positionOnTileMap) : MultiTileObject(
        _name, _layout, _size, _positionOnTileMap) {

}

void sd::Sofa::BeInteractedWith() {
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("That's just an old sofa. It looks like it hasn't been used in a very long time. "));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("But...what's that? Are those holes? "));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Ugh, yes. I will definitely not try to sit on it!"));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("I'm not sure if it will hold with all those holes... "));
    EventSystem::Get().Trigger(args);
}
