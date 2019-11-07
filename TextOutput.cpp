//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>

TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color) : DisplayArea(position, size, color) {
    lines = new std::list<FormattedLine*>();
    lines->push_back(new FormattedLine("", sf::Vector2f(backgroundImage->getPosition()+sf::Vector2f(20,20))));
    text = "";
    glitchWindow = new sf::RenderWindow(sf::VideoMode(1920,1080), "Glitch");
    glitchWindow->setVisible(false);

}

TextOutput::~TextOutput() {
    delete lines;
    lines = nullptr;
}

void TextOutput::drawTo(sf::RenderWindow* window) {
    DisplayArea::drawTo(window);

    if (!sf::Shader::isAvailable())
    {
        for (FormattedLine* line : *lines) {
            line->drawTo(window, window);
        }
    }
    else
    {
        glitchWindow->clear(sf::Color::Black);
        for (FormattedLine* line : *lines) {
            line->drawTo(window, glitchWindow);
        }
        sf::Shader shader;

        if (!shader.loadFromFile("../Resources/Shaders/textGlitch.frag", sf::Shader::Fragment)) {
            // error...
        }
        sf::Texture* tex = new sf::Texture();
        tex->create(1920, 1080);
        tex->update(*glitchWindow);
        shader.setUniform("texture", *tex);
        sf::Sprite sprite;
        sprite.setTexture(*tex);
        window->draw(sprite, &shader);
        delete tex;
    }
}

void TextOutput::addLine(sf::String string) {
    FormattedLine* newLine = new FormattedLine(string, sf::Vector2f(lines->back()->getRect().left, lines->back()->getRect().top+lines->back()->getRect().height)) ;
    //format line
    lines->push_back(newLine);
}

void TextOutput::toggleGlitch() {
    for(FormattedLine* line : *lines){
        line->toggleGlitch();
    }
}


