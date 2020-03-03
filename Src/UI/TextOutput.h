//
// Created by christian.heusser on 06.11.2019.
//

#ifndef _TEXTOUTPUT_H_
#define _TEXTOUTPUT_H_

#include "Core/DrawableObject.h"
#include "TextGlitch.h"
#include <list>
#include <Event/Subscriber.h>
#include "FormattedLine.h"
#include "Font.h"
#include "Colors.h"


namespace sd {
    class TextOutput: public DrawableObject, public Subscriber, public std::enable_shared_from_this<TextOutput> {

        std::list<Sp<FormattedLine>> lines_;
        sf::Vector2f max_size_;
        Sp<Font> fonts_;
        Sp<Colors> colors_;

        sf::Vector2f position_;
        sf::Vector2f offset_;

        Sp<sf::RenderTexture> text_tex_;
        Sp<sf::Sprite> text_sprite_;

    public:
        TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~TextOutput() override = default;

        bool setup() override;

        void add_line(std::string string);
        void print_line(std::string string);

        void draw_to(Sp<sf::RenderTarget> window) const override;
        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;
        void move_vertical(float distance);

        void handle(sf::Event event) override;

        void reformat();
    };
}


#endif //_TEXTOUTPUT_H_
