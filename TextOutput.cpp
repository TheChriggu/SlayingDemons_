//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>

TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color) : DisplayArea(position, size, color) {

    sf::Font* font = new sf::Font();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    text = new sf::Text();
    text->setFont(*font);
    text->setString("");
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Magenta);
    text->setPosition(position);

    glitch = new TextGlitch();
}

TextOutput::~TextOutput() {

}

void TextOutput::drawTo(sf::RenderWindow *window) {
    DisplayArea::drawTo(window);
    window->draw(*text);

    if (!sf::Shader::isAvailable())
    {
        window->draw(*text);

    }
    else
    {
        sf::Shader shader;

        if (!shader.loadFromFile("../Resources/Shaders/textGlitch.frag", sf::Shader::Fragment))
        {
            // error...
        }
        sf::Texture* tex = glitch->glitch(text);
        shader.setUniform("texture", *tex);
        sf::Sprite sprite;
        sprite.setTexture(*tex);
        window->draw(sprite, &shader);
    }
}

void TextOutput::addText(sf::Uint32 input) {
    sf::String result = text->getString();
    if(input == 8 && result.getSize() > 0)
    {
        result.erase(result.getSize()-1,1);
    }
    else
    {
        result += static_cast<char>(input);
    }

    text->setString(result);
}

void TextOutput::addText(sf::String input) {
    sf::String result = text->getString();

     result += input;

    text->setString(result);
}


