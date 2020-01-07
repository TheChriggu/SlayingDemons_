//
// Created by christian.heusser on 12.12.2019.
//

#include "Floor.h"

sd::Floor::Floor() {
    Room* room1 = new Room();
    Room* room2 = new Room();

    Door* northDoor = new Door("doorY", 9, 25, sf::Vector2i(5,0), room2);
    room1->AddObject(northDoor);

    Door* southDoor = new Door("doorX", 9, 25, sf::Vector2i(5,6), room1);
    room2->AddObject(southDoor);

    Monster* enemy = new Monster();
    Stats oneStats = {1,1,1,1,1,1,1,1};
    enemy->SetBaseStats(oneStats, oneStats);
    enemy->SetBuffs(oneStats,oneStats);

    room2->SetEnemy(enemy);

    rooms.emplace_back(room1);
    rooms.emplace_back(room2);
}

sd::Floor::~Floor() {
    rooms.clear();
    //currentRoom = nullptr;
}

sd::Room *sd::Floor::GetStartRoom() {
    return rooms.front();
}
