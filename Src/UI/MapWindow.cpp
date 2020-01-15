//
// Created by christian.heusser on 10.12.2019.
//

#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FightStartedEventArgs.h>
#include "MapWindow.h"


sd::MapWindow::MapWindow(sf::Vector2f _position, sf::Vector2f _size)
    : DrawableObject("map-window")
    , Subscriber()
    , position(_position)
    , size(_size)
{
    backgroundTexture = new sf::Texture();
    backgroundSprite = new sf::Sprite();
    monsterPortraitTexture = new sf::Texture();
    monsterPortraitSprite = new sf::Sprite();
    currenttileMap = new Tilemap(11,7,position + sf::Vector2f(40,44),sf::Vector2u(64,64));
}

sd::MapWindow::~MapWindow() {
    delete backgroundTexture;
    backgroundTexture = nullptr;

    delete backgroundSprite;
    backgroundSprite = nullptr;

    delete monsterPortraitTexture;
    monsterPortraitTexture = nullptr;

    delete monsterPortraitSprite;
    monsterPortraitSprite = nullptr;

    delete currenttileMap;
    currenttileMap = nullptr;
}

void sd::MapWindow::DrawTo(sf::RenderTarget *window) const {
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

void sd::MapWindow::SetPlayerState(sd::PlayerState *_playerState) {
    playerState = _playerState;
}

void sd::MapWindow::Handle(sp<sd::EventArgs> e) {
    std::cout << "!Handle!" << std::endl;
    if (e->type == EventArgs::Type::PlayerStateCreated) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs*>(e.get());
        playerState = args->player_state.get();
    }

    if (e->type == EventArgs::Type::FightStarted) {
        auto arg = dynamic_cast<FightStartedEventArgs*>(e.get());
        monsterPortraitTexture->loadFromFile(arg->fight->GetEnemy()->GetPathToPortrait());
    }
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
