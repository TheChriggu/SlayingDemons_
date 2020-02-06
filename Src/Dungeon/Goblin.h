//
// Created by christian.heusser on 09.01.2020.
//

#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include <PlayerVocabulary.h>
#include "SingleTileObject.h"

namespace sd {
    class Goblin : public SingleTileObject {
    private:
        Sp<PlayerVocabulary> vocab_;

    public:
            //Goblin (std::string name, int sprite_sheet_idx, sf::Vector2i position_on_tile_map);

            //void be_interacted_with() override;

            //void set_player_vocab(Sp<PlayerVocabulary> vocab);
    };
}

#endif //_GOBLIN_H_
