//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FightStartedEventArgs.h>
#include <memory>
#include <utility>
#include <ScriptEngine/ScriptEngine.h>
#include "MapWindow.h"
#include "Event/EventSystem.h"


sd::MapWindow::MapWindow(sf::Vector2f position, sf::Vector2f size)
    : DrawableObject("map-window")
    , Subscriber()
    , position_(position)
    , size_(size)
{
    
    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == EventArgs::Type::PLAYER_STATE_CREATED) {
            auto args = std::dynamic_pointer_cast<PlayerStateCreatedEventArgs>(e);
            player_state_ = Sp<PlayerState>(args->player_state);
        }
    
        if (e->type == EventArgs::Type::FIGHT_STARTED) {
            auto arg = std::dynamic_pointer_cast<FightStartedEventArgs>(e);
            monster_portrait_texture_->loadFromFile(arg->fight.lock()->get_enemy()->get_path_to_portrait());
        }
        );
    
    REGISTER_EVENT_HANDLER();
    
    background_texture_ = std::make_shared<sf::Texture>();
    background_sprite_ = std::make_shared<sf::Sprite>();
    current_tile_map_ = std::make_shared<Tilemap>(11, 7, position + sf::Vector2f(40, 44), sf::Vector2u(64, 64));
    monster_portrait_texture_ = std::make_shared<sf::Texture>();
    monster_portrait_sprite_ = std::make_shared<sf::Sprite>();
    //monsterPortraitSprite->setScale(0.75,0.75);

    map_texture_ = std::make_shared<sf::RenderTexture>();
    map_sprite_ = std::make_shared<sf::Sprite>();
}

bool sd::MapWindow::setup() {
    background_texture_->loadFromFile("../Resources/Sprites/fantasy_map.png");

    background_sprite_->setTexture(*background_texture_);
    background_sprite_->setPosition(position_);

    monster_portrait_texture_->loadFromFile("../Resources/Sprites/goblin.png");

    monster_portrait_sprite_->setTexture(*monster_portrait_texture_);
    monster_portrait_sprite_->setPosition(position_);

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    map_texture_->create(table["size"]["x"], table["size"]["y"]);
    map_sprite_->setTexture(map_texture_->getTexture());

    return DrawableObject::setup ();

}

void sd::MapWindow::draw_to(Sp<sf::RenderTarget> window) const {
    map_texture_->clear(sf::Color::Transparent);

    map_texture_->draw(*background_sprite_);
    
    if(player_state_->is_fighting())
    {
        map_texture_->draw(*monster_portrait_sprite_);
    }
    else
    {
        current_tile_map_->set_layout(player_state_->get_current_room()->get_layout(), 77);
        map_texture_->draw(*current_tile_map_);
    }
    map_texture_->display();


    if (shader_procedure_) {

        shader_procedure_->process (window.get (), map_sprite_.get ());
    } else {
        window->draw(*map_sprite_);
    }


}

sf::Vector2f sd::MapWindow::get_position() {
    return position_;
}

sf::Vector2f sd::MapWindow::get_size() {
    return size_;
}

void sd::MapWindow::handle(sf::Event event) {
    //room->Handle(event);
}

Sp<sd::Room> sd::MapWindow::get_room() {
    //return room;
    std::cout << "dont call MapWindow.GetRoom()!!\n";
    return nullptr;
}

void sd::MapWindow::set_player_state(Sp<sd::PlayerState> player_state) {
    player_state_ = std::move(player_state);
}


