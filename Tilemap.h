//
// Created by christian.heusser on 25.11.2019.
//

#ifndef SLAYINGDEMONS_TILEMAP_H
#define SLAYINGDEMONS_TILEMAP_H

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable{

public:
    void Initialize(sf::Vector2f _position);
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    sf::Vector2f position;
};


#endif //SLAYINGDEMONS_TILEMAP_H
