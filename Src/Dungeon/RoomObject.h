//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_ROOMOBJECT_H
#define SLAYINGDEMONS_ROOMOBJECT_H
#include "Tilemap.h"

namespace sd {
    class RoomObject {

    public:
        RoomObject() = default;
        virtual ~RoomObject() = default;

        virtual void PutOnLayout(int* layout, int width, int height) = 0;
        virtual sf::String GetName() = 0;
    };
}


#endif //SLAYINGDEMONS_ROOMOBJECT_H
