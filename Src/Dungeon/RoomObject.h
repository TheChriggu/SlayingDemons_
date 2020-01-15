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
        virtual std::string GetName() = 0;
        virtual void BeInteractedWith() = 0;
        virtual void BeInspected() = 0;
        virtual void BeOpened() = 0;
        virtual void BeFought() = 0;
    };
}


#endif //SLAYINGDEMONS_ROOMOBJECT_H
