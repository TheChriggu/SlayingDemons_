//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _PLAYERVOCABCHANGEDEVENTARGS_H_
#define _PLAYERVOCABCHANGEDEVENTARGS_H_

#include <PlayerVocabulary.h>
#include "EventArgs.h"

namespace sd {
    class PlayerVocabChangedEventArgs : public EventArgs {
    public:
        explicit PlayerVocabChangedEventArgs(Sp<PlayerVocabulary> vocabulary);
        ~PlayerVocabChangedEventArgs() override = default;

        Sp<PlayerVocabulary> vocabulary;
    };
}

#endif //_PLAYERVOCABCHANGEDEVENTARGS_H_
