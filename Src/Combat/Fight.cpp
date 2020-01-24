//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"
#include <iostream>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/LineToOutputEventArgs.h>

sd::Fight::Fight(sd::Fighter *player, sd::Monster *enemy)
    : player_(player)
    , enemy_(enemy)
{
    Stats zero_stats = {0,0,0,0,0,0,0,0};
    Stats one_stats = {1,1,1,1,1,1,1,1};
    
    player_->SetBaseStats(one_stats, one_stats);
    
    enemy_->ChangeHitPoints(100);
    player_->ChangeHitPoints(100);

    enemy_->SetBuffs(one_stats, one_stats);
    player_->SetBuffs(one_stats, one_stats);

}

sd::Fight::~Fight() {
    //delete (player_); Don't delete player_. He's just a reference
    //delete(enemy_);
    player_ = nullptr;
    enemy_ = nullptr;
}

void sd::Fight::full_turn(sf::String action, sf::String modifier) {

    Word* player_modifier;
    player_modifier = Vocabulary::all_words->Get(modifier);

    Word* player_action;
    player_action = Vocabulary::all_words->Get(action);

    Attack* player_attack = new Attack(player_, (Modifier*)player_modifier, (Action*)player_action);

    sf::String enemy_action = enemy_->GetAction();
    sf::String enemy_modifier = enemy_->GetModifier();
    Attack* enemy_attack = new Attack(enemy_, (Modifier*)(Vocabulary::all_words->Get(enemy_modifier)), (Action*)(Vocabulary::all_words->Get(enemy_action)));
    
    Stats player_attack_stats = player_attack->GetStats();
    Stats enemy_attack_stats = enemy_attack->GetStats();
    
    if(player_attack_stats.speed >= enemy_attack_stats.speed)
    {
        player_turn (player_attack, enemy_attack);
        enemy_turn(player_attack, enemy_attack);
    }
    
    else
        {
            enemy_turn (player_attack, enemy_attack);
            player_turn (player_attack, enemy_attack);
        }
    
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>("You now have " + std::to_string (player_->GetHitPoints ()) + " hp.");
    EventSystem::Get().Trigger(args);
    
    args = std::make_shared<LineToOutputEventArgs>("Your enemy now has " + std::to_string (enemy_->GetHitPoints ()) + " hp.");
    EventSystem::Get().Trigger(args);

     if(enemy_->GetHitPoints() <= 0)
     {
         args = std::make_shared<LineToOutputEventArgs>("You defeated your enemy.");
         EventSystem::Get().Trigger(args);

         std::shared_ptr<EventArgs> args;
         args = std::make_shared<EventArgs>(EventArgs());
         args->type = sd::EventArgs::Type::GOBLIN_DEFEATED;
         EventSystem::Get().Trigger(args);
     }

     delete(player_attack);
     delete(enemy_attack);
}

sd::Monster *sd::Fight::get_enemy() {
    return enemy_;
}
void sd::Fight::player_turn (sd::Attack *player_attack, sd::Attack *enemy_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(player_attack->GetSentenceSecondPerson());
    EventSystem::Get().Trigger(args);
   
    Stats damage_stats = player_attack->GetStats() - (enemy_->GetDefense()) ;
    damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();
    
    args = std::make_shared<LineToOutputEventArgs>("You made " + std::to_string(damage.value)  + " " + Stats::stat_type_to_string (damage.type) + " damage to your enemies hp.");
    EventSystem::Get().Trigger(args);
    
    //TODO: Qualitative evaluation
    /*
    if(damage_stats.mental < 0)
        {
            output->add_line ("He appears to be more friendly now.");
        }
    else{
            output->add_line ("He glares at you.");
        }
        */
    
    args = std::make_shared<LineToOutputEventArgs>("---");
    EventSystem::Get().Trigger(args);
    
    enemy_->ChangeHitPoints(-damage.value);
}

void sd::Fight::enemy_turn (sd::Attack *player_attack, sd::Attack *enemy_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(enemy_attack->GetSentenceThirdPerson ());
    EventSystem::Get().Trigger(args);
    
    Stats damage_stats = enemy_attack->GetStats() - (player_->GetDefense());
    damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();
    
    args = std::make_shared<LineToOutputEventArgs>("Your enemy made " + std::to_string(damage.value) + " " + Stats::stat_type_to_string (damage.type) + " damage to your hp.");
    EventSystem::Get().Trigger(args);
    
    //TODO: Qualitative evaluation
    
    args = std::make_shared<LineToOutputEventArgs>("---");
    EventSystem::Get().Trigger(args);

    player_->ChangeHitPoints(-damage.value);
}
