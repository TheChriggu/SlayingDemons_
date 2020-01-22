//
// Created by christian.heusser on 12.12.2019.
//

#include <ScriptEngine/ScriptEngine.h>
#include "Floor.h"
#include "Goblin.h"
#include "LastRoom.h"

sd::Floor::Floor() : start_room_(nullptr) {
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
    
}

sd::Floor::~Floor() {
    shutdown();
}

Sp<sd::Room> sd::Floor::get_start_room() {
    return start_room_;
}

bool sd::Floor::setup()
{
    int counter = 0;
    
    auto d = ScriptEngine::Get()->get_script("dungeon")->get_table("dungeon");
    if (!d) return false;
    sol::lua_table floor = d.value()["floor1"];
    
    for (const auto& room : floor) {
        rooms_.emplace_back(std::make_shared<Room>(room.first.as<std::string>()));
        std::cout << "++ Room: " << room.first.as<std::string>() << std::endl;
        for (const auto& object : room.second.as<sol::lua_table>())
        {
            std::cout << "++ object: " << object.first.as<std::string>() << std::endl;
    
            if (object.second.is<bool>()) {
                if (object.second.as<bool>()) {
                    start_room_ = rooms_.back();
                    continue;
                }
            }
            if (!object.second.is<sol::table>())
                continue;
            
            sf::Vector2i position(
                object.second.as<sol::lua_table>()["position"]["x"].get_or(0),
                object.second.as<sol::lua_table>()["position"]["y"].get_or(0)
                );
            sf::Vector2i size(
                object.second.as<sol::lua_table>()["layout"]["size"][1].get_or(1),
                object.second.as<sol::lua_table>()["layout"]["size"][2].get_or(1)
            );
            // TODO(FK): Remove because mem-leak
            std::vector<int> layout = {
                object.second.as<sol::lua_table>()["layout"]["tiles"][1].get_or(0),
                object.second.as<sol::lua_table>()["layout"]["tiles"][2].get_or(0)
            };
            sol::function on_interaction = object.second.as<sol::lua_table>()["on_interaction"];
            
            
            
            if (size.x == 1 && size.y == 1) {
                //sol::lua_table test = object.second.as<sol::lua_table>()["next_room"];
                //std::cout << "++ Single tile: " << test.empty() << std::endl;
                if (!object.second.as<sol::lua_table>()["next_room"].get_or<std::string>("").empty()) {
                    std::cout << "++ door"  << std::endl;
                    rooms_.back()->AddObject(
                        new Door(
                            object.first.as<std::string>(),
                                layout[0],
                                layout[1],
                                position,
                            object.second.as<sol::lua_table>()["next_room"].get<std::string>(),
                            on_interaction)
                    );
                }
            
                rooms_.back()->AddObject(
                    new SingleTileObject(
                        object.first.as<std::string>(),
                            layout[0],
                            position,
                        on_interaction)
                );
            } else {
                std::cout << "++ Multi tile"  << std::endl;
                rooms_.back()->AddObject(
                    new MultiTileObject(
                        object.first.as<std::string>(),
                        layout.data(),
                        size,
                        position,
                        on_interaction)
                );
            }
        }
    }
    
    /*Room* room1 = new Room("");
    Room* room2 = new Room("");
    Room* room3 = new Room("");
    Room* room4 = new Room("");
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
    
    
    
    rooms_.emplace_back(room1);
    rooms_.emplace_back(room2);
    rooms_.emplace_back(room3);
    rooms_.emplace_back(room4);
    rooms_.emplace_back(room5);*/
    
    return true;
}

void sd::Floor::shutdown()
{
    rooms_.clear();
}

Sp<sd::Room> sd::Floor::get_room(const std::string &name) const
{
    for (const auto& room : rooms_) {
        if (room->get_name() == name)
            return room;
    }
    
    return nullptr;
}
