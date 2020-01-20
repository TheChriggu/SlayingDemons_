//
// Created by christian.heusser on 11.12.2019.
//

#ifndef _MULTITILEOBJECT_H_
#define _MULTITILEOBJECT_H_

#include "RoomObject.h"

namespace sd {
    class MultiTileObject : public RoomObject{
    private:
        
        sf::Vector2i size_;
        int* layout_;

    public:
        MultiTileObject(std::string name, const int layout[], sf::Vector2i size, sf::Vector2i position_on_tile_map, sol::function on_interaction);
        ~MultiTileObject() override;

        void put_on_layout(int* layout, int width, int height) override;
        std::string get_name() override;
        //virtual void be_interacted_with() override;
    };
}

#endif //_MULTITILEOBJECT_H_
