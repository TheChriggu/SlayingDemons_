//
// Created by christian.heusser on 12.12.2019.
//

#include "Floor.h"

sd::Floor::Floor() {
    sf::Vector2f position = sf::Vector2f(1127.0, 41.0) + sf::Vector2f(40,44);
    Tilemap* tilemap = new Tilemap(11,7,position,sf::Vector2u(64,64));
    Tilemap* tilemap2 = new Tilemap(11,7,position,sf::Vector2u(64,64));
    Room* room1 = new Room(tilemap);
    Room* room2 = new Room(tilemap2);

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
