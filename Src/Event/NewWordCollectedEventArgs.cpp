//
// Created by christian.heusser on 07.01.2020.
//

#include "NewWordCollectedEventArgs.h"

sd::NewWordCollectedEventArgs::NewWordCollectedEventArgs(const std::string& word)
    : word(word) {
    this->type = EventArgs::Type::NEW_WORD_COLLECTED;
}
