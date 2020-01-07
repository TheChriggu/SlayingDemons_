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
    TextOutput* output;
    //Room* room;
    PlayerState* playerState;

    public:
        InputTextProcessor();
        ~InputTextProcessor() override;

        void SetOutput(TextOutput* _output);
        void SetRoom(Room* _room);

        void ProcessInput(sf::String spell);
        std::vector<std::string> SplitBySpace(std::string string);
        PlayerState* GetPlayerState();

        void Handle(std::shared_ptr<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_INPUTTEXTPROCESSOR_H
