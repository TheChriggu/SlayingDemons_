//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#define SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#include "SFML/Graphics.hpp"
#include "UI/TextOutput.h"
#include "PlayerState.h"

namespace sd {

    class InputTextProcessor {
    private:
    //Fight* fight;
    TextOutput* output;
    //Room* room;
    PlayerState* playerState;

    public:
        InputTextProcessor();
        ~InputTextProcessor();

        void SetOutput(TextOutput* _output);
        void SetRoom(Room* _room);

        void ProcessInput(sf::String spell);
        std::vector<sf::String> SplitBySpace(sf::String string);
        PlayerState* GetPlayerState();
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
