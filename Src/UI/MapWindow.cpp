//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FightStartedEventArgs.h>
#include <memory>
#include <utility>
#include "MapWindow.h"


sd::MapWindow::MapWindow(sf::Vector2f _position, sf::Vector2f _size)
    : DrawableObject("map-window")
    , Subscriber()
    , position(_position)
    , size(_size)
{
    backgroundTexture = std::make_shared<sf::Texture>();
    backgroundSprite = std::make_shared<sf::Sprite>();
    currenttileMap = std::make_shared<Tilemap>(11,7,position + sf::Vector2f(40,44),sf::Vector2u(64,64));
    monsterPortraitTexture = new sf::Texture();
    monsterPortraitSprite = new sf::Sprite();
}

bool sd::MapWindow::Setup() {
    backgroundTexture->loadFromFile("../Resources/Sprites/fantasy_map.png");

    backgroundSprite->setTexture(*backgroundTexture);
    backgroundSprite->setPosition(position);

    

    monsterPortraitTexture->loadFromFile("../Resources/Sprites/glitchy_goblin_red.png");

    monsterPortraitSprite->setTexture(*monsterPortraitTexture);
    monsterPortraitSprite->setPosition(position);

    
    return DrawableObject::Setup();

}

void sd::MapWindow::DrawTo(sp<sf::RenderTarget> window) const {
    window->draw(*backgroundSprite);

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

sf::Vector2f sd::MapWindow::GetPosition() {
    return position;
}

sf::Vector2f sd::MapWindow::GetSize() {
    return size;
}

void sd::MapWindow::Handle(sf::Event event) {
    //room->Handle(event);
}

sp<sd::Room> sd::MapWindow::GetRoom() {
    //return room;
    std::cout << "dont call MapWindow.GetRoom()!!\n";
    return nullptr;
}

void sd::MapWindow::SetPlayerState(sp<sd::PlayerState> _playerState) {
    playerState = std::move(_playerState);
}

void sd::MapWindow::Handle(sp<sd::EventArgs> e) {

    if (e->type == EventArgs::Type::PlayerStateCreated) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs*>(e.get());
        playerState = args->player_state;
    }

    if (e->type == EventArgs::Type::FightStarted) {
        auto arg = dynamic_cast<FightStartedEventArgs*>(e.get());
        monsterPortraitTexture->loadFromFile(arg->fight->GetEnemy()->GetPathToPortrait());
    }
}


