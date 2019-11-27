//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "Manageable.h"
#include "Button.h"
#include "DrawableObject.h"
#include "InputField.h"
#include "TextOutput.h"
#include <vector>

namespace sd {
    class Application : public Manageable {

        sf::RenderWindow* window_;
        /*Button* button;
        DrawableObject* background;
        TextOutput* textOutput;
        DrawableObject* wordList;
        InputField* inputField;
        DrawableObject* map;
        DrawableObject* books;*/

        std::vector<DrawableObject*> drawable_objects_;

    public:
        Application();
        virtual ~Application() = default;

        bool Setup() override;
        bool Run();
        void Shutdown() override;

        void clear();



    };
}

#endif //UNTITLED_APPLICATION_H
