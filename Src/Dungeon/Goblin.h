//
// Created by christian.heusser on 09.01.2020.
//

#ifndef SLAYINGDEMONS_GOBLIN_H
#define SLAYINGDEMONS_GOBLIN_H

#include <PlayerVocabulary.h>
#include "SingleTileObject.h"

namespace sd {
    class Goblin : public SingleTileObject {
    private:
        PlayerVocabulary* vocab;

    public:
            Goblin (std::string _name, int _spriteSheetIdx, sf::Vector2i _positionOnTileMap);

            void be_interacted_with() override;

            void SetPlayerVocab(PlayerVocabulary* _vocab);
    };
}

#endif //SLAYINGDEMONS_GOBLIN_H
