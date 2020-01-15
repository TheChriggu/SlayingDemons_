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
    class PossibleWords: public DrawableObject, public Subscriber {
    private:
        std::vector<sp<FormattedLine>> lines;
        sp<PlayerVocabulary> playerVocabulary;

        sp<sf::Sprite> sprite;
        sp<sf::Texture> texture;
        sf::Vector2f position;
        sf::Vector2f size;

    public:
        PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& pathToBackground);
        ~PossibleWords() override = default;

        bool Setup() override;
        void Update();

        void DrawTo(sp<sf::RenderTarget> window) const override;

        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;

        void Handle(sf::Event event) override;
        void Handle(std::shared_ptr<EventArgs> e) override;


    };
}

#endif //SLAYINGDEMONS_POSSIBLEWORDS_H
