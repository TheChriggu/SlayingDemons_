//
// Created by christian.heusser on 25.11.2019.
//

#include <iostream>
#include "Tilemap.h"

Tilemap::Tilemap(unsigned int _width, unsigned int _height, sf::Vector2f _position, sf::Vector2u _tileSize)
    :width(_width)
    ,height(_height)
    ,tileSize(_tileSize)
{
    layout = new int[width*height];
    position = _position;

    // resize the vertex array to fit the level size
    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);


    int defaultLayout[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    LoadSpriteSheet("../Resources/Sprites/fantasy_tilemap.png");
    SetLayout(defaultLayout, width*height);
    SetAllQuadPositions();

}

Tilemap::~Tilemap() {
    delete layout;
    layout = nullptr;
}


void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &tileset;

    // draw the vertex array
    target.draw(vertices, states);
}

int *Tilemap::GetLayout() {
    return layout;
}

void Tilemap::LoadSpriteSheet(sf::String path) {
    // load the tileset texture
    if (!tileset.loadFromFile(path)) {
        //error
    }

    UpdateTiles();

}

void Tilemap::SetLayout(int _layout[], int size) {
    if(width*height == size)
    {
        for (int i=0; i< size; i++)
        {
            layout[i] = _layout[i];
        }

        UpdateTiles();
    }
    else
    {
        std::cout << "new tile layout has different size\n";
    }
}

void Tilemap::SetAllQuadPositions() {
    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * (tileSize.x), j * (tileSize.y)) + position;
            quad[1].position = sf::Vector2f((i + 1) * (tileSize.x), j * (tileSize.y)) + position;
            quad[2].position = sf::Vector2f((i + 1) * (tileSize.x), (j + 1) * (tileSize.y)) + position;
            quad[3].position = sf::Vector2f(i * (tileSize.x), (j + 1) * (tileSize.y)) + position;
        }
    }
}

void Tilemap::UpdateTiles() {
    for (unsigned int i = 0; i < width; ++i)
    {
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = layout[i + j * width];

            // find its position in the tileset texture
            int tu = tileNumber % (tileset.getSize().x / (tileSize.x));
            int tv = tileNumber / (tileset.getSize().x / (tileSize.x));

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &vertices[(i + j * width) * 4];

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * (tileSize.x), tv * (tileSize.y));
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }
    }
}


#include "Tilemap.h"
