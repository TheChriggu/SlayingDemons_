//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_TEXTOUTPUT_H
#define UNTITLED_TEXTOUTPUT_H
#include "DrawableObject.h"
#include "TextGlitch.h"
#include <list>
#include "FormattedLine.h"


namespace sd {
    class TextOutput: public DrawableObject {

        sf::String text;
        sf::RenderWindow* glitchWindow;
        std::list<FormattedLine*>* lines;
    public:
        TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~TextOutput();

        void addLine(sf::String string);

        void DrawTo(sf::RenderWindow* window) const override;
        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;
        void toggleGlitch();

        void Handle(sf::Event event) override;
    };
}


#endif //UNTITLED_TEXTOUTPUT_H
