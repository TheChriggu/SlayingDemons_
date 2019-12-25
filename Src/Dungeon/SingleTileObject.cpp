//
// Created by christian.heusser on 10.12.2019.
//

#include "SingleTileObject.h"

sd::SingleTileObject::SingleTileObject(std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap)
        :name(_name)
        ,spriteSheetIdx(_spriteSheetIdx)
        ,positionOnTileMap(_positionOnTileMap)
{
}

sd::SingleTileObject::~SingleTileObject() {

}

void sd::SingleTileObject::PutOnLayout(int *layout, int width, int height) {
    //TODO: Make sure to check position against width & height
    layout[positionOnTileMap.x + positionOnTileMap.y*width] = spriteSheetIdx;
}

std::string sd::SingleTileObject::GetName() {
    return name;
}
