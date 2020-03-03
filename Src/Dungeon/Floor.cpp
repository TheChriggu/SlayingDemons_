//
// Created by christian.heusser on 12.12.2019.
//

#include <ScriptEngine/ScriptEngine.h>
#include "Floor.h"
#include "Goblin.h"

sd::Floor::Floor(const std::string& name, sol::table& floor_data) : start_room_(nullptr) {
    //int counter = 0;
    
    name_ = name;
    
    for (const auto& room : floor_data) {
        if (room.second.is<bool>())
            continue;

        std::vector<sf::Vector2i> corners;
        std::vector<Sp<sd::RoomObject>> room_objects;
        Sp<Room> current_room;
        bool is_start = false;

        for (const auto& object : room.second.as<sol::lua_table>())
        {
            std::cout << "++ object: " << object.first.as<std::string>() << std::endl;
            
            if (object.second.is<bool>()) {
                is_start = object.second.as<bool>();
            }

            else if (object.first.as<std::string>()== "layout")
            {
                for (const auto& corner : object.second.as<sol::table&>())
                {
                    int x = corner.second.as<sol::lua_table>()[1].get_or(0);
                    int y = corner.second.as<sol::lua_table>()[2].get_or(0);
                    corners.emplace_back(sf::Vector2i (corner.second.as<sol::lua_table>()[1].get_or(0),corner.second.as<sol::lua_table>()[2].get_or(0)));
                }
                current_room = std::make_shared<Room>(room.first.as<std::string>(), corners);
            }

            else
            {
                sf::Vector2i position(
                        object.second.as<sol::lua_table>()["position"]["x"].get_or(0),
                        object.second.as<sol::lua_table>()["position"]["y"].get_or(0)
                );
                sf::Vector2i size(
                        object.second.as<sol::lua_table>()["layout"]["size"][1].get_or(1),
                        object.second.as<sol::lua_table>()["layout"]["size"][2].get_or(1)
                );

                std::vector<int> layout;
                for (int i=1 ; i <= (size.x * size.y) ; i++) {
                    layout.emplace_back(object.second.as<sol::lua_table>()["layout"]["tiles"][i].get_or(-1));
                }

                int rotation = object.second.as<sol::lua_table>()["rotation"].get_or(0);

                auto function_collection = std::make_shared<FunctionCollection>(
                        object.second.as<sol::lua_table>()["on_open"].get<sol::coroutine>(),
                        object.second.as<sol::lua_table>()["on_inspection"].get<sol::coroutine>(),
                        object.second.as<sol::lua_table>()["on_fight"].get<sol::coroutine>(),
                        object.second.as<sol::lua_table>()["on_enter"].get<sol::coroutine>(),
                        object.second.as<sol::lua_table>()["on_destroy"].get<sol::coroutine>()
                );

                if (size.x == 1 && size.y == 1) {
                    room_objects.emplace_back(
                            std::make_shared<SingleTileObject>(
                                    object.first.as<std::string>(),
                                    layout[0],
                                    position,
                                    rotation,
                                    function_collection)
                    );
                }
                else {

                    if (!object.second.as<sol::lua_table>()["next_room"].get_or<std::string>("").empty()) {
                        std::cout << "++ door"  << std::endl;
                        room_objects.emplace_back(
                                std::make_shared<Door>(
                                        object.first.as<std::string>(),
                                        layout[0],
                                        layout[1],
                                        position,
                                        rotation,
                                        object.second.as<sol::lua_table>()["next_room"].get<std::string>(),
                                        object.second.as<sol::lua_table>()["is_locked"].get<bool>(),
                                        function_collection)
                        );
                    }

                    else {
                        std::cout << "++ Multi tile" << std::endl;
                        room_objects.emplace_back(
                                std::make_shared<MultiTileObject>(
                                        object.first.as<std::string>(),
                                        layout,
                                        size,
                                        rotation,
                                        position,
                                        function_collection)
                        );
                    }
                }


            }
        }

        rooms_.emplace_back(current_room);
        if (is_start) {
            start_room_ = rooms_.back();
        }

        for (auto object : room_objects)
        {
            rooms_.back()->add_object(object);
        }


        std::cout << "++ Room: " << room.first.as<std::string>() << std::endl;

    }
}

Sp<sd::Room> sd::Floor::get_start_room() {
    return start_room_;
}

Sp<sd::Room> sd::Floor::get_room(const std::string &name) const
{
    for (const auto& room : rooms_) {
        if (room->get_name() == name)
            return room;
    }
    
    return nullptr;
}

std::string sd::Floor::get_name() {
    return name_;
}
