//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_MAPWINDOW_H
#define SLAYINGDEMONS_MAPWINDOW_H

#include "Core/DrawableObject.h"
#include "Dungeon/Room.h"
#include "Dungeon/Floor.h"
#include "PlayerState.h"
#include "Event/EventArgs.h"

namespace sd {
    class MapWindow : public DrawableObject, public Subscriber {
    private:
        sf::Texture* backgroundTexture;
        sf::Sprite* backgroundSprite;
        sf::Vector2f position;
        sf::Vector2f size;

        Tilemap* currenttileMap;
        PlayerState* playerState;
    public:
        MapWindow(sf::Vector2f _position, sf::Vector2f _size);
        ~MapWindow() override;

        bool Setup() override;

        void DrawTo(sf::RenderTarget* window) const override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;
        Room* GetRoom();
        void SetPlayerState(PlayerState* _playerState);

        void Handle(sf::Event event) override;
        void Handle(sp<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_MAPWINDOW_H
