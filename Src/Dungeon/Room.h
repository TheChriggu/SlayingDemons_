//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_ROOM_H
#define SLAYINGDEMONS_ROOM_H
#include "Tilemap.h"
#include "Core/DrawableObject.h"
#include "RoomObject.h"
#include "SingleTileObject.h"
#include "MultiTileObject.h"
#include "../Monster.h"

namespace sd {
    class Room  {
    private:
        std::vector<RoomObject*> roomObjects;
        int* layout;

        Monster* enemy;

        //Tilemap* tilemap;

    public:
        Room();
        ~Room();

        sf::String GetDescription();
        int* GetLayout();

        void AddObject(RoomObject* object);
        void SetEnemy(Monster* _enemy);

        std::string GetEnterDescription();
        Monster* GetEnemy();


        RoomObject* GetObjectWithName(std::string name);

    };
}

#endif //SLAYINGDEMONS_ROOM_H
