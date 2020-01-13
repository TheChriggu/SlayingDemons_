//
// Created by christian.heusser on 07.01.2020.
//

#include <Event/PlayerVocabChangedEventArgs.h>
#include <Event/PlayerStateCreatedEventArgs.h>
#include "PossibleWords.h"

// TODO(FK): clean up name
sd::PossibleWords::PossibleWords(sf::Vector2f _position, sf::Vector2f _size, std::string pathToBackground)
    : DrawableObject("possible-words")
    , Subscriber()
    , position(_position)
    , size(_size)
{
    sprite = new sf::Sprite();
    texture = new sf::Texture();

    lines = new std::vector<FormattedLine*>();
}

sd::PossibleWords::~PossibleWords() {
    delete lines;
    lines = nullptr;

    playerVocabulary = nullptr;
}

bool sd::PossibleWords::Setup() {

    texture->loadFromFile("../Resources/Sprites/fantasy_input.png");
    sprite->setTexture(*texture, false);
    sprite->setPosition(position);

    return DrawableObject::Setup();
}

void sd::PossibleWords::DrawTo(sf::RenderTarget *window) const {
    window->draw(*sprite);

    for(auto line : *lines)
    {
        line->drawTo(window, window);
    }
}

void sd::PossibleWords::SetPlayerVocab(sd::PlayerVocabulary *_playerVocabulary) {
    playerVocabulary = _playerVocabulary;


}

void sd::PossibleWords::Handle(sf::Event event) {

}

void sd::PossibleWords::Update() {
    sf::Font* font = new sf::Font();
    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return;
    }

    lines->clear();

    sf::Vector2f offset = sf::Vector2f(50, 90);
    for(auto action : *(playerVocabulary->GetModifiers()))
    {
        lines->push_back(new FormattedLine(action, sf::Vector2f(position + offset), font, sf::Vector2f(1000,1000)));
        offset.y += 30;
    }

    offset = sf::Vector2f(250, 90);
    for(auto action : *(playerVocabulary->GetActions()))
    {
        lines->push_back(new FormattedLine(action, sf::Vector2f(position + offset), font, sf::Vector2f(1000,1000)));
        offset.y += 30;
    }
}

void sd::PossibleWords::Handle(std::shared_ptr<EventArgs> _e) {
    if (_e->type == sd::EventArgs::Type::PlayerVocabChanged) {
        //auto e = dynamic_cast<PlayerVocabChangedEventArgs *>(_e.get());

        Update();
    }

    if (_e->type == sd::EventArgs::Type::PlayerStateCreated) {
        auto e = dynamic_cast<PlayerStateCreatedEventArgs *>(_e.get());

        playerVocabulary = e->player_state->GetPlayerVocabulary();

        Update();
    }
}


