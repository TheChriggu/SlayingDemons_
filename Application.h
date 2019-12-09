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
#include "FileInput.h"
#include "World.h"
#include <vector>
#include "FightScripts/Vocabulary.h"
#include "FightScripts/Action.h"
#include "FightScripts/Modifier.h"

namespace sd {
    class Application : public Manageable {

        sf::RenderWindow* window_;
        FileInput* file_input_;

        World* world_;

        std::vector<DrawableObject*> drawable_objects_;
        void LoadVocab();

        TextOutput* output;


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
