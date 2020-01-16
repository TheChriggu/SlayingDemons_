//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include "PossibleWords.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& path_to_background)
    : DrawableObject("possible-words")
    , Subscriber()
    , position_(position)
    , size_(size)
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

void sd::PossibleWords::update() {
    Sp<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    lines_.clear();

    if(playerState->IsFighting()) {
        sf::Vector2f offset = sf::Vector2f(50, 90);
    for(const auto& action : *(player_vocabulary_->GetModifiers()))
    {
        lines_.push_back(std::make_shared<FormattedLine>(
                action,
                sf::Vector2f(position_ + offset),
                font,
                sf::Vector2f(1000,1000)));
            offset.y += 30;
        }

        offset = sf::Vector2f(250, 90);
    for(const auto& action : *(player_vocabulary_->GetActions()))
    {
        lines_.push_back(std::make_shared<FormattedLine>(action,
                                                         sf::Vector2f(position_ + offset),
                                                         font,
                                                         sf::Vector2f(1000,1000)));
            offset.y += 30;
        }
    }
    else
    {

    }
}

void sd::PossibleWords::handle(std::shared_ptr<EventArgs> e) {
    if (e->type == sd::EventArgs::Type::PLAYER_VOCAB_CHANGED) {
        update ();
    }

    if (_e->type == sd::EventArgs::Type::FIGHT_STARTED) {
        Update();
    }
    if (_e->type == sd::EventArgs::Type::FIGHT_ENDED) {
        Update();
    }
    
    if (e->type == sd::EventArgs::Type::PLAYER_STATE_CREATED) {
        auto args = dynamic_cast<PlayerStateCreatedEventArgs *>(e.get());



        player_vocabulary_ = Sp<PlayerVocabulary>(args->player_state->GetPlayerVocabulary());
        playerState = e->player_state;

        update ();
    }
}

sf::Vector2f sd::PossibleWords::get_position() {
    return position_;
}

sf::Vector2f sd::PossibleWords::get_size() {
    return size_;
}


