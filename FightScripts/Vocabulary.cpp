//
// Created by christian.heusser on 28.11.2019.
//

#include "Vocabulary.h"

sd::Vocabulary::Vocabulary() {

}

sd::Vocabulary::~Vocabulary() {

}

bool sd::Vocabulary::Contains(sf::String word) {
    return false;
}

sd::Word *sd::Vocabulary::Get(sf::String word) {
    return nullptr;
}

void sd::Vocabulary::Add(sf::String word, sd::Word *) {

}

sd::Vocabulary* sd::Vocabulary::allWords = nullptr;
