//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#define SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#include "SFML/Graphics.hpp"
#include "Combat/Fight.h"
#include "Player.h"
#include "Monster.h"
#include "UI/TextOutput.h"
#include "Dungeon/Room.h"

namespace sd {

    class InputTextProcessor {
    private:
    Fight* fight;
    TextOutput* output;
    Room* room;

    public:
        InputTextProcessor();
        ~InputTextProcessor();

        void SetOutput(TextOutput* _output);
        void SetRoom(Room* _room);

        void ProcessInput(sf::String spell);
        std::vector<sf::String> SplitBySpace(sf::String string);
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
