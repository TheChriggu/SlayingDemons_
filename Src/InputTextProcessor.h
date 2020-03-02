//
// Created by christian.heusser on 02.12.2019.
//

#ifndef _INPUTTEXTPROCESSOR_H_
#define _INPUTTEXTPROCESSOR_H_

#include "SFML/Graphics.hpp"
#include "UI/TextOutput.h"
#include "PlayerState.h"
#include "Event/Subscriber.h"
#include <regex>

namespace sd {
    class InputTextProcessor : public Subscriber {
        public:
    
        // matches a single word, ignores all leading an trailing whitespaces
        const static std::regex single_word_pattern;
        // matches single word with one whitespace at the end, ignores only leading whitespaces
        const static std::regex single_word_without_trail_pattern;
        // matches two words separated by a whitespace, ignores all leading, trailing and redundant middle whitespaces
        const static std::regex two_words_pattern;
        // deletes anything except the first word, including leading and trailing whitespaces
        const static std::regex single_word_replace_pattern;
        // deletes anything except the second word, including leading and trailing whitespaces
        const static std::regex two_words_replace_pattern;
        // deletes either leading whitespaces or the first word, if there is at least one whitespace following it
        const static std::regex autocomplete_replace_pattern;
        
    private:
        
        Sp<TextOutput> output_;
        Sp<PlayerState> player_state_;

    public:
        InputTextProcessor();
        ~InputTextProcessor() override = default;

        void set_output(Sp<TextOutput> output);
        void set_room(Sp<Room> room);

        void process_input(const std::string& spell);
        std::vector<std::string> split_by_space(std::string string);
        Sp<PlayerState> get_player_state();

        //void handle(Sp<EventArgs> e) override;
    };
}

#endif //_INPUTTEXTPROCESSOR_H_
