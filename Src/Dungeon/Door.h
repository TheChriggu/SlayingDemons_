//
// Created by christian.heusser on 12.12.2019.
//

#ifndef _DOOR_H_
#define _DOOR_H_

#include "SingleTileObject.h"
#include "Room.h"

namespace sd {
    class Door : public SingleTileObject, public std::enable_shared_from_this<Door> {
    private:
        bool is_locked_;
        std::string next_room_;
        int sprite_sheet_idx_open_;
        int sprite_sheet_idx_locked_;
        std::string door_id_;
        int rotation_;

    public:
        Door(std::string name, int sprite_sheet_idx_open, int sprite_sheet_idx_locked,
                sf::Vector2i position_on_tile_map, int rotation, std::string next_room, bool is_locked, Sp<FunctionCollection> function_collection);
        ~Door() override = default;

        void put_on_layout(std::vector<TileData>& layout, int width, int height) override;
        void remove_from_layout(std::vector<TileData>& layout, int width, int height) override;
        std::string get_name() override;
        void be_entered() override;

        void set_locked(bool lock_state);

        [[nodiscard]] const std::string& get_connected_room() const;
    };
}

#endif //_DOOR_H_
