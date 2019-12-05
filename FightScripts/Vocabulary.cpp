//
// Created by christian.heusser on 28.11.2019.
//

#include "Vocabulary.h"

sd::Vocabulary::Vocabulary() {

}

sd::Vocabulary::~Vocabulary() {

}

bool sd::Vocabulary::Contains(sf::String word) {
    return words.find(word) != words.end();
}

sd::Word *sd::Vocabulary::Get(sf::String word) {
    return words.at(word);
}

void sd::Vocabulary::Add(sf::String word, sd::Word* value) {
    words.insert({word, value});
}


