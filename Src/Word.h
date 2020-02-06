//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _WORD_H_
#define _WORD_H_

namespace sd {
    class Word {
    public:
        enum Type {ACTION, MODIFIER, COMMAND, UNKNOWN};
        //TODO: I honestly don't know what all words of the game have in common -.- Maybe Stats.
        virtual ~Word() = default;

        virtual Type get_type();
    };
}

#endif //_WORD_H_
