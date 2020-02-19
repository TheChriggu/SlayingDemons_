//
// Created by christian.heusser on 10.12.2019.
//

#include "Room.h"
#include "Door.h"
#include "Event/EventSystem.h"
#include <utility>
#include <Event/DoorUnlockedEventArgs.h>

sd::Room::Room(std::string name) : Subscriber()
{
    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == EventArgs::Type::ROOM_LAYOUT_CHANGED) {
            for (const auto& object : room_objects_)
            {
                object->put_on_layout(layout_, 11, 7);
            }
        }
    
        if (e->type == EventArgs::Type::DOOR_UNLOCKED) {
            auto arg = std::dynamic_pointer_cast<DoorUnlockedEventArgs>(e);
            if(arg->room_name == name_)
            {
                std::dynamic_pointer_cast<Door>( get_object_with_name(arg->door_name))->set_locked(false);
            }
        }
    
        if (e->type == EventArgs::Type::GOBLIN_DEFEATED) {
            remove_object_with_name("Goblin");
        }
        );
    
    REGISTER_EVENT_HANDLER("Room");
    
    name_ = std::move(name);
    enemy_ = nullptr;
    //tilemap = new Tilemap(11,7,position,sf::Vector2u(64,64));
    layout_ = {
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
    room_objects_.clear();
}


std::string sd::Room::get_description() {
    if (room_objects_.empty())
    {
        return "The room is empty.";
    }


    std::string ret_val = "Inside the room there is a";
    for(const auto& object : room_objects_)
    {
        ret_val += " " + object->get_name() + ",";
    }

    ret_val += ".";

    return ret_val;
}

void sd::Room::add_object(const Sp<sd::RoomObject>& object) {
    object->put_on_layout(layout_, 11, 7);
    room_objects_.emplace_back(object);
}

std::vector<int>& sd::Room::get_layout() {
    return layout_;
}

Sp<sd::RoomObject> sd::Room::get_object_with_name(const std::string& name) {

    for(auto object : room_objects_)
    {
        if (std::string(object->get_name()) == name)
        {
            return object;
        }
    }

    //TODO: Error, if object not found
    return nullptr;
}

void sd::Room::set_enemy(Sp<sd::Monster> enemy) {
    enemy_ = std::move(enemy);
}

std::string sd::Room::get_enter_description() {
    if(enemy_ != nullptr)
    {
        return "You enter the new room. Immediately an enemy_ attacks you.";
    }

    else
    {
        return "You enter the new room.";
    }
}

Sp<sd::Monster> sd::Room::get_enemy() {
    return enemy_;
}

 void sd::Room::remove_object_with_name(const std::string& name) {
    auto it = room_objects_.begin();
    bool it_lock = false;
    for(const auto& object : room_objects_)
    {
        if (std::string(object->get_name()) == name)
        {
            it_lock = true;
        }
        if(!it_lock)
        {
            it.operator++();
        }
    }

    if(it < room_objects_.end())
    {
        (*it)->be_destroyed();
        (*it)->remove_from_layout(layout_, 11, 7);
        room_objects_.erase(it);
    } else
        {
        std::cout << "object not found\n";
    }
}

const std::string &sd::Room::get_name() const
{
    return name_;
}
