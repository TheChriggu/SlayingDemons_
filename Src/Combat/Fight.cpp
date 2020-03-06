//
// Created by christian.heusser on 02.12.2019.
//

#include "Fight.h"
#include <iostream>
#include <utility>
#include <Event/NewWordCollectedEventArgs.h>
#include <Event/EventSystem.h>
#include <Event/LineToOutputEventArgs.h>
#include <ScriptEngine/ScriptEngine.h>

sd::Fight::Fight(Sp<sd::Fighter> player, Sp<sd::Monster> enemy)
    : player_(std::move(player))
    , enemy_(std::move(enemy))
{
    Stats one_stats = {1,1,1,1,1,1,1,1};
    player_->set_base_stats(one_stats, one_stats);
    
    enemy_->set_hit_points(100);
    player_->set_hit_points(100);
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

    std::string enemy_action = enemy_->get_action();
    std::string enemy_modifier = enemy_->get_modifier();
    auto enemy_attack = std::make_shared<Attack>(
        enemy_,
        std::dynamic_pointer_cast<Modifier>(Vocabulary::all_words->get(enemy_modifier)),
        std::dynamic_pointer_cast<Action>(Vocabulary::all_words->get(enemy_action))
            );
    
    Stats player_attack_stats = player_attack->get_stats();
    Stats enemy_attack_stats = enemy_attack->get_stats();
    
    if(player_attack_stats.speed >= enemy_attack_stats.speed)
    {
        player_turn(player_attack);
        if (enemy_->get_hit_points() > 0)
        {
            enemy_turn(enemy_attack);
        }
    }
    
    else
     {
        enemy_turn (enemy_attack);
        if(player_->get_hit_points() > 0)
        {
            player_turn (player_attack);
        }
      }

    if(player_->get_hit_points() <= 0)
    {
        //player lose fight
        auto args = std::make_shared<LineToOutputEventArgs>("You died.");
        EventSystem::get().trigger(args);

        auto defeated_args = std::make_shared<EventArgs>();
        defeated_args->type = sd::EventArgs::Type::PLAYER_DIED;
        EventSystem::get().trigger(defeated_args);
    }

    else if (enemy_->get_hit_points() <= 0)
    {
        //enemy lose fight
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You won.");
        EventSystem::get().trigger(args);

        std::shared_ptr<EventArgs> defeated_args;
        defeated_args = std::make_shared<EventArgs>(EventArgs());
        defeated_args->type = sd::EventArgs::Type::CURRENT_ENEMY_DEFEATED;
        EventSystem::get().trigger(defeated_args);
    }

    else
    {
        std::string hp_eval = "";
        if(player_->get_hit_points() > 75)
        {
            hp_eval = "You feel well. Pretty healthy, despite the ongoing fight, actually.";
        }
        else if(player_->get_hit_points() > 50)
        {
            hp_eval = "This fight is becoming bothersome, and the hits you've taken are starting to show their effect.";
        }
        else if(player_->get_hit_points() > 35)
        {
            hp_eval = "You're breathing quite heavily now. This battle can't go on for much longer.";
        }
        else if(player_->get_hit_points() > 15)
        {
            hp_eval = "Your feet are becoming unstable, you're starting to lose focus. You need to get over with this soon.";
        }
        else if(player_->get_hit_points() > 0)
        {
            hp_eval = "Your conciousness is fading, everything is blurry. If you don't finish quickly, you'll collapse with the next hit from your enemy.";
        }


        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(hp_eval);
        EventSystem::get().trigger(args);

        std::string enemy_hp_eval = "";
        if(player_->get_hit_points() > 75)
        {
            enemy_hp_eval = "The " + enemy_->get_alias() + " is still standing on his feet strongly, pretty eager to attack you again.";
        }
        else if(player_->get_hit_points() > 50)
        {
            enemy_hp_eval = "Your attacks are beginning to show on the " +enemy_->get_alias() + "'s face. " + get_enemy_pronoun("He") + " is taking deep breaths now.";

        }
        else if(enemy_->get_hit_points() > 35)
        {
            enemy_hp_eval = "The " + enemy_->get_alias() + "'s handling of " + get_enemy_pronoun("his") + " weapon has become unsteady." + get_enemy_pronoun("He") + " probably can't go on for much longer.";
        }
        else if(enemy_->get_hit_points() > 15)
        {
            enemy_hp_eval = "The " + enemy_->get_alias() + "'s stance is becoming quite unstable. Just a few more hits, and " + get_enemy_pronoun("he") + " might collapse.";
        }
        else if(enemy_->get_hit_points() > 0)
        {
            enemy_hp_eval = "Almost there. One, maybe two attacks, and the " + enemy_->get_alias() + " will finally be done for.";
        }

        args = std::make_shared<LineToOutputEventArgs>(enemy_hp_eval);
        EventSystem::get().trigger(args);
    }
}

Sp<sd::Monster> sd::Fight::get_enemy() {
    return enemy_;
}

