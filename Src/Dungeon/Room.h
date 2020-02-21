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
#include "TileData.h"

namespace sd {
    class Room : public Subscriber{
    private:
        std::vector<Sp<RoomObject>> room_objects_;
        std::vector<TileData> layout_;

        Sp<Monster> enemy_;
        
        std::string name_;


    public:
        explicit Room(std::string name, const std::vector<sf::Vector2i>& corners);
        ~Room() override;

        std::string get_description();
        [[nodiscard]] std::vector<std::string> get_all_objects() const;
        std::vector<TileData>& get_layout();

        void add_object(const Sp<RoomObject>& object);
        void set_enemy(Sp<Monster> enemy);

        virtual std::string get_enter_description();
        Sp<Monster> get_enemy();
        [[nodiscard]] const std::string& get_name() const;

        Sp<RoomObject> get_object_with_name(const std::string& name);
        void remove_object_with_name(const std::string& name);

    private:
        void generate_wall_layout_from_corners(const std::vector<sf::Vector2i>& corners);
        void set_corner_orientation(sf::Vector2i previous_corner, sf::Vector2i current_corner, sf::Vector2i next_corner);
        void build_wall_from_current_to_next(sf::Vector2i current_corner, sf::Vector2i next_corner);
    };
}

#endif //_ROOM_H_
