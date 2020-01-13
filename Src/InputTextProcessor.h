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
    sp<TextOutput> output;
    //Room* room;
    sp<PlayerState> playerState;

    public:
        InputTextProcessor();
        ~InputTextProcessor() override = default;

        void SetOutput(sp<TextOutput> _output);
        void SetRoom(sp<Room> _room);

        void ProcessInput(sf::String spell);
        std::vector<std::string> SplitBySpace(std::string string);
        sp<PlayerState> GetPlayerState();

        void Handle(sp<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
