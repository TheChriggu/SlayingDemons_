//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_ROOM_H
#define SLAYINGDEMONS_ROOM_H
#include "Tilemap.h"
#include "../Core/DrawableObject.h"
#include "RoomObject.h"
#include "SingleTileObject.h"
#include "MultiTileObject.h"

namespace sd {
    class Room  {
    private:
        sf::Vector2f position;
        sf::Vector2f size;

        std::vector<RoomObject*> roomObjects;

        Tilemap* tilemap;

    public:
        Room(Tilemap* _tilemap);
        ~Room();

        sf::String GetDescription();
        Tilemap* GetTilemap();

        void AddObject(RoomObject* object);

    };
}

#endif //SLAYINGDEMONS_ROOM_H
