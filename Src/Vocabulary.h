//
// Created by christian.heusser on 28.11.2019.
//

#ifndef _VOCABULARY_H_
#define _VOCABULARY_H_

#include <map>
#include "Core/GlobalDefinitions.h"
#include "SFML/Graphics.hpp"
#include "Word.h"

namespace sd {
    class Vocabulary {
    private:
        std::map<sf::String, Sp<Word>> words_;

    public:
        Vocabulary() = default;
        virtual ~Vocabulary() = default;

        bool contains(const std::string& word);
        Sp<Word> get(const std::string& word);
        void add(const std::string& word, const Sp<Word>& value);

        static Sp<Vocabulary> all_words;
    };
}

#endif //_VOCABULARY_H_
