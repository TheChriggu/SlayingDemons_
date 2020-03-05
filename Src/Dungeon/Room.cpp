//
// Created by christian.heusser on 10.12.2019.
//

#include "Room.h"
#include "Door.h"
#include "Event/EventSystem.h"
#include <utility>
#include <Event/DoorUnlockedEventArgs.h>


sd::Room::Room(std::string name, const std::vector<sf::Vector2i>& corners)
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
    
    REGISTER_EVENT_HANDLER();
    
    name_ = std::move(name);
    enemy_ = nullptr;
    layout_ = std::vector<TileData>(77);
    TileData no_tile = {8,0};
    std::fill(layout_.begin(),layout_.end(), no_tile);
    generate_wall_layout_from_corners(corners);
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
    for(const auto& object : get_all_objects())
    {
        ret_val += " [button=" + object + "]" + object + ",";
    }

    ret_val += ".";

    return ret_val;
}

std::vector<std::string> sd::Room::get_all_objects() const
{
    std::vector<std::string> names;
    
    for(const auto& object : room_objects_)
    {
        names.emplace_back(object->get_name());
    }
    
    return names;
}

void sd::Room::add_object(const Sp<sd::RoomObject>& object) {
    object->put_on_layout(layout_, 11, 7);
    room_objects_.emplace_back(object);
}

std::vector<sd::TileData>& sd::Room::get_layout() {
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
    std::cout << "searching for: " << name << "\n";
    auto it = room_objects_.begin();
    bool it_lock = false;
    for(const auto& object : room_objects_)
    {
        std::cout << "comparing to: " << std::string(object->get_name())  << "\n";
        if (std::string(object->get_name()) == name)
        {
            std::cout << "is valid \n";
            it_lock = true;
        }
        if(!it_lock)
        {
            std::cout << "is not valid \n";
            it.operator++();
        }
    }

    if(it < room_objects_.end())
    {
        (*it)->be_destroyed();
        (*it)->remove_from_layout(layout_, 11, 7);
        room_objects_.erase(it);
    }
    else
        {
        std::cout << "object not found\n";
    }
}

const std::string &sd::Room::get_name() const
{
    return name_;
}

void sd::Room::generate_wall_layout_from_corners(const std::vector<sf::Vector2i>& corners) {

    try
    {
        sf::Vector2i previous_corner;
        sf::Vector2i current_corner;
        sf::Vector2i next_corner;

        for (int i=0; i < corners.size(); i++)
        {
            previous_corner = corners[(i-1+corners.size())%corners.size()];
            current_corner = corners[i];
            next_corner = corners[(i+1)%corners.size()];
            
            set_corner_orientation(previous_corner, current_corner, next_corner);
            build_wall_from_current_to_next(current_corner, next_corner);
        }


    }
    catch(std::exception& e)
    {
        //invalid corners
    }
}

void
sd::Room::set_corner_orientation(sf::Vector2i previous_corner, sf::Vector2i current_corner, sf::Vector2i next_corner) {

    //wall comes from the left
    if(previous_corner.x < current_corner.x && next_corner.y > current_corner.y)
    {
        layout_[current_corner.y*11+current_corner.x] = {0,1};
    }
    if(previous_corner.x < current_corner.x && next_corner.y < current_corner.y)
    {
        layout_[current_corner.y*11+current_corner.x] = {2,0};
    }

    //wall comes from the right
    if(previous_corner.x > current_corner.x && next_corner.y > current_corner.y)
    {
        layout_[current_corner.y*11+current_corner.x] = {2,2};
    }
    if(previous_corner.x > current_corner.x && next_corner.y < current_corner.y)
    {
        layout_[current_corner.y*11+current_corner.x] = {0,3};
    }

    //wall comes from the above
    if(previous_corner.y < current_corner.y && next_corner.x > current_corner.x)
    {
        layout_[current_corner.y*11+current_corner.x] = {2,1};
    }
    if(previous_corner.y < current_corner.y && next_corner.x < current_corner.x)
    {
        layout_[current_corner.y*11+current_corner.x] = {0,2};
    }

    //wall comes from the below
    if(previous_corner.y > current_corner.y && next_corner.x > current_corner.x)
    {
        layout_[current_corner.y*11+current_corner.x] = {0,0};
    }
    if(previous_corner.y > current_corner.y && next_corner.x < current_corner.x)
    {
        layout_[current_corner.y*11+current_corner.x] = {2,3};
    }
}

//draws wall between two corners. next_corner must be next corner clockwise from current corner.
void sd::Room::build_wall_from_current_to_next(sf::Vector2i current_corner, sf::Vector2i next_corner) {
    if(next_corner.x > current_corner.x)
    {
        for (int i=current_corner.x + 1; i < next_corner.x; i++)
        {
            TileData wall = {1,0};
            layout_[current_corner.y*11 + i ] = wall;
        }
    }
    if(next_corner.y > current_corner.y)
    {
        for (int i=current_corner.y + 1; i < next_corner.y; i++)
        {
            TileData wall = {1,1};
            layout_[i*11 + current_corner.x] = wall;
        }
    }
    if(next_corner.x < current_corner.x)
    {
        for (int i=current_corner.x - 1; i > next_corner.x; i--)
        {
            TileData wall = {1,2};
            layout_[current_corner.y*11 + i ] = wall;
        }
    }
    if(next_corner.y < current_corner.y)
    {
        for (int i=current_corner.y - 1; i > next_corner.y; i--)
        {
            TileData wall = {1,3};
            layout_[i*11 + current_corner.x] = wall;
        }
    }


}

