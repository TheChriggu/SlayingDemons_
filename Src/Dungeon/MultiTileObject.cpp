//
// Created by christian.heusser on 11.12.2019.
//

#include <iostream>
#include <memory>
#include <utility>
#include <Event/EventSystem.h>
#include <Event/LineToOutputEventArgs.h>
#include "MultiTileObject.h"

sd::MultiTileObject::MultiTileObject(std::string name, const int *layout, sf::Vector2i size, int rotation,
                                     sf::Vector2i position_on_tile_map, Sp<FunctionCollection> function_collection)
    : RoomObject(std::move(name), position_on_tile_map, function_collection)
    , rotation_(rotation)
{
    layout_ = new int[size_.x * size_.y]();

    switch(rotation%4)
    {
        case 0:
            size_ = size;
            for(int row = 0; row < size_.x;row++)
            {
                for(int col = 0; col < size_.y; col++)
                {
                    layout_[row*size_.x+col] = layout[row*size_.x+col];
                }
            }
            break;

        case 1:
            size_.x = size.y;
            size_.y = size.x;
            for(int row = 0; row < size_.x;row++)
            {
                for(int col = 0; col < size_.y; col++)
                {
                    int o_row = size_.x - 1 - col;
                    int o_col = row;
                    layout_[row*size_.x+col] = layout[o_row * size.x + o_col];
                }
            }
            break;

        case 2:
            size_ = size;
            for(int row = 0; row < size_.x;row++)
            {
                for(int col = 0; col < size_.y; col++)
                {
                    int o_row = size_.x - 1 - row;
                    int o_col = size_.y - 1 - col;
                    layout_[row*size_.x+col] = layout[o_row * size.x + o_col];
                }
            }
            break;

        case 3:
            size_.x = size.y;
            size_.y = size.x;
            for(int row = 0; row < size_.x;row++)
            {
                for(int col = 0; col < size_.y; col++)
                {
                    int o_row = col;
                    int o_col = size_.y - 1 - row;
                    layout_[row*size_.x+col] = layout[o_row * size.x + o_col];
                }
            }
            break;
    }



    for (int i=0; i < size_.x * size_.y; i++)
    {
        layout_[i] = layout[i];
    }

}

sd::MultiTileObject::~MultiTileObject() {
    delete layout_;
    layout_ = nullptr;
}

void sd::MultiTileObject::put_on_layout(std::vector<TileData>& layout, int width, int height) {

    if((width < position_on_tile_map_.x + size_.x) || (height < position_on_tile_map_.y + size_.y))
    {
        std::cout << "MultiTileObject outside Room";
    }
    else
    {
        int start_pos = position_on_tile_map_.x + position_on_tile_map_.y * width;

        for(int i = 0; i < size_.x * size_.y; i++)
        {

            int row = i / size_.x;
            int col = i % size_.x;

            int pos = start_pos + col + row * width;

            if(this->layout_[i] != -1)
            {
                layout[pos].tile_idx_ = this->layout_[i];
                layout[pos].rotation_ = rotation_;
            }
        }

    }

}

std::string sd::MultiTileObject::get_name() {
    return name_;
}

void sd::MultiTileObject::remove_from_layout(std::vector<TileData> &layout, int width, int height) {

    if((width < position_on_tile_map_.x + size_.x) || (height < position_on_tile_map_.y + size_.y))
    {
        std::cout << "MultiTileObject outside Room";
    }
    else
    {
        int start_pos = position_on_tile_map_.x + position_on_tile_map_.y * width;

        for(int i = 0; i < size_.x * size_.y; i++)
        {
            int row = i / size_.x;
            int col = i % size_.x;

            int pos = start_pos + col + row * width;

            if(this->layout_[i] != -1)
            {
                layout[pos].tile_idx_ = 9;
                layout[pos].rotation_ = 0;
            }
        }

    }
}
