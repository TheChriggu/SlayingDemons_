//
// Created by christian.heusser on 08.01.2020.
//

#ifndef SLAYINGDEMONS_SOFA_H
#define SLAYINGDEMONS_SOFA_H

#include "MultiTileObject.h"

namespace sd {
    class Sofa : public MultiTileObject{
    public:
        Sofa(std::string _name, int _layout[], sf::Vector2i _size, sf::Vector2i _positionOnTileMap);

        virtual void BeInteractedWith() override;
    };
}

#endif //SLAYINGDEMONS_SOFA_H
