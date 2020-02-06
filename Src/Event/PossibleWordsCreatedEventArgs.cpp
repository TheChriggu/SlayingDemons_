//
// Created by felix on 06.02.20.
//

#include "PossibleWordsCreatedEventArgs.h"
sd::PossibleWordsCreatedEventArgs::PossibleWordsCreatedEventArgs(sd::PossibleWords *possible_words)
    : possible_words(possible_words)
{
    type = EventArgs::Type::POSSIBLE_WORDS_CREATED;
}
