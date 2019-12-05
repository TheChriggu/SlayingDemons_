//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"
#include <iostream>

sd::Fight::Fight(sd::Player *_player, sd::Monster *_enemy)
    : player(_player)
    , enemy(_enemy)
{
    Stats zeroStats = {0,0,0,0,0,0,0,0,0};
    Stats oneStats = {1,1,1,1,1,1,1,1,1};
    player->SetBuffs(oneStats, oneStats);
    enemy->SetBuffs(oneStats, oneStats);
}

sd::Fight::~Fight() {
    //delete (player); Don't delete player. He's just a reference
    //delete(enemy);
    player = nullptr;
    enemy = nullptr;
}

void sd::Fight::FullTurn(sf::String _action, sf::String _modifier, TextOutput* output) {

    Word* playerModifier;
    playerModifier = Vocabulary::allWords->Get(_modifier);

    Word* playerAction;
    playerAction = Vocabulary::allWords->Get(_action);

     Attack* playerAttack = new Attack(player, (Modifier*)playerModifier, (Action*)playerAction);

     sf::String enemyAction = enemy->GetAction();
     sf::String enemyModifier = enemy->GetModifier();
     Attack* enemyAttack = new Attack(enemy,  (Modifier*)(Vocabulary::allWords->Get(enemyModifier)), (Action*)(Vocabulary::allWords->Get(enemyAction)));

     Stats playerAttackStats = playerAttack->GetStats();
     Stats enemyAttackStats = enemyAttack->GetStats();
     std::cout << "Player speed: " << playerAttackStats.speed << "\n";
     std::cout << "Enemy speed: " << enemyAttackStats.speed << "\n";
     if(playerAttackStats.speed >= enemyAttackStats.speed)
     {
         output->addLine(std::string(playerAttack->GetSentenceSecondPerson()));
         output->addLine(std::string(enemyAttack->GetSentenceThirdPerson()));
        //make player move
        //recalculate enemy attack
        //make enemy move
     }
     else
     {
         output->addLine(std::string(enemyAttack->GetSentenceThirdPerson()));
         output->addLine(std::string(playerAttack->GetSentenceSecondPerson()));
     }

     delete(playerAttack);
     delete(enemyAttack);
}

