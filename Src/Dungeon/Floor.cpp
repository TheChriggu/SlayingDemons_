//
// Created by christian.heusser on 12.12.2019.
//

#include "Floor.h"
#include "Sofa.h"
#include "Table.h"
#include "Book.h"
#include "Goblin.h"
#include "LastRoom.h"

sd::Floor::Floor() {
    /*
    Room* room1 = new Room();
    Room* room2 = new Room();

    Door* northDoor = new Door("doorY", 9, 25, sf::Vector2i(5,0), room2);
    room1->AddObject(northDoor);

    Door* southDoor = new Door("doorX", 9, 25, sf::Vector2i(5,6), room1);
    room2->AddObject(southDoor);

    Monster* enemy_ = new Monster();
    Stats oneStats = {1,1,1,1,1,1,1,1};
    enemy_->SetBaseStats(oneStats, oneStats);
    enemy_->SetBuffs(oneStats,oneStats);

    room2->SetEnemy(enemy_);

    rooms.emplace_back(room1);
    rooms.emplace_back(room2);
     */

    Room* room1 = new Room();
    Room* room2 = new Room();
    Room* room3 = new Room();
    Room* room4 = new Room();
    Room* room5 = new LastRoom();


    room1->AddObject(new Door("NorthDoor", 9, 3, sf::Vector2i(5,0), room2));
    room1->AddObject(new Door("EastDoor", 9, 3, sf::Vector2i(10,3), room3));
    int sofaLayout[] = {32,40};
    Sofa* sofa = new Sofa("Sofa", sofaLayout, sf::Vector2i(1,2),sf::Vector2i(1,1));
    room1->AddObject(sofa);
    int tableLayout[] = {33,41};
    sd::Table* table = new sd::Table("Table", tableLayout, sf::Vector2i(1,2),sf::Vector2i(9,4));
    room1->AddObject(table);


    room2->AddObject(new Door("SouthDoor", 9, 3, sf::Vector2i(5,6), room1));
    Door* door = new Door("EastDoor", 9, 3, sf::Vector2i(10,3), room4);
    room2->AddObject(door);
    door->SetLocked(true);
    int bookshelfLayout[] = {48,56};
    room2->AddObject(new MultiTileObject("Bookshelf", bookshelfLayout, sf::Vector2i(1,2), sf::Vector2i(6,4)));
    room2->AddObject(new Goblin("Goblin", 25, sf::Vector2i(9,3)));

    room3->AddObject(new Door("WestDoor", 9, 3, sf::Vector2i(0,3), room1));
    room3->AddObject(new Book("Book", 34, sf::Vector2i(7,3)));



    room4->AddObject(new Door("WestDoor", 9, 3, sf::Vector2i(0,3), room2));
    room4->AddObject(new Door("NorthDoor", 9, 3, sf::Vector2i(5,0), room5));

    room5->AddObject(new Door("SouthDoor", 9, 3, sf::Vector2i(5,6), room4));
    room5->AddObject(new Door("NorthDoor", 9, 3, sf::Vector2i(5,0), room1));



    rooms.emplace_back(room1);
    rooms.emplace_back(room2);
    rooms.emplace_back(room3);
    rooms.emplace_back(room4);
    rooms.emplace_back(room5);
}

sd::Floor::~Floor() {
    rooms.clear();
    //currentRoom = nullptr;
}

sd::Room *sd::Floor::GetStartRoom() {
    return rooms.front();
}
