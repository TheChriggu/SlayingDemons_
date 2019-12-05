//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include <iostream>

sd::InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color, TextOutput* output)
    : output_(output)
    {
    textProcessor = new InputTextProcessor();
    textProcessor->SetOutput(output);

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
    delete text;
    text = nullptr;
    delete output_;
    output_ = nullptr;
    delete textProcessor;
    textProcessor = nullptr;
}

void sd::InputField::addText(sf::Uint32 input) {
    std::cout << "Adding text. received character is: " << input;
    sf::String result = text->getString();
    if(input == 8 && result.getSize() > 0)
    {
        result.erase(result.getSize()-1,1);
    }
    else if(input != 13)
    {
        result += static_cast<char>(input);
    }

    text->setString(result);
}

void sd::InputField::DrawTo(sf::RenderTarget *window) const {
    window->draw(*text);
}

void sd::InputField::Handle(sf::Event event) {
    if(event.key.code == sf::Keyboard::Enter)
    {
        if(event.type == sf::Event::KeyPressed)
        {
        std::cout << "processing input\n";
        sf::String strg = text->getString();

        textProcessor->ProcessInput(strg);
        text->setString("");

        //std::vector<sf::String> strings = textProcessor->SplitBySpace(text->getString());



        //for(sf::String string : strings)
        //{
        //
        //}
        }
    }
    else if (event.type == sf::Event::TextEntered)
    {
        sf::Uint32 input = event.text.unicode;
        addText(input);
    }
    //if(event.type == sf::Event::KeyPressed)
    //{
        //std::cout << "key released\n";


    //}


}
