//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FightStartedEventArgs.h>
#include <memory>
#include <utility>
#include "MapWindow.h"


sd::MapWindow::MapWindow(sf::Vector2f position, sf::Vector2f size)
    : DrawableObject("map-window")
    , Subscriber()
    , position_(position)
    , size_(size)
{
    background_texture_ = std::make_shared<sf::Texture>();
    background_sprite_ = std::make_shared<sf::Sprite>();
    current_tile_map_ = std::make_shared<Tilemap>(11, 7, position_ + sf::Vector2f(40, 44), sf::Vector2u(64, 64));
    monsterPortraitTexture = new sf::Texture();
    monsterPortraitSprite = new sf::Sprite();
}

bool sd::MapWindow::setup() {
    background_texture_->loadFromFile("../Resources/Sprites/fantasy_map.png");

    background_sprite_->setTexture(*background_texture_);
    background_sprite_->setPosition(position_);

    

    monsterPortraitTexture->loadFromFile("../Resources/Sprites/glitchy_goblin_red.png");

    monsterPortraitSprite->setTexture(*monsterPortraitTexture);
    monsterPortraitSprite->setPosition(position);

    return DrawableObject::setup ();

}

void sd::MapWindow::draw_to(Sp<sf::RenderTarget> window) const {
    window->draw(*background_sprite_);

    if(playerState->IsFighting())
    {
        window->draw(*monsterPortraitSprite);
    }
    else
    {
        currenttileMap->SetLayout(playerState->GetCurrentRoom()->GetLayout(),77);
        window->draw(*currenttileMap);
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

void sd::MapWindow::handle(Sp<sd::EventArgs> e) {

    if (e->type == EventArgs::Type::PLAYER_STATE_CREATED) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs*>(e.get());
        player_state_ = args->player_state;
    }

    if (e->type == EventArgs::Type::FightStarted) {
        auto arg = dynamic_cast<FightStartedEventArgs*>(e.get());
        monsterPortraitTexture->loadFromFile(arg->fight->GetEnemy()->GetPathToPortrait());
    }
}


