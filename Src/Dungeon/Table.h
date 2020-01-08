//
// Created by christian.heusser on 08.01.2020.
//

#ifndef SLAYINGDEMONS_TABLE_H
#define SLAYINGDEMONS_TABLE_H
#include "MultiTileObject.h"

namespace sd {
    class Table : public MultiTileObject {
    public:
        Table(std::string _name, int _layout[], sf::Vector2i _size, sf::Vector2i _positionOnTileMap);

        virtual void BeInteractedWith() override;
    };
}


#endif //SLAYINGDEMONS_TABLE_H
