//
// Created by christian.heusser on 02.12.2019.
//

#ifndef _INPUTTEXTPROCESSOR_H_
#define _INPUTTEXTPROCESSOR_H_

#include "SFML/Graphics.hpp"
#include "UI/TextOutput.h"
#include "PlayerState.h"
#include "Event/Subscriber.h"

namespace sd {

    class InputTextProcessor : public Subscriber {
    private:
    //Fight* fight;
    Sp<TextOutput> output_;
    //Room* room;
    Sp<PlayerState> player_state_;

    public:
        InputTextProcessor();
        ~InputTextProcessor() override = default;

        void set_output(Sp<TextOutput> output);
        void set_room(Sp<Room> room);

        void process_input(const std::string& spell);
        std::vector<std::string> split_by_space(std::string string);
        Sp<PlayerState> get_player_state();

        void handle(Sp<EventArgs> e) override;
    };
}

#endif //_INPUTTEXTPROCESSOR_H_
