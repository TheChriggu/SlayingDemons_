//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#define SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#include "SFML/Graphics.hpp"
#include "FightScripts/Fight.h"
#include "FightScripts/Player.h"
#include "FightScripts/Monster.h"
#include "TextOutput.h"

namespace sd {

    class InputTextProcessor {
    private:
    Fight* fight;
    TextOutput* output;
    //std::vector<sf::String> SplitBySpace(sf::String string);

    public:
        InputTextProcessor();
        ~InputTextProcessor();

        void SetOutput(TextOutput* _output);

        void ProcessInput(sf::String spell);
        std::vector<sf::String> SplitBySpace(sf::String string);
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
