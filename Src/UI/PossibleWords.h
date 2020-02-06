//
// Created by christian.heusser on 07.01.2020.
//

#ifndef _POSSIBLEWORDS_H_
#define _POSSIBLEWORDS_H_

#include "Core/DrawableObject.h"
#include "FormattedLine.h"
#include <vector>
#include "PlayerVocabulary.h"
#include "PlayerState.h"

namespace sd {
    class PossibleWords: public DrawableObject, public Subscriber {
    private:
        std::vector<Sp<FormattedLine>> lines_;
        Sp<PlayerVocabulary> player_vocabulary_;
        Sp<PlayerState> player_state_;
        Sp<Font> fonts_;

        Sp<sf::Sprite> sprite_;
        Sp<sf::Texture> texture_;
        sf::Vector2f position_;
        sf::Vector2f size_;
        
        Word::Type current_list_type_;
        
        std::string search_prefix_;

    public:
        PossibleWords(sf::Vector2f position, sf::Vector2f size, const std::string& path_to_background);
        ~PossibleWords() override = default;

        bool setup() override;
        void update(std::vector<std::string>& content);
        
        void display_modifiers();
        void display_actions();
        void display_commands();
        
        void set_search_prefix(const std::string& prefix);
        void add_to_search_prefix(const std::string& prefix);
        [[nodiscard]] const std::string& get_search_prefix() const;
        
        [[nodiscard]] Word::Type get_current_list_type() const;

        void draw_to(Sp<sf::RenderTarget> window) const override;

        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;

        void handle(sf::Event event) override;
        void handle(std::shared_ptr<EventArgs> e) override;


    };
}

#endif //_POSSIBLEWORDS_H_
