//
// Created by christian.heusser on 11.12.2019.
//

#ifndef SLAYINGDEMONS_MULTITILEOBJECT_H
#define SLAYINGDEMONS_MULTITILEOBJECT_H
#include "RoomObject.h"

namespace sd {
    class MultiTileObject : public RoomObject{
    private:
        std::string name;
        sf::Vector2i positionOnTileMap;
        sf::Vector2i size;
        int* layout;

    public:
        MultiTileObject(std::string _name, int _layout[], sf::Vector2i _size, sf::Vector2i _positionOnTileMap);
        ~MultiTileObject() override;

        void PutOnLayout(int* layout, int width, int height) override;
        std::string GetName() override;
    };
}

#endif //SLAYINGDEMONS_MULTITILEOBJECT_H
