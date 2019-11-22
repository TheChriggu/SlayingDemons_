//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include <iostream>

InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color) : DisplayArea(position, size, color){
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
    text->setFillColor(sf::Color::Black);
    text->setPosition(backgroundImage->getPosition() + sf::Vector2f(10,10));
}

InputField::~InputField() {

}

void InputField::addText(sf::Uint32 input) {
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

sf::String InputField::getTextAndClear() {
    sf::String retVal = text->getString();
    text ->setString("");
    return retVal;
}

void InputField::drawTo(sf::RenderWindow *window) {
    DisplayArea::drawTo(window);
    window->draw(*text);
}
