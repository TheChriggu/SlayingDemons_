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
    player->SetBuffs(zeroStats, zeroStats);
    enemy->SetBuffs(zeroStats, zeroStats);
}

sd::Fight::~Fight() {
    //delete (player); Don't delete player. He's just a reference
    //delete(enemy);
    player = nullptr;
    enemy = nullptr;
}

void sd::Fight::FullTurn(sf::String _action, sf::String _modifier) {

    std::cout << "load modifier.\n";
    Word* playerModifier;
    playerModifier = Vocabulary::allWords->Get(_modifier);

    std::cout << "load action.\n";
    Word* playerAction;
    playerAction = Vocabulary::allWords->Get(_action);

    std::cout << "create player attack.\n";
     Attack* playerAttack = new Attack(player, (Modifier*)playerModifier, (Action*)playerAction);

    std::cout << "load enemy action & modifier.\n";
     sf::String enemyAction = enemy->GetAction();
     sf::String enemyModifier = enemy->GetModifier();
    std::cout << "Set enemy attack.\n";
     Attack* enemyAttack = new Attack(enemy,  (Modifier*)(Vocabulary::allWords->Get(enemyModifier)), (Action*)(Vocabulary::allWords->Get(enemyAction)));

    std::cout << "Set player stats.\n";
     Stats playerAttackStats = playerAttack->GetStats();
    std::cout << "Set enemy stats.\n";
     Stats enemyAttackStats = enemyAttack->GetStats();
    std::cout << "compare stats.\n";
     if(playerAttackStats.speed >= enemyAttackStats.speed)
     {
         std::cout << "making player move first";
        //make player move
        //recalculate enemy attack
        //make enemy move
     }
     else
     {
         std::cout << "making enemy move first";
        //make enemy move
        //recalculate player attack
        //make player move
     }

     delete(playerAttack);
     delete(enemyAttack);
}

