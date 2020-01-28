//
// Created by christian.heusser on 12.12.2019.
//

#include <memory>
#include <utility>
#include <Event/EventArgs.h>
#include <Event/EventSystem.h>
#include <Event/WalkedThroughDoorEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <ScriptEngine/ScriptEngine.h>
#include "Door.h"

sd::Door::Door(std::string name,
               int sprite_sheet_idx_open, int sprite_sheet_idx_locked, sf::Vector2i position_on_tile_map, std::string next_room, sol::function on_interaction)
        : SingleTileObject(std::move(name), sprite_sheet_idx_open, position_on_tile_map, std::move(on_interaction))
        , next_room_(std::move(next_room))
        , sprite_sheet_idx_open_(sprite_sheet_idx_open)
        , sprite_sheet_idx_locked_(sprite_sheet_idx_locked)
        , is_locked_(false)
{

}

const std::string& sd::Door::get_connected_room() const {
    return next_room_;
}

void sd::Door::put_on_layout(std::vector<int>& layout, int width, int height) {
    //TODO: make sure position is within width & height
    SingleTileObject::put_on_layout(layout, width, height);
}

std::string sd::Door::get_name() {
    return SingleTileObject::get_name();
}

void sd::Door::be_interacted_with() {
    if(is_locked_)
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("This door is locked.");
        EventSystem::get().trigger(args);
    }

    else {
        std::shared_ptr<WalkedThroughDoorEventArgs> args;
        args = std::make_shared<WalkedThroughDoorEventArgs>(
            Sp<Door>(this)
                );
        args->type = sd::EventArgs::Type::WALKED_THROUGH_DOOR;
        EventSystem::get().trigger(args);

        /*if (nextRoom) {
            ScriptEngine::Get ()->broadcast ("room_changed", nextRoom->is_last);
        }*/
    }
}

void sd::Door::set_locked(bool lock_state) {
    is_locked_ = lock_state;
    if(is_locked_)
    {
        sprite_sheet_idx_ = sprite_sheet_idx_locked_;
    }
    else
    {
        sprite_sheet_idx_ = sprite_sheet_idx_open_;
    }

    std::shared_ptr<EventArgs> args;
    args = std::make_shared<EventArgs>(EventArgs());
    args->type = sd::EventArgs::Type::ROOM_LAYOUT_CHANGED;
    EventSystem::get().trigger(args);
}
