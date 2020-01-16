//
// Created by christian.heusser on 28.11.2019.
//

#ifndef SLAYINGDEMONS_VOCABULARY_H
#define SLAYINGDEMONS_VOCABULARY_H

#include <map>
#include "SFML/Graphics.hpp"
#include "Word.h"

namespace sd {
    class Vocabulary {
    private:
        std::map<sf::String, Word*> words;

    public:
        Vocabulary();
        ~Vocabulary();

        bool Contains(sf::String word);
        Word* Get(sf::String word);
        void Add(sf::String word, Word* );

        static Vocabulary* all_words;
    };
}

#endif //SLAYINGDEMONS_VOCABULARY_H
