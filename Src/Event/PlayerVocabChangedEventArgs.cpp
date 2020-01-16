//
// Created by christian.heusser on 07.01.2020.
//

#include "PlayerVocabChangedEventArgs.h"

sd::PlayerVocabChangedEventArgs::PlayerVocabChangedEventArgs(sd::PlayerVocabulary *_vocabulary) {
    this->type = EventArgs::Type::PLAYER_VOCAB_CHANGED;
    this->vocabulary = _vocabulary;
}