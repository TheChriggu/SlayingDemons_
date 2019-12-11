//
// Created by christian.heusser on 11.12.2019.
//

#ifndef SLAYINGDEMONS_MULTITILEOBJECT_H
#define SLAYINGDEMONS_MULTITILEOBJECT_H
#include "RoomObject.h"

namespace sd {
    class MultiTileObject : public RoomObject{
    private:
        sf::String name;
        sf::Vector2i positionOnTileMap;
        sf::Vector2i size;
        int* layout;

    public:
        MultiTileObject(sf::String _name, int _layout[], sf::Vector2i _size, sf::Vector2i _positionOnTileMap);
        ~MultiTileObject() override;

        void PutOnTileMap(Tilemap* map) override;
        sf::String GetName() override;
    };
}

#endif //SLAYINGDEMONS_MULTITILEOBJECT_H
