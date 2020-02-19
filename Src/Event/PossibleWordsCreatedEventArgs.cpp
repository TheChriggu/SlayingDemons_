//
// Created by felix on 06.02.20.
//

#include "PossibleWordsCreatedEventArgs.h"
#include <utility>

sd::PossibleWordsCreatedEventArgs::PossibleWordsCreatedEventArgs(Sp<sd::PossibleWords> possible_words)
    : possible_words(std::move(possible_words))
{
    type = EventArgs::Type::POSSIBLE_WORDS_CREATED;
}
