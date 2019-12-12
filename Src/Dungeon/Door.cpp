//
// Created by christian.heusser on 12.12.2019.
//

#include "Door.h"

sd::Door::Door(sf::String _name,
               int _spriteSheetIdxOpen, int _spriteSheetIdxLocked, sf::Vector2i _positionOnTileMap, Room* _nextRoom)
        : SingleTileObject(_name, _spriteSheetIdxOpen, _positionOnTileMap)
        , nextRoom(_nextRoom)
{}

sd::Room *sd::Door::GetConnectedRoom() {
    return nextRoom;
}

sd::Door::~Door() {

}

void sd::Door::PutOnTileMap(Tilemap *map) {
    SingleTileObject::PutOnTileMap(map);
}

sf::String sd::Door::GetName() {
    return SingleTileObject::GetName();
}
