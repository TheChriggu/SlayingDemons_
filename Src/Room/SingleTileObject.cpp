//
// Created by christian.heusser on 10.12.2019.
//

#include "SingleTileObject.h"

sd::SingleTileObject::SingleTileObject(sf::String _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap)
        :name(_name)
        ,spriteSheetIdx(_spriteSheetIdx)
        ,positionOnTileMap(_positionOnTileMap)
{
}

sd::SingleTileObject::~SingleTileObject() {

}

void sd::SingleTileObject::PutOnTileMap(Tilemap *map) {
    int* layout = map->GetLayout();

    layout[positionOnTileMap.x + positionOnTileMap.y*map->GetWidth()] = spriteSheetIdx;

    map->SetLayout(layout, map->GetWidth()*map->GetHeight());
}

sf::String sd::SingleTileObject::GetName() {
    return name;
}
