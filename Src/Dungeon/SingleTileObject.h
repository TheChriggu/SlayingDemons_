//
// Created by christian.heusser on 10.12.2019.
//

#ifndef _SINGLETILEOBJECT_H_
#define _SINGLETILEOBJECT_H_

#include "RoomObject.h"
#include "Core/GlobalDefinitions.h"

namespace sd {
    class SingleTileObject : public RoomObject{
    protected:
        
        int sprite_sheet_idx_;

    public:
        SingleTileObject(std::string name, int sprite_sheet_idx, sf::Vector2i position_on_tile_map, Sp<FunctionCollection> function_collection);
        ~SingleTileObject() override = default;

        void put_on_layout(std::vector<int>& layout, int width, int height) override;
        void remove_from_layout(std::vector<int>& layout, int width, int height) override;
        std::string get_name() override;
    };
}

#endif //_SINGLETILEOBJECT_H_
