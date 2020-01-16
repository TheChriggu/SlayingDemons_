//
// Created by christian.heusser on 02.12.2019.
//

#include "InputTextProcessor.h"
#include <iostream>
#include <utility>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>

sd::InputTextProcessor::InputTextProcessor() : Subscriber() {
    playerState = Sp<PlayerState>(new PlayerState());
    std::cout << "~InputTextProcessor Constructor~" << std::endl;
    EventSystem::Get().Trigger(Sp<PlayerStateCreatedEventArgs>(new PlayerStateCreatedEventArgs(playerState)));
}

void sd::InputTextProcessor::ProcessInput(sf::String spell) {

    if(spell == "inspect room")
    {
        output->add_line (playerState->GetCurrentRoom ()->GetDescription ());
    }

    else {
        //split spell
        std::cout << "splitting input\n";
        std::vector<std::string> words = SplitBySpace(spell.toAnsiString());

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
            RoomObject* object = playerState->GetCurrentRoom()->GetObjectWithName(words[1]);

            if(object)
            {
                object->BeInteractedWith();
            }
            else
            {
                std::shared_ptr<LineToOutputEventArgs> args;
                args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("could not find object in room."));
                EventSystem::Get().Trigger(args);
            }
        }

        else if(words[0] == "pickup")
        {
            //TODO: Make sure that this actually is a door
            //Door* door = (Door*) playerState->GetCurrentRoom()->GetObjectWithName(words[1]);
            output->add_line ("picked up " + words[1]);

            std::shared_ptr<NewWordCollectedEventArgs> args;
            args = std::make_shared<NewWordCollectedEventArgs>(NewWordCollectedEventArgs(words[1]));
            EventSystem::Get().Trigger(args);
        }
            //*for(auto word : words)
            //*{
            //*if(!player->HasWord(word))
            //*{
            //send invalid input message to output
            //*}
            //*}

            //check if currently fighting
        else if(playerState->IsFighting())
        {
            //check if fight spell
            std::cout << "fight not nullptr\n";
            std::cout << "making turn\n";
            if(Vocabulary::all_words->Contains(words[0]) && Vocabulary::all_words->Contains(words[1]))
            {
                Word* word1 = Vocabulary::all_words->Get(words[0]);
                Word* word2 = Vocabulary::all_words->Get(words[1]);
                if(word1->GetType() == sd::Word::type::modifier && word2->GetType() == sd::Word::type::action)
                //make turn in fight
                playerState->GetFight()->FullTurn(words[1], words[0], output.get());

                //evaluate result
                //end fight, if fight is over
                //*delete(fight);
                //*fight = nullptr;

                //if not fight spell

                //make enemy turn in fight
                //*fight->makeEnemyTurnOnly();
                //evaluate enemy turn result

                //evaluate player
            }

            else
            {
                output->add_line ("Input not valid modifier+action combination");
            }

        }

        else
        {
            output->add_line ("nothing happens");
        }


        //if not fighting

        //check if it starts a fight

        //create fight object with player & enemy
        //*fight = new fight(player, enemy);
        //evaluate spell (maybe from fight?)

        //if not starting fight

        //evaluate spell

        //send evaluation to output



    }
}

std::vector<std::string> sd::InputTextProcessor::SplitBySpace(std::string string) {
    std::vector<std::string> retVal;
    std::string delimiter = " ";

    size_t pos = 0;
    std::string token;
    while ((pos = string.find(delimiter)) != std::string::npos) {
        token = string.substr(0, pos);

        retVal.emplace_back(token);
        string.erase(0, pos + delimiter.size());
    }
    retVal.emplace_back(string);

    return retVal;
}

void sd::InputTextProcessor::SetOutput(Sp<sd::TextOutput> _output) {
    output = std::move(_output);
}

void sd::InputTextProcessor::SetRoom(Sp<sd::Room> _room) {
    playerState->SetRoomAsCurrent(_room.get());
}

Sp<sd::PlayerState> sd::InputTextProcessor::GetPlayerState() {
    return playerState;
}

void sd::InputTextProcessor::handle(std::shared_ptr<sd::EventArgs> e) {
    if (e->type == EventArgs::Type::TEXT_OUTPUT_CREATED) {
        auto arg = dynamic_cast<TextOutputCreatedEventArgs*>(e.get());
        output = arg->output;
    }
}


