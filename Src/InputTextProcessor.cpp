//
// Created by christian.heusser on 02.12.2019.
//

#include "InputTextProcessor.h"
#include <iostream>
#include <memory>
#include <utility>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>

sd::InputTextProcessor::InputTextProcessor() : Subscriber() {

}

void sd::InputTextProcessor::process_input(const std::string& spell) {

        //split spell
        std::vector<std::string> words = split_by_space(spell);

        //check if currently fighting
        if(player_state_->is_fighting())
        {
            if(player_state_->get_player_vocabulary()->has_word(words[0]) && player_state_->get_player_vocabulary()->has_word(words[1]))
            {
                auto word_1 = Vocabulary::all_words->get(words[0]);
                auto word_2 = Vocabulary::all_words->get(words[1]);
                if(word_1->get_type() == sd::Word::Type::MODIFIER && word_2->get_type() == sd::Word::Type::ACTION)
                //make turn in fight
                    player_state_->get_fight ()->full_turn (words[1], words[0]);
            }

            else
            {
                output_->add_line ("You are currently in combat, you should probably use some combat spells you know of.");
            }
        }

        else if(words[0] == "Inspect")
        {
            if(words[1] == "Room")
            {
                output_->add_line (player_state_->get_current_room()->get_description());
            }
            else
                {
                auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

                if(object)
                {
                    object->be_inspected();
                }
                else
                {
                    std::shared_ptr<LineToOutputEventArgs> args;
                    args = std::make_shared<LineToOutputEventArgs>("Could not find object in room.");
                    EventSystem::get().trigger(args);
                }
            }

        }

        else if(words[0] == "Interact")
        {
            auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

            if(object)
            {
                object->be_interacted_with();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>("Could not find object in room.");
                EventSystem::get().trigger(args);
            }
        }

        else if(words[0] == "Open")
        {
            auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

            if(object)
            {
                object->be_opened();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>("Could not find object in room.");
                EventSystem::get().trigger(args);
            }
        }
        else if(words[0] == "Fight")
        {
            auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

            if(object)
            {
                object->be_fought();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>("Could not find object in room.");
                EventSystem::get().trigger(args);
            }
        }
        else if(words[0] == "Enter")
        {
            auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

            if(object)
            {
                object->be_entered();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>("Could not find object in room.");
                EventSystem::get().trigger(args);
            }
        }

        else
        {
            output_->add_line ("nothing happens");
        }

}

std::vector<std::string> sd::InputTextProcessor::split_by_space(std::string string) {
    std::vector<std::string> ret_val;
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = string.find(delimiter)) != std::string::npos) {
        token = string.substr(0, pos);

        ret_val.emplace_back(token);
        string.erase(0, pos + delimiter.size());
    }
    ret_val.emplace_back(string);

    return ret_val;
}

void sd::InputTextProcessor::set_output(Sp<sd::TextOutput> output) {
    output_ = std::move(output);
}

void sd::InputTextProcessor::set_room(Sp<sd::Room> room) {
    player_state_->set_current_room(std::move(room));
}

Sp<sd::PlayerState> sd::InputTextProcessor::get_player_state() {
    return player_state_;
}

void sd::InputTextProcessor::handle(std::shared_ptr<sd::EventArgs> e) {
    if (e->type == EventArgs::Type::TEXT_OUTPUT_CREATED) {
        auto arg = dynamic_cast<TextOutputCreatedEventArgs*>(e.get());
        output_ = Sp<TextOutput>(arg->output);
    }
    
    if (e->type == EventArgs::Type::PLAYER_STATE_CREATED) {
        auto arg = std::dynamic_pointer_cast<PlayerStateCreatedEventArgs>(e);
        
        player_state_ = Sp<PlayerState>(arg->player_state);
    }
}


