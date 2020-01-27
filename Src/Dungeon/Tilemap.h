//
// Created by christian.heusser on 25.11.2019.
//

#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable{

public:
    Tilemap(unsigned int width, unsigned int height, sf::Vector2f position, sf::Vector2u tile_size);
    ~Tilemap() override;
    void load_sprite_sheet(std::string path);
    void set_layout(int *layout, int size);
    int* get_layout();
    int get_width();
    int get_height();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray vertices_;
    sf::Texture tileset_;
    sf::Vector2f position_;
    int* layout_;
    int width_;
    int height_;
    sf::Vector2u tile_size_;

    void SetAllQuadPositions();
    void UpdateTiles();
};


#endif //_TILEMAP_H_
