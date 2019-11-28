//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include <iostream>

sd::InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color, TextOutput* output)
    : output_(output) {
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
    text->setPosition(position + sf::Vector2f(10, 10));
}

sd::InputField::~InputField() {

}

void sd::InputField::addText(sf::Uint32 input) {
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

sf::String sd::InputField::getTextAndClear() {
    sf::String retVal = text->getString();
    text ->setString("");
    return retVal;
}

void sd::InputField::DrawTo(sf::RenderWindow *window) const {
    window->draw(*text);
}

void sd::InputField::Handle(sf::Event event) {
    if (event.type == sf::Event::TextEntered)
    {
        sf::Uint32 input = event.text.unicode;
        addText(input);
    }
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Enter)
        {
            output_->addLine(getTextAndClear());
        }

    }
}
