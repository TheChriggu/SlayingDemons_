//
// Created by christian.heusser on 25.11.2019.
//

#include <iostream>
#include "Tilemap.h"
#include "Event/SetStageEventArgs.h"
#include <Event/EventSystem.h>

sd::Tilemap::Tilemap(unsigned int width, unsigned int height, sf::Vector2f position, sf::Vector2u tile_size)
    : width_(width)
    , height_(height)
    , tile_size_(tile_size)
{
    std::cout << "Start constructor Tilemap\n";
    //layout_ = new int[width_ * height_];
    layout_ = std::vector<TileData>(width_ * height_);
    position_ = position;

    // resize the vertex array to fit the level size
    vertices_.setPrimitiveType(sf::Quads);
    vertices_.resize(width_ * height_ * 4);
    
    
    std::vector<TileData> default_layout = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
    load_sprite_sheet("../Resources/Sprites/Progressing/spritesheet_0.png");
    set_layout(default_layout, width_ * height_);
    set_all_quad_positions();
    std::cout << "End constructor Tilemap\n";

    event_handler_ = CREATE_EVENT_HANDLER(
    if (e->type == EventArgs::Type::SET_STAGE) {
                auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
                auto path = "../Resources/Sprites/Progressing/spritesheet_" + std::to_string(arg->stage) + ".png";
                load_sprite_sheet(path);
            }
            );

    REGISTER_EVENT_HANDLER();
}


void sd::Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset_;

    // draw the vertex array
    target.draw(vertices_, states);
}

std::vector<sd::TileData>& sd::Tilemap::get_layout() {
    return layout_;
}

void sd::Tilemap::load_sprite_sheet(const std::string& path) {
    // load the tileset texture
    if (!tileset_.loadFromFile(path)) {
        //error
    }
    
    update_tiles();

}

void sd::Tilemap::set_layout(std::vector<TileData>& layout, int size) {
    if(width_ * height_ == size)
    {
        for (int i=0; i< size; i++)
        {
            layout_[i] = layout[i];
        }
    
        update_tiles();
    }
    else
    {
        std::cout << "new tile layout has different size\n";
    }
}

void sd::Tilemap::set_all_quad_positions() {
    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width_; ++i) {
        for (unsigned int j = 0; j < height_; ++j) {

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices_[(i + j * width_) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * (tile_size_.x), j * (tile_size_.y)) + position_;
            quad[1].position = sf::Vector2f((i + 1) * (tile_size_.x), j * (tile_size_.y)) + position_;
            quad[2].position = sf::Vector2f((i + 1) * (tile_size_.x), (j + 1) * (tile_size_.y)) + position_;
            quad[3].position = sf::Vector2f(i * (tile_size_.x), (j + 1) * (tile_size_.y)) + position_;
        }
    }
}

void sd::Tilemap::update_tiles() {
    for (unsigned int i = 0; i < width_; ++i)
    {
        for (unsigned int j = 0; j < height_; ++j)
        {
            // get the current tile number
            int tile_number = layout_[i + j * width_].tile_idx_;

            // find its position in the tileset texture
            int tu = tile_number % (tileset_.getSize().x / (tile_size_.x));
            int tv = tile_number / (tileset_.getSize().x / (tile_size_.x));

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices_[(i + j * width_) * 4];


            // define its 4 texture coordinates
            int rotation = layout_[i + j * width_].rotation_;

            quad[rotation%4].texCoords = sf::Vector2f(tu * (tile_size_.x), tv * (tile_size_.y));
            quad[(rotation+1)%4].texCoords = sf::Vector2f((tu + 1) * tile_size_.x, tv * tile_size_.y);
            quad[(rotation+2)%4].texCoords = sf::Vector2f((tu + 1) * tile_size_.x, (tv + 1) * tile_size_.y);
            quad[(rotation+3)%4].texCoords = sf::Vector2f(tu * tile_size_.x, (tv + 1) * tile_size_.y);



        }
    }
}

int sd::Tilemap::get_width() {
    return width_;
}

int sd::Tilemap::get_height() {
    return height_;
}


