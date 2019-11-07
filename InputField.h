//
// Created by christian.heusser on 07.11.2019.
//

#ifndef UNTITLED_INPUTFIELD_H
#define UNTITLED_INPUTFIELD_H
#include "DisplayArea.h"

class InputField : public DisplayArea{
    sf::Text* text;

public:
    InputField(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    ~InputField();

    void addText(sf::Uint32 input);
    sf::String getTextAndClear();

    void drawTo(sf::RenderWindow* window) override;
};


#endif //UNTITLED_INPUTFIELD_H
