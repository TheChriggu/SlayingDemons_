//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>

TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color) : DisplayArea(position, size, color) {
    lines = new std::list<FormattedLine*>();
    lines->push_back(new FormattedLine("", sf::Vector2f(backgroundImage->getPosition()+sf::Vector2f(20,20))));
    text = "";

}

TextOutput::~TextOutput() {
    delete lines;
    lines = nullptr;
}

void TextOutput::drawTo(sf::RenderWindow *window) {
    DisplayArea::drawTo(window);

    for (FormattedLine* line : *lines) {
        line->drawTo(window);
    }
    /*window->draw(*text);

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
        delete tex;
    }*/
}

void TextOutput::addLine(sf::String string) {
    FormattedLine* newLine = new FormattedLine(string, sf::Vector2f(lines->back()->getRect().left, lines->back()->getRect().top+lines->back()->getRect().height)) ;
    //format line
    lines->push_back(newLine);
}


void TextOutput::addText(sf::Uint32 input) {
    sf::String result = text;
    if(input == 8 && result.getSize() > 0)
    {
        result.erase(result.getSize()-1,1);
    }
    else
    {
        result += static_cast<char>(input);
    }

    text = result;
}

void TextOutput::enterPressed() {
    addLine(text);
    text = "";
}
/*
void TextOutput::addText(sf::String input) {
    sf::String result = text->getString();

     result += input;

    text->setString(result);
}*/


