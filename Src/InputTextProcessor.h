//
// Created by christian.heusser on 02.12.2019.
//

#ifndef SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
#define SLAYINGDEMONS_INPUTTEXTPROCESSOR_H

#include "SFML/Graphics.hpp"
#include "UI/TextOutput.h"
#include "PlayerState.h"
#include "Event/Subscriber.h"

namespace sd {

    class InputTextProcessor : public Subscriber {
    private:
    //Fight* fight;
    Sp<TextOutput> output;
    //Room* room;
    Sp<PlayerState> playerState;

    public:
        InputTextProcessor();
        ~InputTextProcessor() override = default;

        void SetOutput(Sp<TextOutput> _output);
        void SetRoom(Sp<Room> _room);

        void ProcessInput(sf::String spell);
        std::vector<std::string> SplitBySpace(std::string string);
        Sp<PlayerState> GetPlayerState();

        void handle(Sp<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
