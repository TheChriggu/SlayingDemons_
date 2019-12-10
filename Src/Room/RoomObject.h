//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_ROOMOBJECT_H
#define SLAYINGDEMONS_ROOMOBJECT_H
#include "Tilemap.h"

namespace sd {
    class RoomObject {

    public:
        RoomObject();
        ~RoomObject();

        void PutOnTileMap(Tilemap* map);

    };
}


#endif //SLAYINGDEMONS_ROOMOBJECT_H
