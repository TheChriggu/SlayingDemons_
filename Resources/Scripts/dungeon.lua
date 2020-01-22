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
goblin_layout = {
    tiles = {25}
}


dungeon = {
    floor1 = {
        room1 = {
            is_start = true,

            sofa = {
                position = { x = 1, y = 2},
                layout = sofa_layout,
                on_interaction = function()
                    print_line("That's just an old sofa. It looks like it hasn't been used in a very long time. ")
                    print_line("But...what's that? Are those holes? ")
                    print_line("Ugh, yes. I will definitely not try to sit on it!")
                    print_line("I'm not sure if it will hold with all those holes... ")
                    set_glitch_on("background_panel")
                end
            },
            table = {
                position = {x = 9, y = 4},
                layout = table_layout,
                on_interaction = function()
                    print_line("...*cough*...That was a bad idea.")
                    print_line("Note to myself: Don't pull dusty sheets of dusty funiture in dusty, old houses.")
                    print_line("It's a table with a drawer under the table top...but the drawer is empty. ")
                end
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
            goblin = {
                position = {x = 9, y = 3 },
                layout = goblin_layout,
                on_interaction = function()
                    start_new_fight("Goblin")
                end
            }
        },
        room3 = {
            west_door = {
                position = {x = 0, y = 3},
                layout = door_layout,
                next_room = "room1"
            },
            book = {
                position = {x = 7, y = 3},
                layout = book_layout,
                on_interaction = function()
                    print_line("The book is much lighter than you first thought.")
                    print_line("The paper nearly crumbles between you fingers as you try to open it.")
                    print_line("The book is pretty fragile. I should be really careful with-...")
                    print_line("As you carefuly open the book a bit more it swings open with a loud creaking noise.")
                    print_line("You stare at it in suprise as the page began to shimmer. Over both pages are written the word \"cyber\".")
                    print_line("Slowly you lift your hand to touch the word and as as your fingers touch the paper the word \"cyber\" faded. Still not sure what happend you look around the room. ")
                    print_line("You seem to realize that the numbers and signs on the bookshelves aren't just numbers and signs. They are more like informations about people, ")
                    print_line("names, different dates and other preferences. Nevertheless you still don't have any clue what is going on here, but you get the feeling that it all makes sense...somehow.")
                    print_line("Congratulation! you collected the word \"Cyber\".")

                    add_modifier("Cyber")
                end
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

