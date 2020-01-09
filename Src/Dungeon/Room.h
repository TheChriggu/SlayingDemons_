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
#include "../Event/Subscriber.h"

namespace sd {
    class Room : public Subscriber{
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


        void Handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_ROOM_H
