//
// Created by christian.heusser on 10.12.2019.
//

#include "Room.h"
#include <utility>

sd::Room::Room(std::string name)
{
    name_ = std::move(name);
    enemy = nullptr;
    //tilemap = new Tilemap(11,7,position,sf::Vector2u(64,64));
    layout = new int[77]{
            0,1,1,1,1,1,1,1,1,1,2,
            8,9,9,9,9,9,9,9,9,9,10,
            8,9,9,9,9,9,9,9,9,9,10,
            8,9,9,9,9,9,9,9,9,9,10,
            8,9,9,9,9,9,9,9,9,9,10,
            8,9,9,9,9,9,9,9,9,9,10,
            16,17,17,17,17,17,17,17,17,17,18
    };
}

sd::Room::~Room() {
    roomObjects.clear();
    delete layout;
    layout = nullptr;
}


sf::String sd::Room::GetDescription() {
    if (roomObjects.size() == 0)
    {
        return "The room is empty.";
    }


    sf::String retVal = "Inside the room there is a";
    for(auto object : roomObjects)
    {
        retVal += " " + object->GetName() + ",";
    }

    retVal += ".";

    return retVal;
}

void sd::Room::AddObject(sd::RoomObject *object) {
    object->PutOnLayout(layout, 11,7);
    roomObjects.emplace_back(object);
}

int *sd::Room::GetLayout() {
    return layout;
}

sd::RoomObject *sd::Room::GetObjectWithName(std::string name) {

    for(auto object : roomObjects)
    {
        if (std::string(object->GetName()) == name)
        {
            return object;
        }
    }

    //TODO: Error, if object not found
    return nullptr;
}

void sd::Room::SetEnemy(sd::Monster *_enemy) {
    enemy = _enemy;
}

std::string sd::Room::GetEnterDescription() {
    if(enemy != nullptr)
    {
        return "You enter the new room. Immediately an enemy attacks you.";
    }

    else
    {
        return "You enter the new room.";
    }
}

sd::Monster *sd::Room::GetEnemy() {
    return enemy;
}

void sd::Room::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == EventArgs::Type::ROOM_LAYOUT_CHANGED) {
        for (auto object : roomObjects)
        {
            object->PutOnLayout(layout, 11,7);
        }
    }

    if (e->type == EventArgs::Type::GOBLIN_DEFEATED) {
        RemoveObjectWithName("Goblin");
    }
}

 void sd::Room::RemoveObjectWithName(std::string name) {
    auto it = roomObjects.begin();
    bool itLock = false;
    for(auto object : roomObjects)
    {
        if (std::string(object->GetName()) == name)
        {
            itLock = true;
        }
        if(!itLock)
        {
            it.operator++();
        }
    }

    if(it < roomObjects.end())
    {
        roomObjects.erase(it);
        SingleTileObject* mushroom = new SingleTileObject("Mushroom", 24, sf::Vector2i(9,3));
        AddObject(mushroom);
    }
}

const std::string &sd::Room::get_name() const
{
    return name_;
}
