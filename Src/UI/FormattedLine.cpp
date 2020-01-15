//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedLine.h"
#include <memory>

FormattedLine::FormattedLine(const sf::String& string, sf::Vector2f _position, const sp<sf::Font>& _font, sf::Vector2f _maxSize) {
    font = _font;
    position = _position;
    maxSize = _maxSize;
    words.push_back(std::make_shared<FormattedWord>("", _position, _font));
    FormatLine(string, _font);

}

void FormattedLine::drawTo(const sp<sf::RenderTarget>& window) {
    for (const auto& word : words) {
        word->drawTo(window);
    }
}

void FormattedLine::FormatLine(sf::String string, const sp<sf::Font>& _font) {
    /*std::vector<std::string> splitVec;
    std::string delims = " []";
    boost::split(splitVec, string, boost::algorithm::is_any_of(delims));*/

    sf::Vector2f nextPosition =  sf::Vector2f(getRect().left,getRect().top+ getRect().height);
    sf::String word = " ";
    for(auto c = string.begin(); c != string.end(); c++)
    {
        if(sf::String(*c) != ' ' && c != string.end()-1)
        {
            word += *c;
        }

        else
        {
            if(c == string.end()-1)
            {
                word += *c;
            }

            /*if(nextPosition.x > maxSize.x)
            {
                nextPosition = sf::Vector2f(getRect().left, getRect().top + getRect().height);
            }*/

           sp<FormattedWord> newWord = std::make_shared<FormattedWord>(FormattedWord(word, nextPosition, _font));
           nextPosition.x += newWord->getRect().width;
            if(nextPosition.x > maxSize.x)
            {
                nextPosition = sf::Vector2f(getRect().left, getRect().top + getRect().height);
                newWord->setPosition(nextPosition);
                nextPosition.x += newWord->getRect().width;
            }

           words.push_back(newWord);
           word = " ";
        }
    }

    /*FormattedWord* newWord = new FormattedWord(word, false, sf::Vector2f(getRect().left + getRect().width,getRect().top), _font);
    words->push_back(newWord);*/
}

sf::FloatRect FormattedLine::getRect(){
    sf::FloatRect retVal = words.front()->getRect();

    for (const auto& word : words)
    {
        sf::FloatRect rect = word->getRect();
        if (rect.top < retVal.top)
        {
            retVal.top = rect.top;
        }
        if (rect.left < retVal.left)
        {
            retVal.left = rect.left;
        }
        if (rect.top + rect.height > retVal.top + retVal.height)
        {
            retVal.height = rect.top + rect.height - retVal.top;
        }
        if (rect.left + rect.width > retVal.left + retVal.width)
        {
            retVal.width = rect.left + rect.width - retVal.left;
        }
    }
    return retVal;
}

void FormattedLine::MoveVertical(float distance) {
    position.y += distance;
    for(const auto& word : words)
    {
        word->MoveVertical(distance);
    }
}

