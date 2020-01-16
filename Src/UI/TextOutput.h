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


namespace sd {
    class TextOutput: public DrawableObject, public Subscriber {

        std::list<Sp<FormattedLine>> lines_;
        sf::Vector2f max_size_;
        Sp<sf::Font> font_;

        // TODO(CH): rework this Class! Position of an asset should not be determent by "old" data!
        sf::Vector2f start_position_;

    public:
        TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~TextOutput() override = default;

        bool setup() override;

        void add_line(const sf::String& string);
        void print_line(const std::string& string);

        void draw_to(Sp<sf::RenderTarget> window) const override;
        sf::Vector2f get_position() override;
        sf::Vector2f get_size() override;
        void move_vertical(float distance);

        void handle(sf::Event event) override;
        void handle(std::shared_ptr<EventArgs> e) override;
    };
}


#endif //_TEXTOUTPUT_H_
