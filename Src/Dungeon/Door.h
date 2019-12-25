//
// Created by christian.heusser on 12.12.2019.
//

#ifndef SLAYINGDEMONS_DOOR_H
#define SLAYINGDEMONS_DOOR_H

#include "SingleTileObject.h"
#include "Room.h"

namespace sd {
    class Door : public SingleTileObject {
    private:
        bool isLocked;
        Room* nextRoom;

    public:
        Door(std::string _name, int _spriteSheetIdxOpen, int _spriteSheetIdxLocked, sf::Vector2i _positionOnTileMap, Room* _nextRoom);
        ~Door() override;

        virtual void PutOnLayout(int* layout, int width, int height) override;
        std::string GetName() override;

        Room* GetConnectedRoom();
    };
}

#endif //SLAYINGDEMONS_DOOR_H
