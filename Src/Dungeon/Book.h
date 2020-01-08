//
// Created by christian.heusser on 08.01.2020.
//

#ifndef SLAYINGDEMONS_BOOK_H
#define SLAYINGDEMONS_BOOK_H
#include "SingleTileObject.h"

namespace sd {
    class Book : public SingleTileObject {
    public:
        Book(std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap);

        void BeInteractedWith() override;
    };
}

#endif //SLAYINGDEMONS_BOOK_H
