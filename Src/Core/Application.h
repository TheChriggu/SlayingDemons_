//
// Created by christian.heusser on 05.11.2019.
//

#ifndef UNTITLED_APPLICATION_H
#define UNTITLED_APPLICATION_H
#include "SFML/Graphics.hpp"
#include "Manageable.h"
#include "UI/Button.h"
#include "DrawableObject.h"
#include "UI/InputField.h"
#include "UI/TextOutput.h"
#include "IO/FileInput.h"
#include "World.h"
#include <vector>
#include <Shading/ShaderEngine.h>
#include "Vocabulary.h"
#include "Combat/Action.h"
#include "Combat/Modifier.h"
#include "UI/MapWindow.h"
#include "ScriptEngine/ScriptEngine.h"
#include "InputTextProcessor.h"
#include "UI/PossibleWords.h"

namespace sd {
    class Application : public Manageable {

        sf::RenderWindow* window_;
        FileInput* file_input_;

        World* world_;
        TextOutput* output;

        std::vector<DrawableObject*> drawable_objects_;
        InputTextProcessor* inputTextProcessor;

        sp<ShaderEngine> shader_engine_;

        void LoadVocab();

    public:
        Application();
        virtual ~Application() = default;

        bool Setup() override;
        bool Run();
        void Shutdown() override;

        void clear();

        //int Test1();
        //void Test2(std::string message);
    };
}

#endif //UNTITLED_APPLICATION_H
