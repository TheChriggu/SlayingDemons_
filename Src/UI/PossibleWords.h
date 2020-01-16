//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _POSSIBLEWORDS_H_
#define _POSSIBLEWORDS_H_

#include "Core/DrawableObject.h"
#include "FormattedLine.h"
#include <vector>
#include "PlayerVocabulary.h"

namespace sd {
    class PossibleWords: public DrawableObject, public Subscriber {
    private:
        std::vector<Sp<FormattedLine>> lines_;
        Sp<PlayerVocabulary> player_vocabulary_;

        Sp<sf::Sprite> sprite_;
        Sp<sf::Texture> texture_;
        sf::Vector2f position_;
        sf::Vector2f size_;

    public:
        PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& path_to_background);
        ~PossibleWords() override = default;

        bool setup() override;
        void update();

        void draw_to(Sp<sf::RenderTarget> window) const override;

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;

        void handle(sf::Event event) override;
        void handle(std::shared_ptr<EventArgs> e) override;


    };
}

#endif //_POSSIBLEWORDS_H_
