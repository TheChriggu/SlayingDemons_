//
// Created by christian.heusser on 10.12.2019.
//

#ifndef _ROOMOBJECT_H_
#define _ROOMOBJECT_H_

#include <sol/function.hpp>
#include "Tilemap.h"
#include "ScriptEngine/FunctionCollection.h"

namespace sd {
    class RoomObject {
        protected:

        std::shared_ptr<FunctionCollection> function_collection_;
    
        std::string name_;
        sf::Vector2i position_on_tile_map_;

    public:
        RoomObject(std::string name, sf::Vector2i position, std::shared_ptr<FunctionCollection> function_collection);
        virtual ~RoomObject() = default;

        virtual void put_on_layout(std::vector<int>& layout, int width, int height) = 0;
        virtual void remove_from_layout(std::vector<int>& layout, int width, int height) = 0;
        virtual std::string get_name() = 0;
        
        virtual void be_interacted_with();
        virtual void be_destroyed();

        void be_opened();

        void be_inspected();

        void be_fought();

        void be_entered();
    };
}


#endif //_ROOMOBJECT_H_
