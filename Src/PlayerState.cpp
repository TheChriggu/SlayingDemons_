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
#include "PlayerState.h"

sd::PlayerState::PlayerState()
    : Subscriber() {
    fight_ = nullptr;
    player_ = std::make_shared<Fighter>();
    floor_ = std::make_shared<Floor>();
    floor_->setup();
    current_room_ = floor_->get_start_room();
    player_vocabulary_ = std::make_shared<PlayerVocabulary>();
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

void sd::PlayerState::set_room_as_current(Sp<sd::Room> room) {
    current_room_ = std::move(room);

    RoomObject* object = current_room_->GetObjectWithName("Goblin");
    if(object)
    {
        Goblin* goblin = (Goblin*) object;
        goblin->SetPlayerVocab(get_player_vocabulary().get());
    }
}


void sd::PlayerState::start_new_fight(Sp<sd::Monster> enemy) {
    fight_ = std::make_shared<Fight>(player_.get(), enemy.get());

    std::shared_ptr<FightStartedEventArgs> args;
    args = std::make_shared<FightStartedEventArgs>(FightStartedEventArgs(fight_.get()));
    EventSystem::Get().Trigger(args);

}

Sp<sd::PlayerVocabulary> sd::PlayerState::get_player_vocabulary() {
    return player_vocabulary_;
}

void sd::PlayerState::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == EventArgs::Type::WALKED_THROUGH_DOOR) {
        auto arg = dynamic_cast<WalkedThroughDoorEventArgs*>(e.get());
        set_room_as_current(floor_->get_room(arg->door->GetConnectedRoom()));

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs(get_current_room()->GetEnterDescription()));
        EventSystem::Get().Trigger(args);
    }

    if (e->type == EventArgs::Type::START_FIGHT_WITH_GOBLIN) {

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Starting Fight."));
        EventSystem::Get().Trigger(args);
        
        //Monster* goblin = new Monster("../Resources/Sprites/glitchy_goblin_red.png");

        auto list = MonsterList::Get();
        Monster* goblin = list->GetMonster("Goblin");
        start_new_fight(Sp<Monster>(goblin));
    }

    if (e->type == EventArgs::Type::GOBLIN_DEFEATED) {
        ((Door*) current_room_->GetObjectWithName("east_door"))->SetLocked(false);
        fight_.reset();

        std::shared_ptr<EventArgs> args;
        args = std::make_shared<EventArgs>(EventArgs());
        args->type = sd::EventArgs::Type::FIGHT_ENDED;
        EventSystem::Get().Trigger(args);
    }

}
