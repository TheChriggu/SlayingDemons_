//
// Created by christian.heusser on 02.12.2019.
//

#include "InputTextProcessor.h"
#include <iostream>

sd::InputTextProcessor::InputTextProcessor() {
    fight = nullptr;
}

sd::InputTextProcessor::~InputTextProcessor() {

}

void sd::InputTextProcessor::ProcessInput(sf::String spell) {

    //split spell
    std::vector<sf::String> words = SplitBySpace(spell);

    //*check spell validity (or do this in input field already?


    //*check if currently fighting
    if(fight != nullptr)

        //*check if fight spell

            //*make turn in fight
            //fight->fullTurn(string action, string modifier);

            //*evaluate result
                //*end fight, if fight is over
                //delete(fight);
                //fight = nullptr;

        //*if not fight spell

            //*make enemy turn in fight
            //fight->makeEnemyTurnOnly();
            //*evaluate enemy turn result

            //*evaluate player

    //*if not fighting

        //*check if it starts a fight

            //*create fight object with player & enemy
            //fight = new fight(player, enemy);
            //evaluate spell (maybe from fight?)

        //*if not starting fight

            //*evaluate spell



    //*send evaluation to output
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


