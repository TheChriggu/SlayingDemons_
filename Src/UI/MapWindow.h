//
// Created by christian.heusser on 10.12.2019.
//

#ifndef _MAPWINDOW_H_
#define _MAPWINDOW_H_

#include "Core/DrawableObject.h"
#include "Dungeon/Room.h"
#include "Dungeon/Floor.h"
#include "PlayerState.h"
#include "Event/EventArgs.h"

namespace sd {
    class MapWindow : public DrawableObject, public Subscriber {
    private:
        Sp<sf::Texture> background_texture_;
        Sp<sf::Sprite> background_sprite_;
        sf::Vector2f position_;
        sf::Vector2f size_;
        Sp<sf::Texture> monster_portrait_texture_;
        Sp<sf::Sprite> monster_portrait_sprite_;

        Sp<Tilemap> current_tile_map_;
        Sp<PlayerState> player_state_;

        Sp<sf::Sprite> map_sprite_;
        Sp<sf::RenderTexture> map_texture_;
    public:
        MapWindow(sf::Vector2f position, sf::Vector2f size);
        ~MapWindow() override = default;

        bool setup() override;

        void draw_to(Sp<sf::RenderTarget> window) const override;

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;

        Sp<Room> get_room();
        void set_player_state(Sp<PlayerState> player_state);

        void handle(sf::Event event) override;
    };
}

#endif //_MAPWINDOW_H_
