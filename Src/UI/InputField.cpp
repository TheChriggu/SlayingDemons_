//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include <iostream>
#include <memory>
#include <ScriptEngine/ScriptEngine.h>

// TODO(FK): clean up name
sd::InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("input-field")
{

    text_ = std::make_shared<sf::Text>();
    text_->setPosition(position + sf::Vector2f(10, 10));
}

bool sd::InputField::setup() {
    text_processor_ = std::make_shared<InputTextProcessor>();

    auto* font = new sf::Font();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return false;
    }

    text_->setFont(*font);
    text_->setString("");
    text_->setCharacterSize(24);
    text_->setFillColor(sf::Color::Black);

    return DrawableObject::setup ();
}

void sd::InputField::add_text(sf::Uint32 input) {
    sf::String result = text_->getString();
    if(input == 8 && result.getSize() > 0)
    {
        result.erase(result.getSize()-1,1);
    }
    else if(input != 13)
    {
        result += static_cast<char>(input);
    }

    text_->setString(result);
}

void sd::InputField::draw_to(Sp<sf::RenderTarget> window) const {
    window->draw(*text_);
}

void sd::InputField::handle(sf::Event event) {
    if(event.key.code == sf::Keyboard::Enter)
    {
        if(event.type == sf::Event::KeyPressed)
        {
        
            sf::String strg = text_->getString();
    
            text_processor_->process_input(strg.toAnsiString());
            text_->setString("");
    
            ScriptEngine::get().broadcast("input_received", strg.toAnsiString());

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
        add_text (input);
    }
    //if(event.type == sf::Event::KeyPressed)
    //{
        //std::cout << "key released\n";


    //}


}

sf::Vector2f sd::InputField::get_size() {
    return text_->getScale();
}

sf::Vector2f sd::InputField::get_position() {
    return text_->getPosition();
}


