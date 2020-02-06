//
// Created by christian.heusser on 10.12.2019.
//

#ifndef _ROOMOBJECT_H_
#define _ROOMOBJECT_H_

#include <sol/function.hpp>
#include "Tilemap.h"

namespace sd {
    class RoomObject {
        protected:
        
        sol::function be_interacted_with_signal_;
        sol::function be_opened_signal_;
        sol::function be_inspected_signal_;
        sol::function be_fought_signal_;
        sol::function be_entered_signal_;
        sol::function on_destroyed_signal_;
    
        std::string name_;
        sf::Vector2i position_on_tile_map_;

    public:
        RoomObject(std::string name, sf::Vector2i position, sol::function be_interacted_with_signal,
                sol::function be_opened_signal, sol::function be_inspected_signal,
                sol::function be_fought_signal,  sol::function be_entered_signal);
        virtual ~RoomObject() = default;

        virtual void put_on_layout(std::vector<int>& layout, int width, int height) = 0;
        virtual std::string get_name() = 0;
        
        virtual void be_interacted_with();
        virtual void on_destroyed();

        void be_opened();

        void be_inspected();

        void be_fought();

        void be_entered();
    };
}


#endif //_ROOMOBJECT_H_
