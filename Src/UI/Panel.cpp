//
// Created by felix on 26.11.19.
//

#include <ScriptEngine/ScriptEngine.h>
#include "Panel.h"
#include "Event/SetStageEventArgs.h"
#include "Event/EventSystem.h"

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, sf::Color color)
    : DrawableObject("panel")
{
    sf::Texture texture;
    if (!texture.create(size.x,size.y))
    {

    }

    texture_->setRepeated(true);

    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture);
    sprite_->setColor(color);
    sprite_->setPosition(position);

    panel_tex_ = std::make_shared<sf::RenderTexture>();
    panel_sprite_ = std::make_shared<sf::Sprite>();

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    panel_tex_->create(table["size"]["x"], table["size"]["y"]);
    panel_sprite_->setTexture(panel_tex_->getTexture());
}

// TODO(FK): clean up name
sd::Panel::Panel(sf::Vector2f position, sf::Vector2f size, const char* texture_path)
    : DrawableObject("Panel")
{
    texture_ = std::make_shared<sf::Texture>();


    std::string path(texture_path);
    if(path.find("Progressing") != std::string::npos)
    {
        path_ = path;
        event_handler_ = CREATE_EVENT_HANDLER(
         if (e->type == EventArgs::Type::SET_STAGE)
         {
             if (e->type == EventArgs::Type::SET_STAGE) {
                 auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);

                 texture_->loadFromFile(path_ + std::to_string(arg->stage) + ".png");
             }
         }
         );

        REGISTER_EVENT_HANDLER();

        path += "0.png";
        texture_->loadFromFile(path);
    }
    else{
        texture_->loadFromFile(texture_path);
    }

    //texture_->setRepeated(true);
    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(*texture_);
    sprite_->setPosition(position);

    panel_tex_ = std::make_shared<sf::RenderTexture>();
    panel_sprite_ = std::make_shared<sf::Sprite>();

    auto table = ScriptEngine::get().get_script("config")->get_table("window")->as<sol::table>();
    panel_tex_->create(table["size"]["x"], table["size"]["y"]);
    panel_sprite_->setTexture(panel_tex_->getTexture());
}


void sd::Panel::handle(sf::Event event) {

}

sf::Vector2f sd::Panel::get_position() {
    return sprite_->getPosition();
}

sf::Vector2f sd::Panel::get_size() {
    sf::Vector2f size;
    size.x = sprite_->getTexture()->getSize().x;
    size.y = sprite_->getTexture()->getSize().y;
    sf::Vector2f scale = sprite_->getScale();
    size.x *= scale.x;
    size.y *= scale.y;
    return size;
}

void sd::Panel::draw_to(Sp<sf::RenderTarget> window) const{
    panel_tex_->clear(sf::Color::Transparent);
    panel_tex_->draw(*sprite_);
    panel_tex_->display();


    if (shader_procedure_) {

        shader_procedure_->process (window.get (), panel_sprite_.get ());
    } else {

        window->draw(*panel_sprite_);
    }

}

bool sd::Panel::setup() {
    return DrawableObject::setup ();
}


