//
// Created by christian.heusser on 12.12.2019.
//

#include "Door.h"

sd::Door::Door(std::string _name,
               int _spriteSheetIdxOpen, int _spriteSheetIdxLocked, sf::Vector2i _positionOnTileMap, Room* _nextRoom)
        : SingleTileObject(_name, _spriteSheetIdxOpen, _positionOnTileMap)
        , nextRoom(_nextRoom)
{}

sd::Room *sd::Door::GetConnectedRoom() {
    return nextRoom;
}

sd::Door::~Door() {

}

void sd::Door::PutOnLayout(int *layout, int width, int height) {
    //TODO: make sure position is within width & height
    SingleTileObject::PutOnLayout(layout, width, height);
}

std::string sd::Door::GetName() {
    return SingleTileObject::GetName();
}
