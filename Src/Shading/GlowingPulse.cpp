//
// Created by christian.heusser on 19.02.2020.
//

#include <ScriptEngine/ScriptEngine.h>
#include "GlowingPulse.h"

sd::GlowingPulse::GlowingPulse(Sp<sf::Shader> glitch_shader) : ShaderProcedure(glitch_shader) {
    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    screen_size_.x = table["size"]["x"];
    screen_size_.y = table["size"]["y"];

    sf::Texture* noise = new sf::Texture();
    noise->loadFromFile("../Resources/Sprites/noise.png");

    greyscale_shader_ = std::make_shared<sf::Shader>();
    greyscale_shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/greyscale_shader.frag");

    blur_shader_ = std::make_shared<sf::Shader>();
    blur_shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/blur_shader.frag");

    average_shader_ = std::make_shared<sf::Shader>();
    average_shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/color_average_shader.frag");
    average_shader_->setUniform("sourceSize", sf::Vector2f(screen_size_.x/4,screen_size_.y/4));


    shader_->loadFromFile("../Resources/Shaders/mainVertexShader.vert", "../Resources/Shaders/add_image_shader.frag");

    rendered_tex_ = std::make_shared<sf::RenderTexture>();
    rendered_tex_->create(screen_size_.x, screen_size_.y);

    rendered_tex_2_ = std::make_shared<sf::RenderTexture>();
    rendered_tex_2_->create(screen_size_.x, screen_size_.y);

    rendered_sprite_ = std::make_shared<sf::Sprite>();
    rendered_sprite_->setTexture(rendered_tex_->getTexture());

    rendered_sprite_2_ = std::make_shared<sf::Sprite>();
    rendered_sprite_2_->setTexture(rendered_tex_2_->getTexture());

    clock_ = std::make_shared<sf::Clock>(sf::Clock());
}

void sd::GlowingPulse::process(sf::RenderTarget *window, const sf::Drawable *drawable) const {


    greyscale_shader_->setUniform("time", clock_->getElapsedTime().asSeconds());

    rendered_tex_->clear();
    rendered_tex_->draw(*drawable, greyscale_shader_.get());
    rendered_tex_->display();



    rendered_tex_2_->clear();
    rendered_tex_2_->draw(*rendered_sprite_, average_shader_.get());
    rendered_tex_2_->display();

    blur_shader_->setUniform("offsetFactor", sf::Vector2f(1.0f/screen_size_.x , 0));
    rendered_tex_->clear();
    rendered_tex_->draw(*rendered_sprite_2_, blur_shader_.get());
    rendered_tex_->display();

    blur_shader_->setUniform("offsetFactor", sf::Vector2f(0, 1.0f/screen_size_.y));
    rendered_tex_2_->clear();
    rendered_tex_2_->draw(*rendered_sprite_, blur_shader_.get());
    rendered_tex_2_->display();

    blur_shader_->setUniform("offsetFactor", sf::Vector2f(1.0f/screen_size_.x , 0));
    rendered_tex_->clear();
    rendered_tex_->draw(*rendered_sprite_2_, blur_shader_.get());
    rendered_tex_->display();

    blur_shader_->setUniform("offsetFactor", sf::Vector2f(0, 1.0f/screen_size_.y));
    rendered_tex_2_->clear();
    rendered_tex_2_->draw(*rendered_sprite_, blur_shader_.get());
    rendered_tex_2_->display();

    blur_shader_->setUniform("offsetFactor", sf::Vector2f(1.0f/screen_size_.x , 0));
    rendered_tex_->clear();
    rendered_tex_->draw(*rendered_sprite_2_, blur_shader_.get());
    rendered_tex_->display();



    shader_->setUniform("blurTex", rendered_tex_->getTexture());
    window->draw(*drawable, shader_.get());
}
