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
    player_state_ = std::make_shared<PlayerState>();
    std::cout << "~InputTextProcessor Constructor~" << std::endl;
    EventSystem::get().trigger(std::make_shared<PlayerStateCreatedEventArgs>(player_state_));
}

void sd::InputTextProcessor::process_input(const std::string& spell) {

    if(spell == "inspect room")
    {
        output_->add_line (player_state_->get_current_room()->get_description());
    }

    else {
        //split spell
        std::cout << "splitting input\n";
        std::vector<std::string> words = split_by_space(spell);

        //TODO: Sort words in array to be modifier first, then action(or other way round)



        //check spell validity (or do this in input field already?)
        /*
        if (!Vocabulary::allWords->Contains(words[0]) || !Vocabulary::allWords->Contains(words[1])) {
            output->addLine("Input not understood.");
        }
        */

        if(words[0] == "interact")
        {
            //TODO: Make sure that this actually is a door
            auto object = player_state_->get_current_room()->get_object_with_name(words[1]);

            if(object)
            {
                object->be_interacted_with();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>("could not find object in room.");
                EventSystem::get().trigger(args);
            }
        }

        else if(words[0] == "pickup")
        {
            //TODO: Make sure that this actually is a door
            //Door* door = (Door*) playerState->GetCurrentRoom()->GetObjectWithName(words[1]);
            output_->add_line ("picked up " + words[1]);

            std::shared_ptr<NewWordCollectedEventArgs> args;
            args = std::make_shared<NewWordCollectedEventArgs>(NewWordCollectedEventArgs(words[1]));
            EventSystem::get().trigger(args);
        }
            //*for(auto word : words)
            //*{
            //*if(!player_->HasWord(word))
            //*{
            //send invalid input message to output
            //*}
            //*}

            //check if currently fighting
        else if(player_state_->is_fighting())
        {
            //check if fight spell
            std::cout << "fight not nullptr\n";
            std::cout << "making turn\n";
            if(Vocabulary::all_words->contains(words[0]) && Vocabulary::all_words->contains(words[1]))
            {
                auto word_1 = Vocabulary::all_words->get(words[0]);
                auto word_2 = Vocabulary::all_words->get(words[1]);
                if(word_1->get_type() == sd::Word::Type::MODIFIER && word_2->get_type() == sd::Word::Type::ACTION)
                //make turn in fight
                    player_state_->get_fight ()->full_turn (words[1], words[0]);

                //evaluate result
                //end fight, if fight is over
                //*delete(fight);
                //*fight = nullptr;

                //if not fight spell

                //make enemy_ turn in fight
                //*fight->makeEnemyTurnOnly();
                //evaluate enemy_ turn result

                //evaluate player_
            }

            else
            {
                output_->add_line ("Input not valid modifier+action combination");
            }

        }

        else
        {
            output_->add_line ("nothing happens");
        }


        //if not fighting

        //check if it starts a fight

        //create fight object with player_ & enemy_
        //*fight = new fight(player_, enemy_);
        //evaluate spell (maybe from fight?)

        //if not starting fight

        //evaluate spell

        //send evaluation to output



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
    player_state_->set_room_as_current(std::move(room));
}

Sp<sd::PlayerState> sd::InputTextProcessor::get_player_state() {
    return player_state_;
}

void sd::InputTextProcessor::handle(std::shared_ptr<sd::EventArgs> e) {
    if (e->type == EventArgs::Type::TEXT_OUTPUT_CREATED) {
        auto arg = dynamic_cast<TextOutputCreatedEventArgs*>(e.get());
        output_ = arg->output;
    }
}


