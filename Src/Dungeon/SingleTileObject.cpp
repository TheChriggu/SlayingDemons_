//
// Created by christian.heusser on 10.12.2019.
//

#include <memory>
#include <utility>
#include "SingleTileObject.h"
#include "Core/GlobalDefinitions.h"

sd::SingleTileObject::SingleTileObject(std::string name, int sprite_sheet_idx, sf::Vector2i position_on_tile_map, int rotation, Sp<FunctionCollection> function_collection)
        : RoomObject(std::move(name), position_on_tile_map, function_collection)
        , sprite_sheet_idx_(sprite_sheet_idx)
        ,rotation_(rotation)
{ }

void sd::SingleTileObject::put_on_layout(std::vector<TileData>& layout, int width, int height) {
    //TODO: Make sure to check position against width & height
    layout[position_on_tile_map_.x + position_on_tile_map_.y * width].tile_idx_ = sprite_sheet_idx_;
    layout[position_on_tile_map_.x + position_on_tile_map_.y * width].rotation_ = rotation_;
}

std::string sd::SingleTileObject::get_name() {
    return name_;
}

void sd::SingleTileObject::remove_from_layout(std::vector<TileData> &layout, int width, int height) {
        //TODO: Make sure to check position against width & height
        layout[position_on_tile_map_.x + position_on_tile_map_.y * width].tile_idx_ = 8;
    layout[position_on_tile_map_.x + position_on_tile_map_.y * width].rotation_ = 0;
}
