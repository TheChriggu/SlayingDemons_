//
// Created by christian.heusser on 06.11.2019.
//

#include "TextOutput.h"
#include <iostream>
#include <memory>
#include <Event/EventSystem.h>
#include <Event/TextOutputCreatedEventArgs.h>
#include <Event/LineToOutputEventArgs.h>
#include <ScriptEngine/ScriptEngine.h>

//TODO(CH): Lines have to move up, when max is reached.
// TODO(FK): clean up name
sd::TextOutput::TextOutput(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("text-output")
    , Subscriber()
    , start_position_(position)
{


    maxSize = size;
    maxSize.y = 450; //TODO: This is not good
}

bool sd::TextOutput::Setup() {
    ScriptEngine::Get()->RegisterAll("print_line", &TextOutput::printLine, this);

    font = std::make_shared<sf::Font>();

    if (!font->loadFromFile("../Resources/Fonts/comic.ttf"))
    {
        std::cout << "Could not load Font!\n";
        return false;
    }

    lines.push_back(std::make_shared<FormattedLine>(
            "",
            sf::Vector2f(start_position_ + sf::Vector2f(20, 20)),
            font,
            maxSize));

    // Trigger TextOutput Created Event
    EventSystem::Get().Trigger(std::make_shared<TextOutputCreatedEventArgs>(sp<TextOutput>(this)));

    return DrawableObject::Setup();
}

void sd::TextOutput::DrawTo(sp<sf::RenderTarget> window) const {
    // TODO(CH): There is no need to query this condition. Removed because causing Output to not be drawing anymore
    /*if (!sf::Shader::isAvailable())
    {
        for (const auto& line : lines) {
            line->drawTo(window, window);
        }
    }*/
    for (const auto& line : lines) {
        line->drawTo(window);
    }
}

void sd::TextOutput::addLine(const sf::String& string) {

    auto newLine = std::make_shared<FormattedLine>(
            string, sf::Vector2f(
                    lines.back()->getRect().left,
                    lines.back()->getRect().top + lines.back()->getRect().height),
                            font,
                            maxSize
    );

    //format line
    lines.push_back(newLine);
    while(GetSize().y > maxSize.y)
    {
        float distance = lines.front()->getRect().height;
        MoveVertical(-distance);
        lines.pop_front();
    }

}

void sd::TextOutput::printLine(const std::string& string) {
    sf::String temp(string);
    addLine(temp);
}

void sd::TextOutput::Handle(sf::Event event) {

}

sf::Vector2f sd::TextOutput::GetPosition() {
    //TODO(CH): GetPosition function. Based on lines? or saved in variable?
    return sf::Vector2f();
}

sf::Vector2f sd::TextOutput::GetSize() {
    sf::Vector2f retVal;
    retVal.x = 0;
    retVal.y = 0;

    for (const auto& line : lines)
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
    for(const auto& line : lines){
        line->MoveVertical(distance);
    }
}

void sd::TextOutput::Handle(std::shared_ptr<EventArgs> e) {
    if (e->type == EventArgs::Type::LineToOutput) {
        auto arg = dynamic_cast<LineToOutputEventArgs*>(e.get());

        addLine(arg->line);
    }
}




