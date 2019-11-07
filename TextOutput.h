//
// Created by christian.heusser on 06.11.2019.
//

#ifndef UNTITLED_TEXTOUTPUT_H
#define UNTITLED_TEXTOUTPUT_H
#include "DisplayArea.h"
#include "TextGlitch.h"
#include <list>
#include "FormattedLine.h"


class TextOutput: public DisplayArea {

    sf::String text;
    //TextGlitch* glitch;
    std::list<FormattedLine*>* lines;
public:
    TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~TextOutput();

    void addLine(sf::String string);
    void addText(sf::Uint32 input);
    //void addText(sf::String input);
    void enterPressed();


    void drawTo(sf::RenderWindow* window) override;
};


#endif //UNTITLED_TEXTOUTPUT_H
