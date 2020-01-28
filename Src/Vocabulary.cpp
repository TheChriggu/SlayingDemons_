//
// Created by christian.heusser on 28.11.2019.
//

#include "Vocabulary.h"

Sp<sd::Vocabulary> sd::Vocabulary::all_words = nullptr;

bool sd::Vocabulary::contains(const std::string& word) {
    return words_.find(word) != words_.end();
}

Sp<sd::Word> sd::Vocabulary::get(const std::string& word) {
    return words_.at(word);
}

void sd::Vocabulary::add(const std::string& word, const Sp<sd::Word>& value) {
    words_.insert({word, value});
}


