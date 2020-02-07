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
#include "PlayerState.h"

sd::PlayerState::PlayerState()
    : Subscriber() {
    fight_ = nullptr;
    player_ = std::make_shared<Fighter>();
    //current_room_ = current_floor_->get_start_room();
    player_vocabulary_ = std::make_shared<PlayerVocabulary>();
    
    ScriptEngine::get().register_all("start_new_fight", &PlayerState::start_new_fight, this);
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

    ScriptEngine::get().broadcast("room_changed", current_room_->get_name());
}

void sd::PlayerState::set_current_floor(Sp<sd::Floor> floor)
{
    current_floor_ = std::move(floor);
}


void sd::PlayerState::start_new_fight(const std::string& enemy_name) {
    auto list = MonsterList::get();
    auto goblin = list->get_monster(enemy_name);
    //start_new_fight(Sp<Monster>(goblin));
    
    fight_ = std::make_shared<Fight>(player_, goblin);

    std::shared_ptr<FightStartedEventArgs> args;
    args = std::make_shared<FightStartedEventArgs>(fight_.get());
    EventSystem::get().trigger(args);
    
    

    ScriptEngine::get().broadcast("fight_started_with", enemy_name);
}

Sp<sd::PlayerVocabulary> sd::PlayerState::get_player_vocabulary() {
    return player_vocabulary_;
}

void sd::PlayerState::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == EventArgs::Type::WALKED_THROUGH_DOOR) {
        auto arg = dynamic_cast<WalkedThroughDoorEventArgs*>(e.get());
        set_current_room(current_floor_->get_room(arg->door->get_connected_room()));

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(get_current_room()->get_enter_description());
        EventSystem::get().trigger(args);
    }

    if (e->type == EventArgs::Type::START_FIGHT_WITH_GOBLIN) {

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>("Starting Fight.");
        EventSystem::get().trigger(args);
        
        //Monster* goblin = new Monster("../Resources/Sprites/glitchy_goblin_red.png");

        start_new_fight("Goblin");
    }

    if (e->type == EventArgs::Type::CURRENT_ENEMY_DEFEATED) {
        current_room_->remove_object_with_name(fight_->get_enemy()->get_name());
        fight_.reset();

        std::shared_ptr<EventArgs> args;
        args = std::make_shared<EventArgs>(EventArgs());
        args->type = sd::EventArgs::Type::FIGHT_ENDED;
        EventSystem::get().trigger(args);
    
        ScriptEngine::get().broadcast("fight_stopped");
    }

}

