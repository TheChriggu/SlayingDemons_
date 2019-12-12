//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_SINGLETILEOBJECT_H
#define SLAYINGDEMONS_SINGLETILEOBJECT_H
#include "RoomObject.h"


namespace sd {
    class SingleTileObject : public RoomObject{
    protected:
        int spriteSheetIdx;
        sf::String name;
        sf::Vector2i positionOnTileMap;

    public:
        SingleTileObject(sf::String _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap);
        ~SingleTileObject() override;

        virtual void PutOnTileMap(Tilemap* map) override;
        sf::String GetName() override;
    };
}

#endif //SLAYINGDEMONS_SINGLETILEOBJECT_H
