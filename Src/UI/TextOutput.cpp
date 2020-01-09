//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>
#include <memory>
#include <Event/EventSystem.h>
#include <Event/TextOutputCreatedEventArgs.h>

//TODO(CH): Lines have to move up, when max is reached.
// TODO(FK): clean up name
sd::TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("text-output")
{
    lines = new std::list<FormattedLine*>();
    lines->push_back(new FormattedLine("", sf::Vector2f(position + sf::Vector2f(20, 20))));
    text = "";

    glitchTexture = new sf::RenderTexture();
    if(!glitchTexture->create(1920,1080))
    {
        std::cout << "could not create render texture for output\n";
    }


    glitchSprite = new sf::Sprite();
    glitchSprite->setTexture(glitchTexture->getTexture());

    maxSize = size;
    maxSize.y = 450; //TODO: This is not good

    shader = new sf::Shader();
    if (!shader->loadFromFile("../Resources/Shaders/textGlitch.frag", sf::Shader::Fragment)) {
        // error...
    }

    auto pt = std::make_shared<TextOutputCreatedEventArgs>(this);

    EventSystem::Get().Trigger(pt);
}

sd::TextOutput::~TextOutput() {
    delete lines;
    lines = nullptr;

    delete glitchTexture;
    glitchTexture = nullptr;

    delete glitchSprite;
    glitchSprite = nullptr;

    delete shader;
    shader = nullptr;
}

void sd::TextOutput::DrawTo(sf::RenderTarget* window) const {

    if (!sf::Shader::isAvailable())
    {
        for (FormattedLine* line : *lines) {
            line->drawTo(window, window);
        }
    }
    else
    {
        glitchTexture->clear(sf::Color::White);
        //glitchTexture->draw(*honkerSprite, shader);

        for (FormattedLine* line : *lines) {
            line->drawTo(window, glitchTexture);
        }


        glitchTexture->display();
        //shader->setUniform("texture", glitchTexture->getTexture());
        window->draw(*glitchSprite, shader);
    }

}

void sd::TextOutput::addLine(sf::String string) {
    FormattedLine* newLine = new FormattedLine(string, sf::Vector2f(lines->back()->getRect().left, lines->back()->getRect().top+lines->back()->getRect().height)) ;
    //format line
    lines->push_back(newLine);
    while(GetSize().y > maxSize.y)
    {
        float distance = lines->front()->getRect().height;
        MoveVertical(-distance);
        lines->pop_front();
    }

}

void sd::TextOutput::toggleGlitch() {
    for(FormattedLine* line : *lines){
        line->toggleGlitch();
    }
}

void sd::TextOutput::Handle(sf::Event event) {

}

sf::Vector2f sd::TextOutput::GetPosition() {
    //TODO(CH): GetPosition function. Based on lines? or saved in variable?
    return DrawableObject::GetPosition();
}

sf::Vector2f sd::TextOutput::GetSize() {
    sf::Vector2f retVal;
    retVal.x = 0;
    retVal.y = 0;

    for (FormattedLine* line : *lines)
    {
        sf::FloatRect rect = line->getRect();
        if (rect.width > retVal.x)
        {
            retVal.x = rect.width;
        }

        retVal.y += rect.height;
    }

    return retVal;
}

void sd::TextOutput::MoveVertical(float distance) {
    for(FormattedLine* line : *lines){
        line->MoveVertical(distance);
    }
}

void sd::TextOutput::Update(sf::RenderTarget* window) {
    glitchTexture->clear(sf::Color::White);

    for (FormattedLine* line : *lines) {
        line->drawTo(window, glitchTexture);
    }


    glitchTexture->display();
}


