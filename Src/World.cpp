//
// Created by felix on 27.11.19.
//

#include <Event/EventSystem.h>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include "World.h"
#include <Event/DoorUnlockedEventArgs.h>

sd::World::World() {

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
    //ScriptEngine::get().register_all("enter_door", &World::enter_door, this);

    return true;
}

void sd::World::shutdown() { }

void sd::World::handle(Sp<sd::EventArgs> e)
{

}

void sd::World::unlock_door(std::string room_name, std::string door_name) {
    std::shared_ptr<DoorUnlockedEventArgs> args;
    args = std::make_shared<DoorUnlockedEventArgs>(room_name, door_name);
    EventSystem::get().trigger(args);
}
