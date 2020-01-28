//
// Created by christian.heusser on 25.11.2019.
//

#include <iostream>
#include "Tilemap.h"

Tilemap::Tilemap(unsigned int width, unsigned int height, sf::Vector2f position, sf::Vector2u tile_size)
    : width_(width)
    , height_(height)
    , tile_size_(tile_size)
{
    std::cout << "Start contructor Tilemap\n";
    //layout_ = new int[width_ * height_];
    layout_ = std::vector<int>(width_ * height_);
    position_ = position;

    // resize the vertex array to fit the level size
    vertices_.setPrimitiveType(sf::Quads);
    vertices_.resize(width_ * height_ * 4);
    
    
    std::vector<int> default_layout = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    load_sprite_sheet("../Resources/Sprites/fantasy_tilemap.png");
    set_layout(default_layout, width_ * height_);
    set_all_quad_positions();
    std::cout << "End contructor Tilemap\n";
}


void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset_;

    // draw the vertex array
    target.draw(vertices_, states);
}

std::vector<int>& Tilemap::get_layout() {
    return layout_;
}

void Tilemap::load_sprite_sheet(const std::string& path) {
    // load the tileset texture
    if (!tileset_.loadFromFile(path)) {
        //error
    }
    
    update_tiles();

}

void Tilemap::set_layout(std::vector<int>& layout, int size) {
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

void Tilemap::set_all_quad_positions() {
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

void Tilemap::update_tiles() {
    for (unsigned int i = 0; i < width_; ++i)
    {
        for (unsigned int j = 0; j < height_; ++j)
        {
            // get the current tile number
            int tile_number = layout_[i + j * width_];

            // find its position in the tileset texture
            int tu = tile_number % (tileset_.getSize().x / (tile_size_.x));
            int tv = tile_number / (tileset_.getSize().x / (tile_size_.x));

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices_[(i + j * width_) * 4];

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * (tile_size_.x), tv * (tile_size_.y));
            quad[1].texCoords = sf::Vector2f((tu + 1) * tile_size_.x, tv * tile_size_.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tile_size_.x, (tv + 1) * tile_size_.y);
            quad[3].texCoords = sf::Vector2f(tu * tile_size_.x, (tv + 1) * tile_size_.y);
        }
    }
}

int Tilemap::get_width() {
    return width_;
}

int Tilemap::get_height() {
    return height_;
}


#include "Tilemap.h"
