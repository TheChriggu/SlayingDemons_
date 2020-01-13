//
// Created by christian.heusser on 12.12.2019.
//

#include <Event/WalkedThroughDoorEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <Event/EventSystem.h>
#include <Dungeon/Goblin.h>
#include "PlayerState.h"

sd::PlayerState::PlayerState()
    : Subscriber() {
    fight = nullptr;
    player = new Fighter();
    floor = new Floor();
    currentRoom = floor->GetStartRoom();
    playerVocabulary = new PlayerVocabulary();
}

sd::PlayerState::~PlayerState() {
    delete fight;
    fight = nullptr;
    currentRoom = nullptr;

    delete player;
    player = nullptr;

    delete floor;
    floor = nullptr;
    currentRoom = nullptr;

    delete playerVocabulary;
    playerVocabulary = nullptr;
}

sd::Room *sd::PlayerState::GetCurrentRoom() {
    return currentRoom;
}

sd::Fight *sd::PlayerState::GetFight() {
    return fight;
}

bool sd::PlayerState::IsFighting() {
    return fight != nullptr;
}

void sd::PlayerState::SetRoomAsCurrent(sd::Room *room) {
    currentRoom = room;

    RoomObject* object = currentRoom->GetObjectWithName("Goblin");
    if(object)
    {
        Goblin* goblin = (Goblin*) object;
        goblin->SetPlayerVocab(GetPlayerVocabulary());
    }
}

void sd::PlayerState::StartNewFight(sd::Monster *enemy) {
    fight = new Fight(player, enemy);
}

void sd::PlayerState::EndFight() {
    delete fight;
    fight = nullptr;
}

sd::PlayerVocabulary *sd::PlayerState::GetPlayerVocabulary() {
    return playerVocabulary;
}

void sd::PlayerState::Handle(std::shared_ptr<EventArgs> e) {
    if (e->type == EventArgs::Type::WalkedThroughDoor) {
        auto arg = dynamic_cast<WalkedThroughDoorEventArgs*>(e.get());
        SetRoomAsCurrent(arg->door->GetConnectedRoom());

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs(GetCurrentRoom()->GetEnterDescription()));
        EventSystem::Get().Trigger(args);
    }

    if (e->type == EventArgs::Type::StartFightWithGoblin) {

        std::shared_ptr<LineToOutputEventArgs> args;
        args = std::make_shared<LineToOutputEventArgs>(LineToOutputEventArgs("Starting Fight."));
        EventSystem::Get().Trigger(args);

        Monster* goblin = new Monster();

        StartNewFight(goblin);
    }

    if (e->type == EventArgs::Type::GoblinDefeated) {

        ((Door*) currentRoom->GetObjectWithName("EastDoor"))->SetLocked(false);
        delete fight;
        fight = nullptr;
    }


}
