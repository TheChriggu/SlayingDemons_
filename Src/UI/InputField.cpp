//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include <iostream>
#include <memory>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/PossibleWordsCreatedEventArgs.h>

// TODO(FK): clean up name
sd::InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("input-field")
    , Subscriber()
{

    text_ = std::make_shared<sf::Text>();
    text_->setPosition(position + sf::Vector2f(10, 10));
    
    text_processor_ = std::make_shared<InputTextProcessor>();
}

bool sd::InputField::setup() {
    

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
    std::cout << "Code: " << input << std::endl;
    
    sf::String result = text_->getString();
    if(input == 8)
    {
        if (result.getSize() > 0)
        {
            result.erase(result.getSize() - 1, 1);
            text_->setString(result);
            possible_words_->trim_last_on_search_prefix();
        }
        
        return;
    }
    else if(input != 13)
    {
        result += static_cast<char>(input);
    }

    text_->setString(result);
    
    if (input != 32)
        possible_words_->add_to_search_prefix(std::string(1, static_cast<char>(input)));
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
            
            switch(possible_words_->get_current_list_type()) {
                case Word::Type::ACTION:
                    possible_words_->display_modifiers();
                    break;
                case Word::Type::UNKNOWN:
                    possible_words_->display_commands();
                    break;
                case Word::Type::COMMAND:
                    possible_words_->display_commands();
                    break;
            }
            possible_words_->set_search_prefix("");
    
            ScriptEngine::get().broadcast("input_received", strg.toAnsiString());
        }
    }
    else if (event.key.code == sf::Keyboard::Space)
    {
        if (event.type == sf::Event::KeyPressed) {
            if(possible_words_->get_current_list_type() == Word::Type::MODIFIER) {
                //Complete Word
                possible_words_->set_search_prefix("");
                possible_words_->display_actions();
                
            }
            else if(possible_words_->get_current_list_type() == Word::Type::ACTION)
            {
                //possible_words_->display_commands(); //placeholder to check if this line is reached

                //Complete word
                possible_words_->set_search_prefix("");
            }
            else if(possible_words_->get_current_list_type() == Word::Type::COMMAND)
            {
                //possible_words_->display_modifiers(); //placeholder to check if this line is reached

                //Complete word
                //switch to list of room objects
                possible_words_->set_search_prefix("");
            }
        }
    }
    else if(event.type == sf::Event::TextEntered)
    {
        add_text (event.text.unicode);
    }
    
    if (event.key.code == sf::Keyboard::BackSpace) {
        possible_words_->set_search_prefix(text_->getString().toAnsiString());
    }
}

sf::Vector2f sd::InputField::get_size() {
    return text_->getScale();
}

sf::Vector2f sd::InputField::get_position() {
    return text_->getPosition();
}

void sd::InputField::handle(Sp<sd::EventArgs> e)
{
    if (e->type == EventArgs::Type::POSSIBLE_WORDS_CREATED) {
        auto args = std::dynamic_pointer_cast<PossibleWordsCreatedEventArgs>(e);
    
        possible_words_ = Sp<PossibleWords>(args->possible_words);
    }
}