void sd::Fight::player_turn (const Sp<sd::Attack>& player_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;
    args = std::make_shared<LineToOutputEventArgs>(player_attack->get_sentence(2, enemy_));
    EventSystem::get().trigger(args);
   
    Stats damage_stats = (player_attack->get_stats()) - (enemy_->get_defense());
    //damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();

    std::string eval = "You made ";

    if(damage.value > 0) {
        if (damage.value > 50) {
            eval += "a lot of ";
        } else if (damage.value > 30) {
            eval += "quite a bit of ";
        } else if (damage.value > 20) {
            eval += "some ";
        } else if (damage.value > 10) {
            eval += "a bit of ";
        } else if (damage.value > 0) {
            eval += "almost no ";
        }
        eval += Stats::stat_type_to_string (damage.type) + " damage to the " + enemy_->get_alias() + ".";
    }
    else if(damage.value == 0)
    {
        eval += "no damage at all.";
    }
    else if(damage.value < 0)
    {
        eval = "Your attack accidentally healed the " + enemy_->get_alias() + ".";
    }

    std::cout << "damage done by player: " << damage.value << "\n";
    std::cout << "enemy hp left: " << enemy_->get_hit_points() << "\n";

    args = std::make_shared<LineToOutputEventArgs>(eval);
    EventSystem::get().trigger(args);

    args = std::make_shared<LineToOutputEventArgs>("---");
    EventSystem::get().trigger(args);
    
    enemy_->change_hit_points(-damage.value);
    
    ScriptEngine::get().broadcast("player_attacked", player_attack->get_sentence(2, enemy_));
}

void sd::Fight::enemy_turn (const Sp<sd::Attack>& enemy_attack)
{
    std::shared_ptr<LineToOutputEventArgs> args;

    args = std::make_shared<LineToOutputEventArgs>("The " + enemy_->get_alias() + " attacks you with " + enemy_attack->get_attack_name());
    EventSystem::get().trigger(args);

    args = std::make_shared<LineToOutputEventArgs>(enemy_attack->get_sentence(3, enemy_));
    EventSystem::get().trigger(args);

    Stats damage_stats = enemy_attack->get_stats() - (player_->get_defense());
    //damage_stats.min_to_zero ();
    Stats::SingleStat damage = damage_stats.get_max_damage_stat ();

    std::string eval = "";

    if(enemy_->get_gender() == "male")
    {
        eval = "He made ";
    }
    else if(enemy_->get_gender() == "female")
    {
        eval = "She made ";
    }
    else
    {
        eval = "It made ";
    }

    if(damage.value > 0) {
        if (damage.value > 50) {
            eval += "a lot of ";
        } else if (damage.value > 30) {
            eval += "quite a bit of ";
        } else if (damage.value > 20) {
            eval += "some ";
        } else if (damage.value > 10) {
            eval += "a bit of ";
        } else if (damage.value > 0) {
            eval += "almost no ";
        }
        eval += Stats::stat_type_to_string (damage.type) + " damage to you.";
    }
    else if(damage.value == 0)
    {
        eval += "no damage at all.";
    }
    else if(damage.value < 0)
    {
        if(enemy_->get_gender() == "male")
        {
            eval = "His attack accidentally healed you a bit.";
        }
        else if(enemy_->get_gender() == "female")
        {
            eval = "Her attack accidentally healed you a bit.";
        }
        else
        {
            eval = "Its attack accidentally healed you a bit.";
        }
    }

    std::cout << "damage done by enemy: " << damage.value << "\n";
    std::cout << "player hp left: " << enemy_->get_hit_points() << "\n";


    args = std::make_shared<LineToOutputEventArgs>(eval);
    EventSystem::get().trigger(args);

    args = std::make_shared<LineToOutputEventArgs>("---");
    EventSystem::get().trigger(args);
    
    player_->change_hit_points(-damage.value);
    
    ScriptEngine::get().broadcast("enemy_attacked", enemy_attack->get_sentence(2,enemy_));
}

std::string sd::Fight::get_enemy_pronoun(std::string declination) {
    //TODO: Cover this more thoroughly
    if(declination == "he")
    {
        if(enemy_->get_gender() == "male")
        {
            return "he";
        }
        else if(enemy_->get_gender() == "female")
        {
            return "she";
        }
        else
        {
            return "it";
        }
    }
    if(declination == "He")
    {
        if(enemy_->get_gender() == "male")
        {
            return "He";
        }
        else if(enemy_->get_gender() == "female")
        {
            return "She";
        }
        else
        {
            return "It";
        }
    }
    if(declination == "his") {
        if (enemy_->get_gender() == "male") {
            return "his";
        } else if (enemy_->get_gender() == "female") {
            return "her";
        } else {
            return "its";
        }
    }
    if(declination == "His") {
        if (enemy_->get_gender() == "male") {
            return "His";
        } else if (enemy_->get_gender() == "female") {
            return "Her";
        } else {
            return "Its";
        }
    }
    return "XE";
}
