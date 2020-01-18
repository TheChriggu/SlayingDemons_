--
-- Created by IntelliJ IDEA.
-- User: felix
-- Date: 17.01.20
-- Time: 12:10
-- To change this template use File | Settings | File Templates.
--
sofa_layout = {
    size = {1, 2},
    tiles = {32, 40}
}
table_layout = {
    size = {1, 2},
    tiles = {33, 41}
}
door_layout = {
    tiles = {9, 3}
}
book_layout = {
    tiles = {34}
}
bookshelf_layout = {
    size = {1, 2},
    tiles = {48, 56}
}


dungeon = {
    floor1 = {
        room1 = {
            is_start = true,

            sofa = {
                position = { x = 1, y = 2},
                layout = sofa_layout
            },
            table = {
                position = {x = 9, y = 4},
                layout = table_layout
            },
            east_door = {
                position = {x = 10, y = 3},
                layout = door_layout,
                next_room = "room3"
            },
            north_door = {
                position = {x = 5, y = 0},
                layout = door_layout,
                next_room = "room2"
            }
        },
        room2 = {
            south_door = {
                position = {x = 5, y = 6},
                layout = door_layout,
                next_room = "room1"
            },
            east_door = {
                position = {x = 10, y = 3},
                layout = door_layout,
                next_room = "room4"
            },
            bookshelf  = {
                position = {x = 6, y = 4},
                layout = bookshelf_layout
            },
        },
        room3 = {
            west_door = {
                position = {x = 0, y = 3},
                layout = door_layout,
                next_room = "room1"
            },
            book = {
                position = {x = 7, y = 3},
                layout = book_layout
            }
        },
        room4 = {
            west_door = {
                position = {x = 0, y = 3},
                layout = door_layout,
                next_room = "room2"
            },
            north_door = {
                position = {x = 5, y = 0},
                layout = door_layout,
                next_room = "room2"
            }
        },
        room5 = {
            north_door = {
                position = {x = 5, y = 0},
                layout = door_layout,
                next_room = "room2"
            },
            south_door = {
                position = {x = 5, y = 6},
                layout = door_layout,
                next_room = "room2"
            }
        }
    }
}

