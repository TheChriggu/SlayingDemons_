//
// Created by christian.heusser on 07.01.2020.
//

#include "NewWordCollectedEventArgs.h"

sd::NewWordCollectedEventArgs::NewWordCollectedEventArgs(std::string _word) {
    this->type = EventArgs::Type::NEW_WORD_COLLECTED;
    this->word = _word;
}
