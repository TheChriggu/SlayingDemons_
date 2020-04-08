//
// Created by christian.heusser on 12.12.2019.
//

#include <Event/WalkedThroughDoorEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <Dungeon/Goblin.h>
#include <utility>
#include <Event/FightStartedEventArgs.h>
#include <Combat/MonsterList.h>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/DoorUnlockedEventArgs.h>
#include "PlayerState.h"

sd::PlayerState::PlayerState()
    : Subscriber() {
    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == EventArgs::Type::WALKED_THROUGH_DOOR) {
            auto arg = std::dynamic_pointer_cast<WalkedThroughDoorEventArgs>(e);
            set_current_room(current_floor_->get_room(arg->door.lock()->get_connected_room()));

            //auto args = std::make_shared<LineToOutputEventArgs>(get_current_room()->get_enter_description());
            //EventSystem::get().trigger(args);
        }

        if (e->type == EventArgs::Type::START_FIGHT_WITH_GOBLIN) {

            std::shared_ptr<LineToOutputEventArgs> args;
            args = std::make_shared<LineToOutputEventArgs>("Starting Fight.");
            EventSystem::get().trigger(args);

            //Monster* goblin = new Monster("../Resources/Sprites/glitchy_goblin_red.png");

            start_new_fight("Goblin");
        }

        if (e->type == EventArgs::Type::CURRENT_ENEMY_DEFEATED) {
            current_room_->remove_object_with_name(fight_->get_enemy()->get_room_object_to_remove_on_defeat());
            fight_.reset();

            std::shared_ptr<EventArgs> args;
            args = std::make_shared<EventArgs>(EventArgs());
            args->type = sd::EventArgs::Type::FIGHT_ENDED;
            EventSystem::get().trigger(args);

            ScriptEngine::get().broadcast("fight_stopped");

            player_vocabulary_->set_objects(current_room_->get_all_objects());
        }
        if (e->type == EventArgs::Type::ROOM_LAYOUT_CHANGED) {
            player_vocabulary_->set_objects(current_room_->get_all_objects());
        }
        if (e->type == EventArgs::Type::PLAYER_DIED) {

            fight_.reset();

            auto args = std::make_shared<EventArgs>(EventArgs());
            args->type = sd::EventArgs::Type::FIGHT_ENDED;
            EventSystem::get().trigger(args);
        }
        if (e->type == EventArgs::Type::GAINED_FOCUS)
        {
            check_for_self_destruct_added();

            if(!FileInput::is_existing("../Resources/InnocentFileDoNotOpen.txt"))
            {
                ScriptEngine::get().broadcast("player_profile_deleted");
            }
        }
        );

    REGISTER_EVENT_HANDLER();

    fight_ = nullptr;
    player_ = std::make_shared<Fighter>();
    //current_room_ = current_floor_->get_start_room();
    player_vocabulary_ = std::make_shared<PlayerVocabulary>();

    door_fight_done = false;

    ScriptEngine::get().register_all("start_new_fight", &PlayerState::start_new_fight, this);
    ScriptEngine::get().register_all("start_new_fight_with_differently_named_enemy", &PlayerState::start_new_fight_room_object, this);
    ScriptEngine::get().register_all("player_door_fight", &PlayerState::player_door_fight, this);
}

Sp<sd::Room> sd::PlayerState::get_current_room() {
    return current_room_;
}

Sp<sd::Fight> sd::PlayerState::get_fight() {
    return fight_;
}

bool sd::PlayerState::is_fighting() {
    return fight_ != nullptr;
}

void sd::PlayerState::set_current_room(Sp<sd::Room> room) {
    current_room_ = std::move(room);

    player_vocabulary_->set_objects(current_room_->get_all_objects());
    
    ScriptEngine::get().broadcast("room_changed", current_room_->get_name());
}

void sd::PlayerState::set_current_floor(Sp<sd::Floor> floor)
{
    current_floor_ = std::move(floor);
}


void sd::PlayerState::start_new_fight_room_object(const std::string& enemy_name, const std::string& room_object_to_remove_on_defeat) {
    std::string enemy_name_lower = enemy_name;
    std::string room_object_to_remove_on_defeat_lower = room_object_to_remove_on_defeat;
    strtk::convert_to_lowercase(enemy_name_lower);
    strtk::convert_to_lowercase(room_object_to_remove_on_defeat_lower);
    
    auto list = MonsterList::get();
    auto goblin = list->get_monster(enemy_name_lower);
    goblin->set_room_object_to_remove_on_defeat(room_object_to_remove_on_defeat_lower);
    //start_new_fight(Sp<Monster>(goblin));
    
    fight_ = std::make_shared<Fight>(player_, goblin);

    auto args = std::make_shared<FightStartedEventArgs>(fight_);
    EventSystem::get().trigger(args);
    
    

    ScriptEngine::get().broadcast("fight_started_with", enemy_name_lower);
}

void sd::PlayerState::start_new_fight(const std::string &enemy_name) {
    std::string enemy_name_lower = enemy_name;
    strtk::convert_to_lowercase(enemy_name_lower);
    
    start_new_fight_room_object(enemy_name_lower, enemy_name_lower);
}

Sp<sd::PlayerVocabulary> sd::PlayerState::get_player_vocabulary() {
    return player_vocabulary_;
}

void sd::PlayerState::save_current_vocab() {
    player_vocabulary_->save_to_file();

}

void sd::PlayerState::load_vocab()
{

    player_vocabulary_->load_from_file();
}

Sp<sd::Floor> sd::PlayerState::get_current_floor() {
    return current_floor_;
}

void sd::PlayerState::player_door_fight() {
    if(!player_vocabulary_->has_word("light") || !player_vocabulary_->has_word("red") || !player_vocabulary_->has_word("green") || !player_vocabulary_->has_word("blue"))
    {
        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You'd love to do that, but you're still lacking something.");
        EventSystem::get().trigger(args);
    }
    else if(!door_fight_done)
    {
        door_fight_done = true;

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("You finally have everything you need");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("[input]> red light");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("You shoot a red light at the door. It starts to glow lightly.");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("[input]> blue light");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("You shoot a blue light at the door. It starts to glow stronger now.");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("[input]> green light");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("You shoot a green light at the door. It is starting to vibrate.");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("The vibration gets stronger and stronger. Suddenly it stops.");
        EventSystem::get().trigger(args);

        args = std::make_shared<LineToOutputEventArgs>("The door is passable now.");
        EventSystem::get().trigger(args);

        std::shared_ptr<DoorUnlockedEventArgs> doorArgs;
        doorArgs = std::make_shared<DoorUnlockedEventArgs>("main_room", "white_door");
        EventSystem::get().trigger(doorArgs);
    }
    else

        {
            std::shared_ptr<LineToOutputEventArgs> args;
            args = std::make_shared<LineToOutputEventArgs>("You've already spent enough energy on this.");
            EventSystem::get().trigger(args);
        }

}

void sd::PlayerState::check_for_self_destruct_added() {
    player_vocabulary_->check_for_self_destruct_added();
}




