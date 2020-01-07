//
// Created by christian.heusser on 07.01.2020.
//

#ifndef SLAYINGDEMONS_POSSIBLEWORDS_H
#define SLAYINGDEMONS_POSSIBLEWORDS_H

#include "Core/DrawableObject.h"
#include "FormattedLine.h"
#include <vector>
#include "PlayerVocabulary.h"

namespace sd {
    class PossibleWords: public DrawableObject {
    private:
        std::vector<FormattedLine*>* lines;
        PlayerVocabulary* playerVocabulary;

        sf::Sprite* sprite;
        sf::Texture* texture;
        sf::Vector2f position;
        sf::Vector2f size;



    public:
        PossibleWords(sf::Vector2f position, sf::Vector2f size, std::string pathToBackground);
        ~PossibleWords();

        void DrawTo(sf::RenderTarget* window) const override;
        void SetPlayerVocab(PlayerVocabulary* _playerVocabulary);

        void Handle(sf::Event event) override;

        void Update();
    };
}

#endif //SLAYINGDEMONS_POSSIBLEWORDS_H
