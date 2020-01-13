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

        sp<sf::RenderWindow> window_;
        sp<FileInput> file_input_;

        sp<World> world_;
        sp<TextOutput> output;

        std::vector<sp<DrawableObject>> drawable_objects_;

        sp<ShaderEngine> shader_engine_;

        void LoadVocab();

    public:
        Application();
        ~Application() override = default;

        bool Setup() override;
        bool Run();
        void Shutdown() override;

        void clear();
    };
}

#endif //UNTITLED_APPLICATION_H
