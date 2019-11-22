//
// Created by christian.heusser on 06.11.2019.
//

#include "TextGlitch.h"

TextGlitch::TextGlitch() {
    window = new sf::RenderWindow(sf::VideoMode(1920,1080), "Glitch");
    window->setVisible(false);
}

TextGlitch::~TextGlitch() {
    delete window;
}

sf::Texture* TextGlitch::glitch(sf::Text* text) {
    window->clear();
    window->draw(*text);
    sf::Texture* tex = new sf::Texture();
    tex->create(1920, 1080);
    tex->update(*window);

    return tex;
}
