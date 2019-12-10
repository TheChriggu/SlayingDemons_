//
// Created by christian.heusser on 02.12.2019.
//

#include "InputTextProcessor.h"
#include <iostream>

sd::InputTextProcessor::InputTextProcessor() {
    Stats zeroStats = {0,0,0,0,0,0,0,0,0};
    Stats oneStats = {1,1,1,1,1,1,1,1,1};
    Player* player = new Player();
    player->SetBaseStats(oneStats, oneStats);
    Monster* enemy = new Monster();
    enemy->SetBaseStats(oneStats, oneStats);
    fight = new Fight(player, enemy);
}

sd::InputTextProcessor::~InputTextProcessor() {
    delete fight;
    fight = nullptr;
}

void sd::InputTextProcessor::ProcessInput(sf::String spell) {

    //split spell
    std::cout << "splitting input\n";
    std::vector<sf::String> words = SplitBySpace(spell);

    //TODO: Sort words in array to be modifier first, then action(or other way round)

    //check spell validity (or do this in input field already?)
    if(!Vocabulary::allWords->Contains(words[0]) || !Vocabulary::allWords->Contains(words[1]))
    {
        output->addLine("Input not understood.");
    }

    //*for(auto word : words)
    //*{
        //*if(!player->HasWord(word))
        //*{
            //send invalid input message to output
        //*}
    //*}

    //check if currently fighting
    else// if(fight != nullptr)
    {
        //check if fight spell
        std::cout << "fight not nullptr\n";
        std::cout << "making turn\n";
            //make turn in fight
            fight->FullTurn(words[1], words[0], output);

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


    //if not fighting

        //check if it starts a fight

            //create fight object with player & enemy
            //*fight = new fight(player, enemy);
            //evaluate spell (maybe from fight?)

        //if not starting fight

            //evaluate spell



    //send evaluation to output
}

std::vector<sf::String> sd::InputTextProcessor::SplitBySpace(sf::String string) {
    std::vector<sf::String> retVal;
    sf::String delimiter = " ";

    size_t pos = 0;
    sf::String token;
    while ((pos = string.find(delimiter)) != string.InvalidPos) {
        token = string.substring(0, pos);

        retVal.emplace_back(token);
        string.erase(0, pos + delimiter.getSize());
    }
    retVal.emplace_back(string);

    return retVal;
}

void sd::InputTextProcessor::SetOutput(sd::TextOutput *_output) {
    output = _output;
}


