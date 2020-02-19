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

sd::Door::Door(std::string name, int sprite_sheet_idx_open, int sprite_sheet_idx_locked,
            sf::Vector2i position_on_tile_map, int rotation, std::string next_room, bool is_locked, Sp<FunctionCollection> function_collection)
        : SingleTileObject(std::move(name)
                , sprite_sheet_idx_locked
                , position_on_tile_map
                , rotation
                , function_collection)
        , next_room_(std::move(next_room))
        , sprite_sheet_idx_open_(sprite_sheet_idx_open)
        , sprite_sheet_idx_locked_(sprite_sheet_idx_locked)
        , is_locked_(is_locked)
{
    if(is_locked_)
    {
        sprite_sheet_idx_ = sprite_sheet_idx_locked_;
    }
    else
    {
        sprite_sheet_idx_ = sprite_sheet_idx_open_;
    }
}

const std::string& sd::Door::get_connected_room() const {
    return next_room_;
}

void sd::Door::put_on_layout(std::vector<TileData>& layout, int width, int height) {
    //TODO: make sure position is within width & height
    SingleTileObject::put_on_layout(layout, width, height);
}

std::string sd::Door::get_name() {
    return SingleTileObject::get_name();
}

void sd::Door::be_entered() {
    if(is_locked_)
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("This door is locked.");
        EventSystem::get().trigger(args);
    }

    else {
        auto args = std::make_shared<WalkedThroughDoorEventArgs>(weak_from_this());
        //args->type = sd::EventArgs::Type::WALKED_THROUGH_DOOR;
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

void sd::Door::remove_from_layout(std::vector<TileData> &layout, int width, int height) {
    //TODO: make sure position is within width & height
    SingleTileObject::remove_from_layout(layout, width, height);
}
