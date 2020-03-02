//
// Created by christian.heusser on 07.11.2019.
//

#include "InputField.h"
#include "Event/EventSystem.h"
#include <iostream>
#include <memory>
#include <ScriptEngine/ScriptEngine.h>
#include <Event/PossibleWordsCreatedEventArgs.h>
#include "Event/ClickableWordClickedEventArgs.h"

// TODO(FK): clean up name
sd::InputField::InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("input-field")
    , Subscriber()
{
    event_handler_ = CREATE_EVENT_HANDLER(
        if (e->type == EventArgs::Type::POSSIBLE_WORDS_CREATED) {
            auto args = std::dynamic_pointer_cast<PossibleWordsCreatedEventArgs>(e);
        
            possible_words_ = args->possible_words;
        }
        if (e->type == EventArgs::Type::CLICKABLE_WORD_CLICKED) {
            auto args = std::dynamic_pointer_cast<ClickableWordClickedEventArgs>(e);

             for(auto letter : args->word)
             {
                 add_text(letter);
             }
        }
        );
    
    REGISTER_EVENT_HANDLER();
    
    //single_word_pattern_ = std::regex()

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
    //std::cout << "Code: " << input << std::endl;
    
    sf::String result = text_->getString();
    if(input == UNI_BACKSPACE)
    {
        if (result.getSize() > 0)
        {
            result.erase(result.getSize() - 1, 1);
        }
    }
    else if(input != UNI_ENTER)
    {
        result += static_cast<char>(input);
    }

    text_->setString(result);
    
    possible_words_->update_search_prefix(text_->getString().toAnsiString());
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
                case Word::Type::OBJECT:
                    possible_words_->display_commands();
                    break;
            }
            possible_words_->set_search_prefix("");
    
            ScriptEngine::get().broadcast("input_received", strg.toAnsiString());
        }
    }
    else if (event.key.code == sf::Keyboard::Space)
    {
        if (event.type == sf::Event::KeyPressed &&
            std::regex_match(text_->getString().toAnsiString(), InputTextProcessor::single_word_pattern))
        {
            
            switch(possible_words_->get_current_list_type()) {
                case Word::Type::MODIFIER:
                    possible_words_->display_actions();
                    break;
                case Word::Type::COMMAND:
                    possible_words_->display_objects();
                    break;
            }
            
        }
    }
    else if (event.key.code == sf::Keyboard::BackSpace)
    {
        if (event.type == sf::Event::KeyPressed &&
            std::regex_match(text_->getString().toAnsiString(), InputTextProcessor::single_word_without_trail_pattern))
        {
            switch(possible_words_->get_current_list_type()) {
                case Word::Type::ACTION:
                    possible_words_->display_modifiers();
                    break;
                case Word::Type::OBJECT:
                    possible_words_->display_commands();
                    break;
            }
        }
    }
    else if(event.type == sf::Event::TextEntered)
    {
        add_text (event.text.unicode);
    }
}

sf::Vector2f sd::InputField::get_size() {
    return text_->getScale();
}

sf::Vector2f sd::InputField::get_position() {
    return text_->getPosition();
}


