//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"

sd::Fight::Fight(sd::Fighter *_player, sd::Fighter *_enemy)
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

     Attack* playerAttack = new Attack(player,  dynamic_cast<Modifier*>(Vocabulary::allWords->Get(_modifier)), dynamic_cast<Action*>(Vocabulary::allWords->Get(_action)));

     sf::String enemyAction = enemy->GetAction();
     sf::String enemyModifier = enemy->GetModifier();
     Attack* enemyAttack = new Attack(enemy,  dynamic_cast<Modifier*>(Vocabulary::allWords->Get(enemyModifier)), dynamic_cast<Action*>(Vocabulary::allWords->Get(enemyAction)));

     Stats playerAttackStats = playerAttack->GetStats();
     Stats enemyAttackStats = enemyAttack->GetStats();
     if(playerAttackStats.speed >= enemyAttackStats.speed)
     {
        //make player move
        //recalculate enemy attack
        //make enemy move
     }
     else
     {
        //make enemy move
        //recalculate player attack
        //make player move
     }

     delete(playerAttack);
     delete(enemyAttack);
}

