//
// Created by christian.heusser on 10.12.2019.
//

#ifndef SLAYINGDEMONS_MAPWINDOW_H
#define SLAYINGDEMONS_MAPWINDOW_H
#include "../Core/DrawableObject.h"
#include "../Room.h"

namespace sd {
    class MapWindow : public DrawableObject {
    private:
        sf::Texture* backgroundTexture;
        sf::Sprite* backgroundSprite;
        sf::Vector2f position;
        sf::Vector2f size;

        Room* room;
    public:
        MapWindow(sf::Vector2f _position, sf::Vector2f _size);
        ~MapWindow() override;

        void DrawTo(sf::RenderTarget* window) const override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;

        void Handle(sf::Event event) override;
    };
}

#endif //SLAYINGDEMONS_MAPWINDOW_H
