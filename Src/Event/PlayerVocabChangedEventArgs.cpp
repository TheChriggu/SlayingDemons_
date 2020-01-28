//
// Created by christian.heusser on 07.01.2020.
//

#include "PlayerVocabChangedEventArgs.h"
#include <utility>

sd::PlayerVocabChangedEventArgs::PlayerVocabChangedEventArgs(Sp<sd::PlayerVocabulary> vocabulary)
    : vocabulary(std::move(vocabulary)) {
    this->type = EventArgs::Type::PLAYER_VOCAB_CHANGED;
}