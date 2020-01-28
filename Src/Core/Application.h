//
// Created by christian.heusser on 05.11.2019.
//

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

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
#include <Event/EventSystem.h>
#include "Vocabulary.h"
#include "Combat/Action.h"
#include "Combat/Modifier.h"
#include "UI/MapWindow.h"
#include "ScriptEngine/ScriptEngine.h"
#include "InputTextProcessor.h"
#include "UI/PossibleWords.h"

namespace sd {
    class Application : public Manageable {

        Sp<sf::RenderWindow> window_;
        std::vector<Sp<DrawableObject>> drawable_objects_;

        Sp<ShaderEngine> shader_engine_;
        Sp<EventSystem> event_system_;
        Sp<ScriptEngine> script_system_;

        void load_vocab();

    public:
        Application() = default;
        ~Application() override = default;

        bool setup() override;
        bool run();
        void shutdown() override;
        
        bool setup_window();
        bool setup_scene();
    };
}

#endif //_APPLICATION_H_
