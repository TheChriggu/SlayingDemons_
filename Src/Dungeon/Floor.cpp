//
// Created by christian.heusser on 12.12.2019.
//

#include "Floor.h"

sd::Floor::Floor() {
    Room* room1 = new Room();
    Room* room2 = new Room();

    Door* northDoor = new Door("north door", 9, 25, sf::Vector2i(5,0), room2);
    room1->AddObject(northDoor);

    Door* southDoor = new Door("south door", 9, 25, sf::Vector2i(5,6), room1);
    room2->AddObject(southDoor);

    currentRoom = room1;
}

sd::Floor::~Floor() {
    rooms.clear();
    currentRoom = nullptr;
}

sd::Room *sd::Floor::GetCurrentRoom() {
    return currentRoom;
}
