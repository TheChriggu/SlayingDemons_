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
#include <UI/Colors.h>
#include "Vocabulary.h"
#include "Combat/Action.h"
#include "Combat/Modifier.h"
#include "UI/MapWindow.h"
#include "ScriptEngine/ScriptEngine.h"
#include "InputTextProcessor.h"
#include "UI/PossibleWords.h"
#include "UI/Screen.h"
#include "StartUp/SplashScreens.h"
#include "../Audio/AudioPlayer.h"
#include "../UI/Cursor.h"

namespace sd {
    class Application : public Manageable {

        Sp<SplashScreens> splash_screens_;


        Sp<sf::RenderWindow> window_;
        std::vector<Sp<DrawableObject>> drawable_objects_;
        
        Sp<World> world_;
        Sp<Font> fonts_;
        Sp<Colors> colors_;
        
        Sp<ShaderEngine> shader_engine_;

        Sp<AudioPlayer> audio_player_;

        void load_vocab();

        //Sp<sf::RenderTexture> screen_texture_;
        Sp<Screen> screen_;
        
        void test();

        Sp<Cursor> cursor_;

    public:
        Application() = default;
        ~Application() override = default;

        bool setup_splash_screens();
        bool setup_main_menu();
        bool setup() override;
        bool run_splash_screens();
        bool run_main_menu();
        bool run();
        void shutdown() override;
        
        bool setup_window();
        bool setup_scene();
    };
}

#endif //_APPLICATION_H_
