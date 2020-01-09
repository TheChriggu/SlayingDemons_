//
// Created by christian.heusser on 07.11.2019.
//

#include "FormattedLine.h"

FormattedLine::FormattedLine(sf::String string, sf::Vector2f _position, sf::Font* _font, sf::Vector2f _maxSize) {
    words = new std::list<FormattedWord*>();
    position = _position;
    maxSize = _maxSize;
    words->push_back(new FormattedWord("", false, _position, _font));
    FormatLine(string, _font);

}

FormattedLine::~FormattedLine() {
    delete words;
    words = nullptr;
}

void FormattedLine::drawTo(sf::RenderTarget* window, sf::RenderTarget* glitchWindow) {
    for (FormattedWord* word : *words) {
        word->drawTo(window, glitchWindow);
    }
}

void FormattedLine::FormatLine(sf::String string, sf::Font* _font) {
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

           FormattedWord* newWord = new FormattedWord(word, false, nextPosition, _font);
           nextPosition.x += newWord->getRect().width;
            if(nextPosition.x > maxSize.x)
            {
                nextPosition = sf::Vector2f(getRect().left, getRect().top + getRect().height);
                newWord->setPosition(nextPosition);
                nextPosition.x += newWord->getRect().width;
            }

           words->push_back(newWord);
           word = " ";
        }
    }

    /*FormattedWord* newWord = new FormattedWord(word, false, sf::Vector2f(getRect().left + getRect().width,getRect().top), _font);
    words->push_back(newWord);*/
}

sf::FloatRect FormattedLine::getRect(){
    sf::FloatRect retVal = words->front()->getRect();

    for (FormattedWord* word : *words)
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

void FormattedLine::toggleGlitch() {
    for (FormattedWord* word : *words) {
        word->toggleGlitch();
    }
}

void FormattedLine::MoveVertical(float distance) {
    position.y += distance;
    for(FormattedWord* word : *words)
    {
        word->MoveVertical(distance);
    }
}

