//
// Created by christian.heusser on 10.12.2019.
//

#include <memory>
#include <utility>
#include "SingleTileObject.h"

sd::SingleTileObject::SingleTileObject(std::string name, int sprite_sheet_idx, sf::Vector2i position_on_tile_map, sol::function on_interaction)
        : RoomObject(std::move(name), position_on_tile_map, std::move(on_interaction))
        , sprite_sheet_idx_(sprite_sheet_idx)
{ }

void sd::SingleTileObject::put_on_layout(int *layout, int width, int height) {
    //TODO: Make sure to check position against width & height
    layout[position_on_tile_map_.x + position_on_tile_map_.y * width] = sprite_sheet_idx_;
}

std::string sd::SingleTileObject::get_name() {
    return name_;
}
