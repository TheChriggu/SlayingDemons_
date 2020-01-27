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
        std::vector<Sp<RoomObject>> room_objects_;
        int* layout_;

        Sp<Monster> enemy_;
        
        std::string name_;

        //Tilemap* tilemap;

    public:
        explicit Room(std::string name);
        ~Room() override;

        sf::String get_description();
        int* get_layout();

        void add_object(const Sp<RoomObject>& object);
        void set_enemy(Sp<Monster> enemy);

        virtual std::string get_enter_description();
        Sp<Monster> get_enemy();
        [[nodiscard]] const std::string& get_name() const;

        Sp<RoomObject> get_object_with_name(const std::string& name);
        void remove_object_with_name(const std::string& name);

        void handle(Sp<EventArgs> e) override;
    };
}

#endif //_ROOM_H_
