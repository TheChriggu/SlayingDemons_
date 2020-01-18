//
// Created by christian.heusser on 12.12.2019.
//

#ifndef _DOOR_H_
#define _DOOR_H_

#include "SingleTileObject.h"
#include "Room.h"

namespace sd {
    class Door : public SingleTileObject {
    private:
        bool isLocked;
        std::string nextRoom;
        int spriteSheetIdxOpen;
        int spriteSheetIdxLocked;

    public:
        Door(std::string _name, int _spriteSheetIdxOpen, int _spriteSheetIdxLocked, sf::Vector2i _positionOnTileMap, std::string _nextRoom);
        ~Door() override;

        virtual void PutOnLayout(int* layout, int width, int height) override;
        std::string GetName() override;
        void BeInteractedWith() override;

        void SetLocked(bool lockState);

        const std::string& GetConnectedRoom() const;
    };
}

#endif //_DOOR_H_
