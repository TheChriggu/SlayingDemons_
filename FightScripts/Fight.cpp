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
         //player move
         output->addLine(std::string(playerAttack->GetSentenceSecondPerson()));
         Stats damageStats = playerAttackStats - (enemy->GetDefense()) ;
         damageStats = MinToZero(damageStats);

         float physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.plant+damageStats.water;
         output->addLine("You made " + std::to_string(physicalDamage) + " damage to your enemies hp.");
         output->addLine("You made " + std::to_string(damageStats.mental) + " to his mentality.");
         if(damageStats.mental < 0)
         {
             output->addLine("He appears to be more friendly now.");
         }
         else
         {
             output->addLine("He glares at you.");
         }

         output->addLine("---");
         //Enemy move
         output->addLine(std::string(enemyAttack->GetSentenceThirdPerson()));
         damageStats = enemyAttackStats - (player->GetDefense());
         damageStats = MinToZero(damageStats);

         physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.plant+damageStats.water;
         output->addLine("Your enemy made " + std::to_string(physicalDamage) + " damage to your hp.");
         output->addLine("He made " + std::to_string(damageStats.mental) + " to your mentality.\n");
     }
     else
     {
         //Enemy move
         output->addLine(std::string(enemyAttack->GetSentenceThirdPerson()));
         Stats damageStats = enemyAttackStats - (player->GetDefense());
         damageStats = MinToZero(damageStats);

         float physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.plant+damageStats.water;
         output->addLine("Your enemy made " + std::to_string(physicalDamage) + " damage to your hp.");
         output->addLine("He made " + std::to_string(damageStats.mental) + " damage to your mentality.");

         output->addLine("---");
         //player move
         output->addLine(std::string(playerAttack->GetSentenceSecondPerson()));
         damageStats = playerAttackStats - (enemy->GetDefense());
         damageStats = MinToZero(damageStats);

         physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.plant+damageStats.water;
         output->addLine("You made " + std::to_string(physicalDamage) + " damage to your enemies hp.");
         output->addLine("You made " + std::to_string(damageStats.mental) + " damage to his mentality.");
         if(damageStats.mental < 0)
         {
             output->addLine("He appears to be more friendly now.\n");
         }
         else
         {
             output->addLine("He glares at you.\n");
         }


     }

     delete(playerAttack);
     delete(enemyAttack);


}

sd::Stats sd::Fight::MinToZero(Stats stats) {
    if (stats.plant < 0)
    {
        stats.plant = 0;
    }
    if (stats.tree < 0)
    {
        stats.tree = 0;
    }
    if (stats.physical < 0)
    {
        stats.physical = 0;
    }
    if (stats.earth < 0)
    {
        stats.earth = 0;
    }
    if (stats.fire < 0)
    {
        stats.fire = 0;
    }
    if (stats.water< 0)
    {
        stats.water = 0;
    }

    return stats;
}
