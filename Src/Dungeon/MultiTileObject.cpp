//
// Created by christian.heusser on 11.12.2019.
//

#include <iostream>
#include "MultiTileObject.h"

sd::MultiTileObject::MultiTileObject(std::string _name, int *_layout, sf::Vector2i _size,
                                     sf::Vector2i _positionOnTileMap)
    :name(_name)
    ,size(_size)
    ,positionOnTileMap(_positionOnTileMap)
{
    layout = new int[size.x*size.y]();
    for (int i=0; i < size.x*size.y; i++)
    {
        layout[i] = _layout[i];
    }
}

sd::MultiTileObject::~MultiTileObject() {
    delete layout;
    layout = nullptr;
}

void sd::MultiTileObject::PutOnLayout(int *layout, int width, int height) {

    if((width < positionOnTileMap.x + size.x) || (height < positionOnTileMap.y + size.y))
    {
        std::cout << "MultiTileObject outside Room";
    }
    else
    {
        int startPos = positionOnTileMap.x + positionOnTileMap.y*width;

        for(int i = 0; i < size.x * size.y;i++)
        {
            int row = i/size.x;
            int col = i%size.x;

            int pos = startPos+col+row*width;

            if(this->layout[i] != -1)
            {
                layout[pos] = this->layout[i];
            }
        }

    }

}

std::string sd::MultiTileObject::GetName() {
    return name;
}

void sd::MultiTileObject::BeInteractedWith() {
    //yeah... whats here?
}
