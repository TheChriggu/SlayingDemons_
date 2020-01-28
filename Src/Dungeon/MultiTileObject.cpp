//
// Created by christian.heusser on 11.12.2019.
//

#include <iostream>
#include <memory>
#include <utility>
#include <Event/EventSystem.h>
#include <Event/LineToOutputEventArgs.h>
#include "MultiTileObject.h"

sd::MultiTileObject::MultiTileObject(std::string name, const int *layout, sf::Vector2i size,
                                     sf::Vector2i position_on_tile_map, sol::function on_interaction)
    : RoomObject(std::move(name), position_on_tile_map, std::move(on_interaction))
    , size_(size)
{
    layout_ = new int[size_.x * size_.y]();
    for (int i=0; i < size_.x * size_.y; i++)
    {
        layout_[i] = layout[i];
    }
}

sd::MultiTileObject::~MultiTileObject() {
    delete layout_;
    layout_ = nullptr;
}

void sd::MultiTileObject::put_on_layout(std::vector<int>& layout, int width, int height) {

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
                layout[pos] = this->layout_[i];
            }
        }

    }

}

std::string sd::MultiTileObject::get_name() {
    return name_;
}
