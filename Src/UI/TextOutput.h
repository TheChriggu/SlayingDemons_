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

        sf::String text;
        sf::RenderTexture* glitchTexture;
        sf::Sprite* glitchSprite;
        std::list<FormattedLine*>* lines;
        sf::Vector2f maxSize;
        sf::Shader* shader;
        sf::Font* font;

    public:
        TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
        ~TextOutput();

        void addLine(sf::String string);

        void DrawTo(sf::RenderTarget* window) const override;
        sf::Vector2f GetPosition() override;
        sf::Vector2f GetSize() override;
        void toggleGlitch();
        void MoveVertical(float distance);
        void Update(sf::RenderTarget* window);

        void Handle(sf::Event event) override;
        void Handle(std::shared_ptr<EventArgs> e) override;
    };
}


#endif //UNTITLED_TEXTOUTPUT_H
