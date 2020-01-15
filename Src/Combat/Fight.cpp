//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"
#include <iostream>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/EventSystem.h>

sd::Fight::Fight(sd::Fighter *_player, sd::Monster *_enemy)
    : player(_player)
    , enemy(_enemy)
{
    Stats zeroStats = {0,0,0,0,0,0,0,0};
    Stats oneStats = {1,1,1,1,1,1,1,1};

    Stats enemyOffense(1,1,1,1,1,1,1,1);
    Stats enemyDefense(1,1,1,1,1,1,1,1);
    Stats playerOffense(1,1,1,1,1,1,1,1);
    Stats playerDefense(1,1,1,1,1,1,1,1);

    enemy->SetBaseStats(enemyOffense, enemyDefense);
    player->SetBaseStats(playerOffense, playerDefense);

    enemy->ChangeHitPoints(100);
    player->ChangeHitPoints(100);

    enemy->SetBuffs(oneStats, oneStats);
    player->SetBuffs(oneStats, oneStats);

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

     if(playerAttackStats.speed >= enemyAttackStats.speed)
     {
         //player move
         output->addLine(playerAttack->GetSentenceSecondPerson());
         Stats damageStats = playerAttackStats - (enemy->GetDefense()) ;
         damageStats.MinToZero();

         float physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.water;
         output->addLine("You made " + std::to_string(physicalDamage) + " damage to your enemies hp.");
         output->addLine("You made " + std::to_string(damageStats.mental) + " damage to his mentality.");
         if(damageStats.mental < 0)
         {
             output->addLine("He appears to be more friendly now.");
         }
         else
         {
             output->addLine("He glares at you.");
         }

         enemy->ChangeHitPoints(-physicalDamage);
         enemy->ChangeMentalState(-damageStats.mental);


         output->addLine("---");
         //Enemy move
         output->addLine(enemyAttack->GetSentenceThirdPerson());
         damageStats = enemyAttackStats - (player->GetDefense());
         damageStats.MinToZero();

         physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.water;
         output->addLine("Your enemy made " + std::to_string(physicalDamage) + " damage to your hp.");
         output->addLine("He made " + std::to_string(damageStats.mental) + " damage to your mentality.");

         player->ChangeHitPoints(-physicalDamage);
         player->ChangeMentalState(-damageStats.mental);
     }
     else
     {
         //Enemy move
         output->addLine(enemyAttack->GetSentenceThirdPerson());
         Stats damageStats = enemyAttackStats - (player->GetDefense());
         damageStats.MinToZero();

         float physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.water;
         output->addLine("Your enemy made " + std::to_string(physicalDamage) + " damage to your hp.");
         output->addLine("He made " + std::to_string(damageStats.mental) + " damage to your mentality.");

         player->ChangeHitPoints(-physicalDamage);
         player->ChangeMentalState(-damageStats.mental);

         output->addLine("---");
         //player move
         output->addLine(playerAttack->GetSentenceSecondPerson());
         damageStats = playerAttackStats - (enemy->GetDefense());
         damageStats.MinToZero();

         physicalDamage = damageStats.fire+damageStats.earth+damageStats.physical+damageStats.tree+damageStats.water;
         output->addLine("You made " + std::to_string(physicalDamage) + " damage to your enemies hp.");
         output->addLine("You made " + std::to_string(damageStats.mental) + " damage to his mentality.");
         if(damageStats.mental < 0)
         {
             output->addLine("He appears to be more friendly now.");
         }
         else
         {
             output->addLine("He glares at you.");
         }

         enemy->ChangeHitPoints(-physicalDamage);
         enemy->ChangeMentalState(-damageStats.mental);


     }

     output->addLine("---");
     output->addLine("You now have " + std::to_string(player->GetHitPoints()) + " hp and " + std::to_string(player->GetMentalState()) + " mentality.");
     output->addLine("Your enemy now has " + std::to_string(enemy->GetHitPoints()) + " hp and " + std::to_string(enemy->GetMentalState()) + " mentality.");


     if(enemy->GetHitPoints() <= 0)
     {
         output->addLine("You defeated your enemy.");

         std::shared_ptr<EventArgs> args;
         args = std::make_shared<EventArgs>(EventArgs());
         args->type = sd::EventArgs::Type::GoblinDefeated;
         EventSystem::Get().Trigger(args);
     }

     delete(playerAttack);
     delete(enemyAttack);
}

sd::Monster *sd::Fight::GetEnemy() {
    return enemy;
}
