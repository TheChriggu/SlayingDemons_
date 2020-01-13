//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_TEXTOUTPUT_H
#define UNTITLED_TEXTOUTPUT_H
#include "Core/DrawableObject.h"
#include "TextGlitch.h"
#include <list>
#include <Event/Subscriber.h>
#include "FormattedLine.h"


namespace sd {
    class TextOutput: public DrawableObject, public Subscriber {

        std::list<sp<FormattedLine>> lines;
        sf::Vector2f maxSize;
        sp<sf::Font> font;

        // TODO(CH): rework this Class! Position of an asset should not be determent by "old" data!
        sf::Vector2f start_position_;

    public:
        TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~TextOutput() override = default;

        bool Setup() override;

        void addLine(sf::String string);
        void printLine(std::string string);

        void DrawTo(sf::RenderTarget* window) const override;
        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;
        void MoveVertical(float distance);

        void Handle(sf::Event event) override;
        void Handle(std::shared_ptr<EventArgs> e) override;
    };
}


#endif //UNTITLED_TEXTOUTPUT_H
