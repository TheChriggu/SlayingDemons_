//
// Created by christian.heusser on 25.11.2019.
//

#ifndef SLAYINGDEMONS_TILEMAP_H
#define SLAYINGDEMONS_TILEMAP_H

#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable{

public:
    Tilemap(unsigned int _width, unsigned int _height, sf::Vector2f _position, sf::Vector2u _tileSize);
    ~Tilemap() override;
    void LoadSpriteSheet(sf::String path);
    void SetLayout(int _layout[], int size);
    int* GetLayout();
    int GetWidth();
    int GetHeight();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::VertexArray vertices;
    sf::Texture tileset;
    sf::Vector2f position;
    int* layout;
    int width;
    int height;
    sf::Vector2u tileSize;

    void SetAllQuadPositions();
    void UpdateTiles();
};


#endif //SLAYINGDEMONS_TILEMAP_H
