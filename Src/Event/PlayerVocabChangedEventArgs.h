//
// Created by christian.heusser on 07.01.2020.
//

#ifndef SLAYINGDEMONS_PLAYERVOCABCHANGEDEVENTARGS_H
#define SLAYINGDEMONS_PLAYERVOCABCHANGEDEVENTARGS_H

#include <PlayerVocabulary.h>
#include "EventArgs.h"

namespace sd {
    class PlayerVocabChangedEventArgs : public EventArgs {
    public:
        explicit PlayerVocabChangedEventArgs(PlayerVocabulary* _vocabulary);

        PlayerVocabulary* vocabulary;
    };
}

#endif //SLAYINGDEMONS_PLAYERVOCABCHANGEDEVENTARGS_H
