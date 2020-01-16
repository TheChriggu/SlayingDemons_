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
        sp<sf::Texture> backgroundTexture;
        sp<sf::Sprite> backgroundSprite;
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Texture* monsterPortraitTexture;
        sf::Sprite* monsterPortraitSprite;

        sp<Tilemap> currenttileMap;
        sp<PlayerState> playerState;
    public:
        MapWindow(sf::Vector2f _position, sf::Vector2f _size);
        ~MapWindow() override = default;

        bool Setup() override;

        void DrawTo(sp<sf::RenderTarget> window) const override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;

        sp<Room> GetRoom();
        void SetPlayerState(sp<PlayerState> _playerState);

        void Handle(sf::Event event) override;
        void Handle(sp<EventArgs> e) override;
    };
}

#endif //SLAYINGDEMONS_MAPWINDOW_H
