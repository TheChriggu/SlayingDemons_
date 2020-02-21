//
// Created by felix on 06.02.20.
//

#ifndef _POSSIBLEWORDSCREATEDEVENTARGS_H_
#define _POSSIBLEWORDSCREATEDEVENTARGS_H_

#include "EventArgs.h"
#include "UI/PossibleWords.h"

namespace sd {
    class PossibleWordsCreatedEventArgs : public EventArgs {
        public:
        explicit PossibleWordsCreatedEventArgs(Sp<PossibleWords> possible_words);
        ~PossibleWordsCreatedEventArgs() override = default;
        
        Sp<PossibleWords> possible_words;
    };
}

#endif //_POSSIBLEWORDSCREATEDEVENTARGS_H_
