//
// Created by christian.heusser on 05.03.2020.
//

#include "Cursor.h"
#include <Event/EventSystem.h>
#include "Event/SetStageEventArgs.h"

sd::Cursor::Cursor() {
    cursor_texture_ = std::make_shared<sf::Texture>();
    cursor_texture_->loadFromFile("../Resources/Sprites/Progressing/cursor_0.png");

    cursor_image_ = cursor_texture_->copyToImage();

    cursor_ = std::make_shared<sf::Cursor>();
    auto pixels = (cursor_image_.getPixelsPtr());
    cursor_->loadFromPixels(pixels, sf::Vector2u(64, 64), sf::Vector2u(1, 1));

    has_changed = false;
    event_handler_ = CREATE_EVENT_HANDLER
            (
                if (e->type == EventArgs::Type::SET_STAGE)
                {
                    auto arg = std::dynamic_pointer_cast<SetStageEventArgs>(e);
                    cursor_texture_->loadFromFile("../Resources/Sprites/Progressing/cursor_" + std::to_string(arg->stage) + ".png");

                    cursor_image_ = cursor_texture_->copyToImage();
                    auto pixels = (cursor_image_.getPixelsPtr());
                    cursor_->loadFromPixels(pixels, sf::Vector2u(64, 64), sf::Vector2u(1, 1));

                    std::cout << "cursor changed\n";
                    has_changed = true;
                }
             );

    REGISTER_EVENT_HANDLER();
}

Sp<sf::Cursor> sd::Cursor::get_cursor() {
    return cursor_;
}

bool sd::Cursor::check_on_mouse_cursor() {
    if(has_changed)
    {
        has_changed = false;
        return true;
    }
    return false;
}
