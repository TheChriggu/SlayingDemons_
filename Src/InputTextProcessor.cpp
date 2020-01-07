//
// Created by christian.heusser on 02.12.2019.
//

#include "InputTextProcessor.h"
#include <iostream>
#include <Event/TextOutputCreatedEventArgs.h>

sd::InputTextProcessor::InputTextProcessor() : Subscriber() {
    playerState = new PlayerState();
}

sd::InputTextProcessor::~InputTextProcessor() {
    delete playerState;
    playerState = nullptr;
}

void sd::InputTextProcessor::ProcessInput(sf::String spell) {

    if(spell == "inspect room")
    {
        output->addLine(playerState->GetCurrentRoom()->GetDescription());
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
            Door* door = (Door*) playerState->GetCurrentRoom()->GetObjectWithName(words[1]);
            playerState->SetRoomAsCurrent(door->GetConnectedRoom());
            output->addLine(playerState->GetCurrentRoom()->GetEnterDescription());
            if(playerState->GetCurrentRoom()->GetEnemy() != nullptr)
            {
                output->addLine("starting fight");
                playerState->StartNewFight(playerState->GetCurrentRoom()->GetEnemy());
            }
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
            //make turn in fight
            playerState->GetFight()->FullTurn(words[1], words[0], output);

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
            output->addLine("nothing happens");
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

void sd::InputTextProcessor::SetOutput(sd::TextOutput *_output) {
    output = _output;
}

void sd::InputTextProcessor::SetRoom(sd::Room *_room) {
    playerState->SetRoomAsCurrent(_room);
}

sd::PlayerState *sd::InputTextProcessor::GetPlayerState() {
    return playerState;
}

void sd::InputTextProcessor::Handle(std::shared_ptr<sd::EventArgs> e) {
    std::cout << "Test Output" << std::endl;
    if (e->type == EventArgs::Type::TextOutputCreated) {
        auto arg = dynamic_cast<TextOutputCreatedEventArgs*>(e.get());
        output = arg->output;
    }
}


