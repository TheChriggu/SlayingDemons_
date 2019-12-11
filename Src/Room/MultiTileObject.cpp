//
// Created by christian.heusser on 11.12.2019.
//

#include <iostream>
#include "MultiTileObject.h"

sd::MultiTileObject::MultiTileObject(sf::String _name, int *_layout, sf::Vector2i _size,
                                     sf::Vector2i _positionOnTileMap)
    :name(_name)
    ,size(_size)
    ,positionOnTileMap(_positionOnTileMap)
{
    layout = new int[size.x*size.y];
    for (int i=0; i < size.x*size.y; i++)
    {
        layout[i] = _layout[i];
    }
}

sd::MultiTileObject::~MultiTileObject() {
    delete layout;
    layout = nullptr;
}

void sd::MultiTileObject::PutOnTileMap(Tilemap *map) {

    if((map->GetWidth() < positionOnTileMap.x + size.x) || (map->GetHeight() < positionOnTileMap.y + size.y))
    {
        std::cout << "MultiTileObject outside Room";
    }
    else
    {
        int startPos = positionOnTileMap.x + positionOnTileMap.y*map->GetWidth();
        int* mapLayout = map->GetLayout();
        for(int i = 0; i < size.x * size.y;i++)
        {
            int row = i/size.x;
            int col = i%size.x;

            int pos = startPos+col+row*map->GetWidth();

            if(layout[i] != -1)
            {
                mapLayout[pos] = layout[i];
            }
        }
        map->SetLayout(mapLayout, map->GetWidth()*map->GetHeight());
    }

}

sf::String sd::MultiTileObject::GetName() {
    return name;
}
