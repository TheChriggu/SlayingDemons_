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
#include <Event/FontsCreatedEventArgs.h>
#include <Event/ColorsCreatedEventArgs.h>

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
        if (e->type == EventArgs::Type::FONTS_CREATED) {
            auto arg = std::dynamic_pointer_cast<FontsCreatedEventArgs>(e);
            fonts_ = Sp<Font>(arg->fonts);
        }
        if (e->type == EventArgs::Type::COLORS_CREATED) {
            auto arg = std::dynamic_pointer_cast<ColorsCreatedEventArgs>(e);
            colors_ = Sp<Colors>(arg->colors);
        }

        );
    
    REGISTER_EVENT_HANDLER();

    text_ = std::make_shared<sf::Text>();
    text_->setPosition(position + sf::Vector2f(10, 10));
    
    text_processor_ = std::make_shared<InputTextProcessor>();
}

bool sd::InputField::setup() {

    text_->setFont(*(fonts_->GetCurrentFont()));
    text_->setString("");
    text_->setCharacterSize(24);
    text_->setFillColor(colors_->GetCurrentColor());

    return DrawableObject::setup ();
}

void sd::InputField::add_text(sf::Uint32 input) {
    //std::cout << "Code: " << input << std::endl;
    
    if (input == UNI_ENTER || input == UNI_TAB)
        return;
    
    sf::String result = text_->getString();
    
    if(input == UNI_BACKSPACE)
    {
        if (result.getSize() > 0)
        {
            result.erase(result.getSize() - 1, 1);
        }
    } else {
        result += static_cast<char>(input);
    }
    
    
    text_->setString(result);
    
    possible_words_->update_search_prefix(text_->getString().toAnsiString());
}

void sd::InputField::draw_to(Sp<sf::RenderTarget> window) const {
    text_->setFont(*(fonts_->GetCurrentFont()));
    text_->setFillColor(colors_->GetCurrentColor());
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
        if (event.type == sf::Event::KeyPressed)
        {
            possible_words_->update_search_prefix(text_->getString().toAnsiString());
            
            auto input = text_->getString();
            input += possible_words_->complete_first_possible_word();
            text_->setString(input);
            possible_words_->update_search_prefix(input.toAnsiString());
            
            if (std::regex_match(text_->getString().toAnsiString(), InputTextProcessor::single_word_pattern)) {
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
    else if (event.key.code == sf::Keyboard::Tab)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            auto input = text_->getString().toAnsiString();
            auto completion = possible_words_->loop_through_possible_words();
            auto prefix = possible_words_->get_search_prefix();
            auto position = input.find_last_of(prefix) - (prefix.size() - 1);
            
            /*std::cout << "input: " << input << std::endl;
            std::cout << "completion: " << completion << std::endl;
            std::cout << "prefix: " << prefix.size() << std::endl;
            std::cout << "position: " << position << std::endl;
            std::cout << "last position: " << input.size() - 1 << std::endl;*/
            
            // deletes the prefix and anything thats behind it and then places the prefix with the rest of looped word behind it
            /*input = std::regex_replace(
                input,
                std::regex(prefix + ".*"),
                prefix + completion);*/
            input.replace(position, input.size(), prefix + completion);
            
            text_->setString(input);
        }
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
        if (event.type == sf::Event::KeyPressed)
        {
            possible_words_->update_search_prefix(text_->getString().toAnsiString());
            
            auto input = text_->getString();
            input += possible_words_->complete_first_possible_word();
            text_->setString(input);
            possible_words_->update_search_prefix(input.toAnsiString());
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


