--
-- Created by IntelliJ IDEA.
-- User: felix
-- Date: 17.01.20
-- Time: 12:10
-- To change this template use File | Settings | File Templates.
--


-- Old House Layouts
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


-- Forest Layouts
tree_layout = {
    size = {1,2},
    tiles = {49, 57},
}
bush_layout={
    size = {1,1},
    tiles = {58},
}
bushGroup_layout={
    size = {3,2},
    tiles = {-1,58,-1,58,-1,58},
}
chest_layout={
    size = {2,1},
    tiles = {50},
}
axe_layout={
    size = {1,1},
    tiles = {42},
}
skeleton_layout={
    size = {1,1},
    tiles = {43},
}
path_layout={
    size = {2,1},
    tiles = {51,51},
}


dungeon = {
    floor1 = {
        is_start = true,
        Southern_Forest={
            --layout = { {x = 2, y = 0}, {x=10, y= 0}, {x=10, y=6}, {x=2, y= 6}},

            is_start = true,

            Goblin = {
                position = {x = 2, y = 5},
                layout = goblin_layout,
                on_interaction = function()
                    start_new_fight("Goblin")
                end
            },

            Nothern_Way = {
                position = {x = 5,y = 0},
                layout = door_layout,
                next_room = "Western_Forest",
            },

            Tree = {
                position={x=3,y=1},
                layout = tree_layout,
                on_interaction = function ()
                    print_line("It's a tree.")
                    print_line("Not astounding, when you consider I'm in a forest right now... ")
                end
            },

            Bushes = {
                position = {x= 7,y=1},
                layout = bushGroup_layout,
                on_interaction= function ()
                    print_line("You can see several bushes. Some of them carry berries. ")
                    print_line("As you take a closer look you wouldn't consider them eatable. ")
                end
            },

            Axe = {
                position = {x = 7, y = 3},
                layout= axe_layout,
                on_interaction = function ()
                    print_line("Through the thick moss you see something shiny. As you approach it you realize it's an axe. ")
                    print_line("An old axe. I don't think it will be useful. ")
                    print_line("The blade is broken. There is a long crack in it. ")
                    print_line("As fast as you discover your new find, as fast you leave it again. It's not gonna help you anyway. ")
                end
            },
        },

        Western_Forest = {
            --layout = { {x = 2, y = 0}, {x=10, y= 0}, {x=10, y=6}, {x=2, y= 6}},

            Way_back_down = {
                position = {x = 5,y = 6},
                layout = door_layout,
                next_room = "Southern_Forest",
            },

            -- Door unlocks only when the bush in front of it is removed
            Nothern_Way = {
                position = {x = 9,y = 0},
                layout = door_layout,
                next_room = "Eastern_Forest",
            },

            -- Door unlocks only when the bush in front of it is removed
            Southern_Way = {
                position = {x = 9,y = 6},
                layout = door_layout,
                next_room = "Eastern_Forest",
            },

            Eastern_Way = {
                position = {x = 10,y = 3},
                layout = door_layout,
                next_room = "",
            },

            Upper_Bush = {
                position = {x = 9, y = 1},
                layout= bush_layout,
                on_interaction = function ()
                    print_line("I can see a path behind this bush. But I first have to remove the bush. ")
                    print_line("I could try to use some spells on it. ")
                end
            },

            Buttom_Bush = {
                position = {x = 9, y = 5},
                layout= bush_layout,
                on_interaction = function ()
                    print_line("I can see a path behind this bush. But I first have to remove the bush. ")
                    print_line("I could try to use some spells on it. ")
                end
            },

            Outworn_Path = {
                position = {x = 8, y = 3},
                layout= path_layout,
                on_interaction = function ()
                    print_line("The path looks old, like it hasn't been used in a long, long time. ")
                    print_line("It leads to the east. I could follow the way and see where it goes. ")
                end
            }, 
            
            Skeleton = {
                position = {x = 8, y = 3},
                layout= skeleton_layout,
                on_interaction = function ()
                    print_line("Uagh! It's a skeleton. I mean like a real skeleton! ")
                    print_line("I know the wizard said it will be dangerous and the forest is known to be deep, but that was a real living adventurer, who died. ")
                    print_line("Why am I here? ")
                end
            },

            -- Enemy Normal Goblin
        },

        Eastern_Forest = {
            --layout = { {x = 0, y = 0}, {x=7, y= 0}, {x=7, y=6}, {x=0, y= 6}},

            Southern_Way = {
                position = {x = 1,y = 6},
                layout = door_layout,
                next_room = "Western_Forest",
            },

            Nothern_Way = {
                position = {x = 1,y = 0},
                layout = door_layout,
                next_room = "Western_Forest",
            },

            -- Angucken des Raums allgemein
            -- Spieler sieht dabei einen blockierten Weg
        },

        Deep_Forest = {
            --layout = { {x = 0, y = 0}, {x=10, y= 0}, {x=10, y=4}, {x=0, y= 4}},

            Nothern_Way = {
            position = {x = 5,y = 0},
            layout = door_layout,
            next_room = "Clearing",
            },

            Western_Way = {
                position = {x = 0,y = 3},
                layout = door_layout,
                next_room = "Western_Forest",
            },


            Chest = {
                position = {x = 8, y = 3},
                layout= chest_layout,
                on_interaction = function ()
                    print_line("It's an old chest. Not really big. You could maybe fit a book inside? I think. ")
                    print_line("...I never saw a book so I don't know. They're too expensive. But it looks like I can open the chest.")
                    -- crackling noises and squeaking
                    print_line("As you open the chest you see you were right, or at least you think you were right. Inside is laying something you would consider a book.")
                    print_line("It has a deep blueish binding and faded letters on it. You cant't read it anymore but it seams the letters used to be golden. ")
                    print_line("You take out the book and your hands touch the binding. The book beginns to shimmer as the remainigs of the faited golden cover vanishes. ")
                    print_line("You imagine hearing the sound of waves and water mixed with some screeching of sea gull. ")
                    print_line("What was that? Was that a sea gull? But I'm in the middle of a forest. ")
                    print_line("Congratulation! you collected the word \"Water\".")
                    
                    add_modifier ("Water")
                end
            }, 

            -- Enemy Fire Goblin
        },

        Clearing = {
            layout = { {x = 3, y = 0}, {x=7, y= 0}, {x=7, y=6}, {x=3, y= 6}},

                Southern_Way = {
                position = {x = 5,y = 6},
                layout = door_layout,
                next_room = "Deep_Forest",
            },
        },

        --[[
        room1 = {

            sofa = {
                position = { x = 1, y = 2},
                layout = sofa_layout,
                on_interaction = function()
                    print_line("That's just an old sofa. It looks like it hasn't been used in a very long time. ")
                    print_line("But...what's that? Are those holes? ")
                    print_line("Ugh, yes. I will definitely not try to sit on it!")
                    print_line("I'm not sure if it will hold with all those holes... ")
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
        },
        room6 = {
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
        },
        ]]
    }
}



