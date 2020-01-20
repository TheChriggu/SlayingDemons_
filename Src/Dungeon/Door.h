//
// Created by christian.heusser on 12.12.2019.
//

#ifndef _DOOR_H_
#define _DOOR_H_

#include "SingleTileObject.h"
#include "Room.h"

namespace sd {
    class Door : public SingleTileObject {
    private:
        bool is_locked_;
        std::string next_room_;
        int sprite_sheet_idx_open_;
        int sprite_sheet_idx_locked_;

    public:
        Door(std::string name, int sprite_sheet_idx_open, int sprite_sheet_idx_locked, sf::Vector2i position_on_tile_map,
            std::string next_room, sol::function on_interaction);
        ~Door() override = default;

        void put_on_layout(int* layout, int width, int height) override;
        std::string get_name() override;
        void be_interacted_with() override;

        void set_locked(bool lock_state);

        [[nodiscard]] const std::string& get_connected_room() const;
    };
}

#endif //_DOOR_H_
