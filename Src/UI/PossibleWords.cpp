//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include "PossibleWords.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f _position, sf::Vector2f _size, const std::string& pathToBackground)
    : DrawableObject("possible-words")
    , Subscriber()
    , position(_position)
    , size(_size)
{
    sprite = std::make_shared<sf::Sprite>();
    texture = std::make_shared<sf::Texture>();
}

bool sd::PossibleWords::Setup() {

    texture->loadFromFile("../Resources/Sprites/fantasy_input.png");
    sprite->setTexture(*texture, false);
    sprite->setPosition(position);

    return DrawableObject::Setup();
}

void sd::PossibleWords::DrawTo(sp<sf::RenderTarget> window) const {
    window->draw(*sprite);

    for(const auto& line : lines)
    {
        line->drawTo(window);
    }
}

void sd::PossibleWords::Handle(sf::Event event) {

}

void sd::PossibleWords::Update() {
    sp<sf::Font> font = std::make_shared<sf::Font>();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    lines.clear();

    if(playerState->IsFighting()) {
        sf::Vector2f offset = sf::Vector2f(50, 90);
    for(const auto& action : *(playerVocabulary->GetModifiers()))
            lines->push_back(
        lines.push_back(std::make_shared<FormattedLine>(
                action,
                sf::Vector2f(position + offset),
                font,
                sf::Vector2f(1000,1000)));
            offset.y += 30;
        }

        offset = sf::Vector2f(250, 90);
    for(const auto& action : *(playerVocabulary->GetActions()))
            lines->push_back(
        lines.push_back(std::make_shared<FormattedLine>(action,
                sf::Vector2f(position + offset),
                font,
                sf::Vector2f(1000,1000)));
            offset.y += 30;
        }
    }
    else
    {

    }
}

void sd::PossibleWords::Handle(std::shared_ptr<EventArgs> _e) {
    if (_e->type == sd::EventArgs::Type::PlayerVocabChanged) {
        Update();
    }

    if (_e->type == sd::EventArgs::Type::FightStarted) {
        Update();
    }
    if (_e->type == sd::EventArgs::Type::FightEnded) {
        Update();
    }

    if (_e->type == sd::EventArgs::Type::PlayerStateCreated) {
        auto e = dynamic_cast<PlayerStateCreatedEventArgs *>(_e.get());

        playerVocabulary = sp<PlayerVocabulary>(e->player_state->GetPlayerVocabulary());
        playerState = e->player_state;

        Update();
    }
}

sf::Vector2f sd::PossibleWords::GetPosition() {
    return position;
}

sf::Vector2f sd::PossibleWords::GetSize() {
    return size;
}


