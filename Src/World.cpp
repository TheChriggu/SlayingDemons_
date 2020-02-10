//
// Created by felix on 27.11.19.
//

#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include "World.h"
#include <Event/DoorUnlockedEventArgs.h>

sd::World::World() : Subscriber(){

}

bool sd::World::setup() {
    player_state_ = std::make_shared<PlayerState>();
    
    EventSystem& event_system = EventSystem::get();
    event_system.trigger(std::make_shared<PlayerStateCreatedEventArgs>(player_state_.get()));
    
    
    auto dungeon_script = ScriptEngine::get().get_script("dungeon");
    
    if (!dungeon_script) return false;
    
    auto dungeon_data = dungeon_script->get_table("dungeon");
    
    if (!dungeon_data) return false;
    
    for (const auto& floor_data : dungeon_data.value()) {
        
        std::string name = floor_data.first.as<std::string>();
        sol::table data = floor_data.second.as<sol::table>();
        
        floors_.emplace_back(std::make_shared<Floor>(name, data));
    
        if (data["is_start"].valid()) {
            player_state_->set_current_floor(floors_.back());
            player_state_->set_current_room(floors_.back()->get_start_room());
        }
    }

    ScriptEngine::get().register_all("unlock_door", &World::unlock_door, this);
    ScriptEngine::get().register_all("set_floor", &World::set_floor, this);

    return true;
}

void sd::World::shutdown() { }

void sd::World::handle(Sp<sd::EventArgs> e)
{
    if (e->type == EventArgs::Type::PLAYER_DIED)
    {
        //reset player
        player_state_->load_vocab();

        //reset floor
        int i = 0;

        while(floors_[i] != player_state_->get_current_floor())
        {
            i++;
        }

        //reload room with same name as current room, emplace it back in floors_
        auto dungeon_script = ScriptEngine::get().get_script("dungeon");
        auto dungeon_data = dungeon_script->get_table("dungeon");

        for (const auto& floor_data : dungeon_data.value()) {

            std::string name = floor_data.first.as<std::string>();
            if(name == floors_[i]->get_name())
            {
                sol::table data = floor_data.second.as<sol::table>();

                floors_[i] = (std::make_shared<Floor>(name, data));

                set_floor(floors_[i]->get_name());
            }
        }
    }
}

void sd::World::unlock_door(std::string room_name, std::string door_name) {
    std::shared_ptr<DoorUnlockedEventArgs> args;
    args = std::make_shared<DoorUnlockedEventArgs>(room_name, door_name);
    EventSystem::get().trigger(args);
}

void sd::World::set_floor(std::string floor_name) {
    for (auto floor : floors_)
    {
        if(floor->get_name() == floor_name)
        {
            player_state_->set_current_floor(floor);
            player_state_->set_current_room(floor->get_start_room());
            player_state_->save_current_vocab();
        }
    }
}
