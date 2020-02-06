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
        rooms_.emplace_back(std::make_shared<Room>(room.first.as<std::string>()));
        std::cout << "++ Room: " << room.first.as<std::string>() << std::endl;
        
        if (room.second.is<bool>())
            continue;
        
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
            
            std::vector<int> layout;
            for (int i=1 ; i <= (size.x * size.y) ; i++) {
                layout.emplace_back(object.second.as<sol::lua_table>()["layout"]["tiles"][i].get_or(-1));
            }

            auto function_collection = std::make_shared<FunctionCollection>(
                object.second.as<sol::lua_table>()["on_interaction"],
                object.second.as<sol::lua_table>()["on_open"],
                object.second.as<sol::lua_table>()["on_inspection"],
                object.second.as<sol::lua_table>()["on_fight"],
                object.second.as<sol::lua_table>()["on_enter"],
                object.second.as<sol::lua_table>()["on_destroy"]
                );

            
            
            
            if (size.x == 1 && size.y == 1) {
                //sol::lua_table test = object.second.as<sol::lua_table>()["next_room"];
                //std::cout << "++ Single tile: " << test.empty() << std::endl;

                rooms_.back()->add_object(
                    std::make_shared<SingleTileObject>(
                        object.first.as<std::string>(),
                        layout[0],
                        position,
                        function_collection)
                );
            } else {

                if (!object.second.as<sol::lua_table>()["next_room"].get_or<std::string>("").empty()) {
                    std::cout << "++ door"  << std::endl;


                    rooms_.back()->add_object(
                            std::make_shared<Door>(
                                    object.first.as<std::string>(),
                                    layout[0],
                                    layout[1],
                                    position,
                                    object.second.as<sol::lua_table>()["next_room"].get<std::string>(),
                                    object.second.as<sol::lua_table>()["is_locked"].get<bool>(),
                                    function_collection)
                    );
                }

                else {
                    std::cout << "++ Multi tile" << std::endl;
                    rooms_.back()->add_object(
                            std::make_shared<MultiTileObject>(
                                    object.first.as<std::string>(),
                                    layout.data(),
                                    size,
                                    position,
                                    function_collection)
                    );
                }
            }
        }
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
