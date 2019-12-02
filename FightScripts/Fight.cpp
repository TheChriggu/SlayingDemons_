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
