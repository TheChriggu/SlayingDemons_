//
// Created by christian.heusser on 08.01.2020.
//

#include <memory>
#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include "Table.h"

void sd::Table::BeInteractedWith() {
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("...*cough*...That was a bad idea."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Note to myself: Don't pull dusty sheets of dusty funiture in dusty, old houses."));
    EventSystem::Get().Trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("It's a table with a drawer under the table top...but the drawer is empty. "));
    EventSystem::Get().Trigger(args);
}

sd::Table::Table(std::string _name, int *_layout, sf::Vector2i _size, sf::Vector2i _positionOnTileMap)
        : MultiTileObject(_name, _layout, _size, _positionOnTileMap) {

}
