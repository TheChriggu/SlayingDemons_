//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"
#include <iostream>
#include <utility>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/LineToOutputEventArgs.h>

sd::Fight::Fight(Sp<sd::Fighter> player, Sp<sd::Monster> enemy)
    : player_(std::move(player))
    , enemy_(std::move(enemy))
{
    Stats zero_stats = {0,0,0,0,0,0,0,0};
    Stats one_stats = {1,1,1,1,1,1,1,1};
    
    player_->SetBaseStats(one_stats, one_stats);
    
    enemy_->ChangeHitPoints(100);
    player_->ChangeHitPoints(100);

    enemy_->SetBuffs(one_stats, one_stats);
    player_->SetBuffs(one_stats, one_stats);

}

void sd::Fight::full_turn(std::string action, std::string modifier) {

    //Word* player_modifier;
    auto player_modifier = Vocabulary::all_words->get(modifier);

    //Word* player_action;
    auto player_action = Vocabulary::all_words->get(action);

    auto player_attack = std::make_shared<Attack>(
        player_,
        std::dynamic_pointer_cast<Modifier>(player_modifier),
        std::dynamic_pointer_cast<Action>(player_action)
            );

    std::string enemy_action = enemy_->GetAction().toAnsiString();
    std::string enemy_modifier = enemy_->GetModifier().toAnsiString();
    auto enemy_attack = std::make_shared<Attack>(
        enemy_,
        std::dynamic_pointer_cast<Modifier>(Vocabulary::all_words->get(enemy_modifier)),
        std::dynamic_pointer_cast<Action>(Vocabulary::all_words->get(enemy_action))
            );
    
    Stats player_attack_stats = player_attack->get_stats();
    Stats enemy_attack_stats = enemy_attack->get_stats();
    
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
    EventSystem::get().trigger(args);
    
    args = std::make_shared<LineToOutputEventArgs>("Your enemy now has " + std::to_string (enemy_->GetHitPoints ()) + " hp.");
    EventSystem::get().trigger(args);

     if(enemy_->GetHitPoints() <= 0)
     {
         args = std::make_shared<LineToOutputEventArgs>("You defeated your enemy.");
         EventSystem::get().trigger(args);

         std::shared_ptr<EventArgs> args;
         args = std::make_shared<EventArgs>(EventArgs());
         args->type = sd::EventArgs::Type::GOBLIN_DEFEATED;
         EventSystem::get().trigger(args);
     }
}

Sp<sd::Monster> sd::Fight::get_enemy() {
    return enemy_;
}
void sd::Fight::player_turn (const Sp<sd::Attack>& player_attack, const Sp<sd::Attack>& enemy_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(player_attack->get_sentence_second_person());
    EventSystem::get().trigger(args);
   
    Stats damage_stats = player_attack->get_stats() - (enemy_->GetDefense()) ;
    damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();
    
    args = std::make_shared<LineToOutputEventArgs>("You made " + std::to_string(damage.value)  + " " + Stats::stat_type_to_string (damage.type) + " damage to your enemies hp.");
    EventSystem::get().trigger(args);
    
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
    EventSystem::get().trigger(args);
    
    enemy_->ChangeHitPoints(-damage.value);
}

void sd::Fight::enemy_turn (const Sp<sd::Attack>& player_attack, const Sp<sd::Attack>& enemy_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(enemy_attack->get_sentence_third_person());
    EventSystem::get().trigger(args);
    
    Stats damage_stats = enemy_attack->get_stats() - (player_->GetDefense());
    damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();
    
    args = std::make_shared<LineToOutputEventArgs>("Your enemy made " + std::to_string(damage.value) + " " + Stats::stat_type_to_string (damage.type) + " damage to your hp.");
    EventSystem::get().trigger(args);
    
    //TODO: Qualitative evaluation
    
    args = std::make_shared<LineToOutputEventArgs>("---");
    EventSystem::get().trigger(args);

    player_->ChangeHitPoints(-damage.value);
}
