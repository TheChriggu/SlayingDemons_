//
// Created by christian.heusser on 10.12.2019.
//

#ifndef _ROOM_H_
#define _ROOM_H_
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
        
        std::string name_;

        //Tilemap* tilemap;

    public:
        Room(std::string name);
        ~Room();

        // TODO(FK): slightly embarrassing temp variable
        bool is_last = false;

        sf::String GetDescription();
        int* GetLayout();

        void AddObject(RoomObject* object);
        void SetEnemy(Monster* _enemy);

        virtual std::string GetEnterDescription();
        Monster* GetEnemy();
        const std::string& get_name() const;

        RoomObject* GetObjectWithName(std::string name);
        void RemoveObjectWithName(std::string name);

        void handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //_ROOM_H_
