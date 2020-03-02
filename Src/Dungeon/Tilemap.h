//
// Created by christian.heusser on 25.11.2019.
//

#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <SFML/Graphics.hpp>
#include <Event/Subscriber.h>
#include "../Dungeon/TileData.h"

namespace sd {
    class Tilemap : public sf::Drawable, public sf::Transformable, public Subscriber {

    public:
        Tilemap(unsigned int width, unsigned int height, sf::Vector2f position, sf::Vector2u tile_size);

        ~Tilemap() override = default;

        void load_sprite_sheet(const std::string &path);

        void set_layout(std::vector<TileData> &layout, int size);

        std::vector<TileData> &get_layout();

        int get_width();

        int get_height();

    private:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        sf::VertexArray vertices_;
        sf::Texture tileset_;
        sf::Vector2f position_;
        std::vector<TileData> layout_;
        int width_;
        int height_;
        sf::Vector2u tile_size_;

        void set_all_quad_positions();

        void update_tiles();
    };
}

#endif //_TILEMAP_H_
