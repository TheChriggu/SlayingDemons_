//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_SINGLETILEOBJECT_H
#define SLAYINGDEMONS_SINGLETILEOBJECT_H
#include "RoomObject.h"


namespace sd {
    class SingleTileObject : RoomObject{
    private:
        int spriteSheetIdx;
        sf::String name;
        sf::Vector2i positionOnTileMap;

    public:
        SingleTileObject(sf::String _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap);
        ~SingleTileObject();

        virtual void PutOnTileMap(Tilemap* map);
    };
}

#endif //SLAYINGDEMONS_SINGLETILEOBJECT_H
