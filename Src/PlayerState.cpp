//
// Created by christian.heusser on 12.12.2019.
//

#include "PlayerState.h"

sd::PlayerState::PlayerState() {
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
