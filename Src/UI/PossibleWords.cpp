//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include <Event/FontsCreatedEventArgs.h>
#include "PossibleWords.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& path_to_background)
    : DrawableObject("possible-words")
    , Subscriber()
    , position_(position)
    , size_(size)
    , current_list_type_(Word::UNKNOWN)
{
    sprite_ = std::make_shared<sf::Sprite>();
    texture_ = std::make_shared<sf::Texture>();
}

bool sd::PossibleWords::setup() {

    texture_->loadFromFile("../Resources/Sprites/fantasy_input.png");
    sprite_->setTexture(*texture_, false);
    sprite_->setPosition(position_);

    return DrawableObject::setup ();
}

void sd::PossibleWords::draw_to(Sp<sf::RenderTarget> window) const {
    window->draw(*sprite_);

    for(const auto& line : lines_)
    {
        line->draw_to (window);
    }
}

void sd::PossibleWords::handle(sf::Event event) {

}

void sd::PossibleWords::update(std::vector<std::string>& content) {
    lines_.clear();

    
    sf::Vector2f offset = sf::Vector2f(50, 90);
        
    for(const auto& word : content)
    {
        lines_.push_back(std::make_shared<FormattedLine>(
                word,
                sf::Vector2f(position_ + offset),
                sf::Vector2f(1000,1000),
                        fonts_));
        offset.y += 30;
    }

    /*offset = sf::Vector2f(250, 90);
    for(const auto& action : player_vocabulary_->get_actions())
    {
        lines_.push_back(std::make_shared<FormattedLine>(action,
                                                         sf::Vector2f(position_ + offset),
                                                         sf::Vector2f(1000,1000),fonts_));
            offset.y += 30;
        }
    }
    else
    {

    }*/
}

void sd::PossibleWords::handle(std::shared_ptr<EventArgs> e) {
    /*if (e->type == sd::EventArgs::Type::PLAYER_VOCAB_CHANGED) {
        auto args = std::dynamic_pointer_cast<PlayerVocabChangedEventArgs>(e);
        
        switch (args->change_type) {
            case Word::ACTION:
                update()
                break;
        }
    }*/

    if (e->type == sd::EventArgs::Type::FIGHT_STARTED) {
        update(player_vocabulary_->get_modifiers());
    }
    if (e->type == sd::EventArgs::Type::FIGHT_ENDED) {
        update(player_vocabulary_->get_commands());
    }
    
    if (e->type == sd::EventArgs::Type::PLAYER_STATE_CREATED) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs *>(e.get());
        
        player_vocabulary_ = args->player_state->get_player_vocabulary();
        player_state_ = Sp<PlayerState>(args->player_state);
        
        std::cout << "~~Words: " << std::endl;
        for (const auto& word : player_vocabulary_->get_modifiers())
            std::cout << "~" << word << std::endl;

        update (player_vocabulary_->get_commands());
    }

    if (e->type == EventArgs::Type::FONTS_CREATED) {
        auto arg = dynamic_cast<FontsCreatedEventArgs*>(e.get());
        fonts_ = Sp<Font>(arg->fonts);
     }
}

sf::Vector2f sd::PossibleWords::get_position() {
    return position_;
}

sf::Vector2f sd::PossibleWords::get_size() {
    return size_;
}


