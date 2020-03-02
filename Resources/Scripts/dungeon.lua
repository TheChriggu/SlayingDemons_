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
    size = {2,1},
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
    size = {1,1},
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
bushDoor_layout = {
    size = {2,1},
    tiles = {9, 58}
}


dungeon = {
    floor1 = {
        is_start = true,

        Southern_Forest={
            layout = { {2, 0}, {10, 0}, {10, 6}, {2, 6}},

            northern_way = {
                position = {x = 5,y = 0},
                layout = door_layout,
                is_locked = false,
                next_room = "western_forest",

                on_inspection = function()
                    print_line("It's a small path leading to the north.")
                end,

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end
            },

            tree = {
                position={x=3,y=1},
                layout = tree_layout,

                on_inspection = function ()
                    print_line("It's a tree.")
                    print_line("Not astounding, considering you're in a forest right now... ")
                end
            },

            bushes = {
                position = {x= 7,y=1},
                layout = bushGroup_layout,

                on_inspection = function ()
                    print_line("You can see several bushes. Some of them carry berries. ")
                    print_line("As you take a closer look you wouldn't consider them edible. ")
                end
            },

            axe = {
                position = {x = 7, y = 3},
                layout= axe_layout,

                on_inspection = function ()
                    --print_line("Through the thick moss you see something shiny. As you approach it you realize it's an axe. ")
                    print_line("An old axe. Probably not very useful. ")
                    print_line("The blade is broken. There is a long crack in it. ")
                    print_line("As fast as you discover your new find, you leave it again. It's not gonna help you anyway. ")
                end
            },
        },

        western_forest = {
            layout = { {2,0}, {10,0}, {10,6}, {2,6}},

            Way_back_down = {
                position = {x = 5,y = 6},
                layout = door_layout,
                next_room = "Southern_Forest",
            },

            northern_way = {
                position = {x = 9,y = 0},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest",
                is_locked=true,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your Pyro Poke on the bush.")
                    print_line("[b] > Pyro Poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "northern_way")
                end,

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end
            },

            southern_way = {
                position = {x = 9,y = 6},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest",
                is_locked=true,

                on_interaction = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your Pyro Poke on the bush.")
                    print_line("[b] > Pyro Poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "southern_way")
                end,

                on_enter = function()
                    print_line("You walk to the south and enter a new room.")
                end
            },

            eastern_way = {
                is_locked= true,
                position = {x = 10,y = 3},
                rotation = 0,
                layout = door_layout,
                next_room = "deep_forest",

                on_enter = function()
                    print_line("You walk to the east and enter a new room.")
                end
            },

            Goblin = {
                position = {x = 5, y = 3},
                layout = goblin_layout,
                --on_interaction = function()
                    --print_line("You walk to the Goblin, wanting to wish him a merry day.")
                    --print_line("He does not understand your intentions. A fight ensues.")
                    --start_new_fight("Goblin")
                --end,

                on_open = function()
                    print_line("You try to open the Goblin. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the Goblin attacks you.")
                    start_new_fight("Goblin")
                end,

                on_inspection = function()
                    print_line("It's a small, hairy, wild, angry Goblin. Nothing too dangerous. Probably...")
                end,

                on_fight = function()
                    print_line("You take charge and attack the Goblin.")
                    start_new_fight("Goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the Goblin, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    start_new_fight("Goblin")
                end,

                on_destroy = function ()
                    unlock_door("western_forest", "eastern_way")
                end,
            },

            outworn_path = {
                position = {x = 8, y = 3},
                layout= path_layout,
                on_inspection = function ()
                    print_line("The path looks old, like it hasn't been used in a long, long time. ")
                    print_line("It leads to the east. You could follow the way and see where it goes. ")
                end
            },
            
            skeleton = {
                position = {x = 6, y = 1},
                layout= skeleton_layout,
                on_inspection = function ()
                    print_line("Uagh! It's a skeleton. Like... a real skeleton! ")
                    print_line("You know the wizard said it will be dangerous and the forest is known to be deep, but that was a real living adventurer, who died. ")
                    print_line("Why are you here? ")
                end
            },

        },

        Eastern_Forest = {
            layout = { {0, 0}, {7, 0}, {7, 6}, {0, 6}},

            southern_way = {
                position = {x = 1,y = 6},
                layout = door_layout,
                next_room = "western_forest",

                on_enter = function()
                    print_line("You walk to the south and enter a new room.")
                end
            },

            northern_way = {
                position = {x = 1,y = 0},
                layout = door_layout,
                next_room = "western_forest",

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end
            },

            -- Angucken des Raums allgemein
            -- Spieler sieht dabei einen blockierten Weg
        },

        deep_forest = {
            layout = { {0, 0}, {10, 0}, {10, 4}, {0, 4}},

            northern_way = {
            position = {x = 5,y = 0},
            layout = door_layout,
            next_room = "clearing",
            },

            western_way = {
                position = {x = 0,y = 3},
                layout = door_layout,
                next_room = "western_forest",

                on_enter = function()
                    print_line("You walk to the west and enter a new room.")
                end
            },

            chest = {
                position = {x = 2, y = 1},
                layout= chest_layout,
                on_inspection = function ()
                    print_line("It's an old chest. Not really big. You could maybe fit a book inside?")
                    print_line("...You've never seen a book so you wouldn't know. They're too expensive. But it looks like you can open the chest.")
                    -- crackling noises and squeaking
                    print_line("As you open the chest you see you were right, or at least you think you were right. Inside is laying something you would consider a book.")
                    print_line("It has a deep blueish binding and faded letters on it. You cant't read it anymore but it seams the letters used to be golden. ")
                    print_line("You take out the book and your hands touch the binding. The book begins to shimmer as the remainigs of the faited golden cover vanishes. ")
                    print_line("You hear the sound of waves and water mixed with some screeching of sea gull. ")
                    print_line("What was that? Was that a sea gull? But You're in the middle of a forest. ")
                    print_line("Congratulation! You've collected the word \"Water\".")
                    add_modifier ("Water")
                end,

                on_open = function ()
                    print_line("It's an old chest. Not really big. You could maybe fit a book inside?")
                    print_line("...You've never seen a book so you wouldn't know. They're too expensive. But it looks like you can open the chest.")
                    -- crackling noises and squeaking
                    print_line("As you open the chest you see you were right, or at least you think you were right. Inside is laying something you would consider a book.")
                    print_line("It has a deep blueish binding and faded letters on it. You cant't read it anymore but it seams the letters used to be golden. ")
                    print_line("You take out the book and your hands touch the binding. The book begins to shimmer as the remainigs of the faited golden cover vanishes. ")
                    print_line("You hear the sound of waves and water mixed with some screeching of sea gull. ")
                    print_line("What was that? Was that a sea gull? But You're in the middle of a forest. ")
                    print_line("Congratulation! You've collected the word \"Water\".")
                    add_modifier ("Water")
                end
            },

            Goblin = {
                position = {x = 7, y = 2},
                layout = goblin_layout,
                on_inspection = function()
                    print_line("You walk to the Goblin, wanting to wish him a merry day.")
                    print_line("Maybe you should mention he is burning.")
                    print_line("He does not understand your intentions. A fight ensues.")
                    start_new_fight("Fire Goblin")
                end,

                on_open = function()
                    print_line("You try to open the Goblin. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the Goblin attacks you.")
                    start_new_fight("Fire Goblin")
                end,

                on_fight = function()
                    print_line("You take charge and attack the Goblin.")
                    start_new_fight("Fire Goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the Goblin, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    start_new_fight("Fire Goblin")
                end
            },
        },

        clearing = {
            layout = { {3, 0}, {7, 0}, {7, 6}, {3,6}},

            southern_way = {
                position = {x = 5,y = 6},
                layout = door_layout,
                next_room = "deep_forest",

                on_enter = function()
                    print_line("You walk to the south and enter a new room.")
                end
            },

            chest = {
                position = {x = 5, y = 1},
                layout= chest_layout,
                on_open = function ()
                    print_line("It's an old chest. Again. You are kind of afraid what is going to happen this time when you open it. ")
                    print_line("Slowly you approach the chest and open it.")
                    -- crackling noises and squeaking
                    print_line("At the bottom of the chest lays a piece of paper. It looks similar to a map.")
                    print_line("You take a closer look at it and it's a map of the forest. The marked location is a bit to the east from your place.")
                    print_line("But it's in walking distance. You could reach it in maybe 30 minutes.")
                    set_glitch_on("output-panel")
                end
            },
        },
    },

    dungeon_2={
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
    },

    dungeon_3= {
        is_start = true,
        main_room = {
            is_start = true,
            
            red_door = {
                position = {x=2, y=0},
                layout = door_layout,
                next_room = "red_room"
            },
            green_door = {
                position = {x=5, y=0},
                layout = door_layout,
                next_room = "green_room"
            },
            blue_door = {
                position = {x=8, y=0},
                layout = door_layout,
                next_room = "blue_room"
            },
            -- Door opens after red light, green light and blue light were used on the door
            -- Writing after Light has been collected:
            -- I'm the last one to open, but first I have to shine the brightest.
            white_door = {
                position = {x=10, y=3},
                layout = door_layout,
                next_room = "secret_room",
                is_locked = false,

                on_enter = function ()
                    set_glitch_on("output-panel")
                end
                
            },
        
            chest = {
                position = {x = 5, y = 3},
                layout= chest_layout,
                on_open = function ()
                    print_line("It's the old chest you saw when you entered the room.")
                    print_line("But something about this chest seems different...")
                    print_line("It appears to glow from the inside out.")
                    print_line("You're not quite sure if you should open it or not.")
                    print_line("But after all you decide to open it, because until now nothing bad has ever happend when you opened unkown chest.")
                    -- crackling noises and squeaking
                    print_line("As you slowly open the lid a beam of light escapes through the crack.")
                    print_line("It hits the door to the east.")
                    print_line("Your gaze follows the beam and you see writing appearing, where the light hit the door.")
                    print_line("With a loud crack the lid swings open and floods the room with bright white light")
                    print_line("For a few seconds you see nothing but white, but than the light is gone and you see the room again.")
                    print_line("Congratulation! You've collected the word \"Light\".")
                    add_action ("Light")
                    set_glitch_on("output-panel")
                end,
            },

            on_inspection = function ()
                print_line("The room is nearly empty, except four doors.")
                print_line("Three are on the north side. A red, green and blue one.")
                print_line("The fourth one is white and one the east side.")
                print_line("But wait! There is one more thing.")
                print_line("It's another old chest, which is standing right in the middle of the room.")

            end
        },

        red_room = {
            way_back = {
                position = {x=5, y=6},
                layout = door_layout,
                next_room = "main_room"
            },

            chest = {
                position = {x = 5, y = 1},
                layout= chest_layout,
                on_open = function ()
                    print_line("It's an old chest. Again. ")
                    print_line("But at this time you are getting kind of used to it, what happens when you open one of this old chests.")
                    print_line("Slowly you approach the chest and open it.")
                    -- crackling noises and squeaking
                    print_line("The whole inside is red. ")
                    print_line("You take a closer look at it and as soon as you opened the chest completely a blinding red light fills the room.")
                    print_line("For a few seconds you can't see anything, but than the light is gone and you see the room again.")
                    -- rgb glitch
                    print_line("Congratulation! You've collected the word \"Red\".")
                    add_modifier ("Red")
                    set_glitch_on("output-panel")
                end,
            },
        },

        blue_room = {
            way_back = {
                position = {x=5, y=6},
                layout = door_layout,
                next_room = "main_room"
            },

            chest = {
                position = {x = 5, y = 1},
                layout= chest_layout,
                on_open = function ()
                    print_line("Another old chest.")
                    print_line("But at this time you are getting kind of used to it, what happens when you open one of this old chests.")
                    print_line("Slowly you approach the chest and open it.")
                    -- crackling noises and squeaking
                    print_line("The whole inside is blue. ")
                    print_line("You take a closer look at it and as soon as you opened the chest completely a blinding blue light fills the room.")
                    print_line("For a few seconds you can't see anything, but than the light is gone and you see the room again.")
                    -- rgb glitch
                    print_line("Congratulation! You've collected the word \"Blue\".")
                    add_modifier ("Blue")
                    set_glitch_on("output-panel")
                end,
            },
        },

        green_room = {
            way_back = {
                position = {x=5, y=6},
                layout = door_layout,
                next_room = "main_room"
            },
            
            chest = {
                position = {x = 5, y = 1},
                layout= chest_layout,
                on_open = function ()
                    print_line("You know what it is. An old chest.")
                    print_line("What a surprise.")
                    print_line("Slowly you approach the chest and open it.")
                    -- crackling noises and squeaking
                    print_line("The whole inside is green. ")
                    print_line("You take a closer look at it and as soon as you opened the chest completely a blinding green light fills the room.")
                    print_line("For a few seconds you can't see anything, but than the light is gone and you see the room again.")
                    -- rgb glitch
                    print_line("Congratulation! You've collected the word \"Green\".")
                    add_modifier ("Green")
                    set_glitch_on("output-panel")
                end,
            },

            Mimicry = {
                position = {x = 5, y = 4},
                layout = goblin_layout,

                on_open = function()
                    print_line("You try to open the Mimicry. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the Mimicry attacks you.")
                    start_new_fight("Goblin")
                end,

                on_inspection = function()
                    print_line("It's a small branch of a tree...with feets...and pointy fangs peaking out of its mouth. Shouldn't too dangerous. Probably...")
                end,

                on_fight = function()
                    print_line("You take charge and attack the Mimicry.")
                    start_new_fight("Goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the Mimicry, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    start_new_fight("Goblin")
                end,
            }
        },

        secret_room = {
            way_back = {
                position = {x=0, y=3},
                layout = door_layout,
                next_room = "main_room"
            },
    
            bookshelves = {
                position = {x=2, y=1},
                layout= bookshelf_layout,
    
                on_inspection =  function ()
                    print_line("You take a closer look at the bookshelves and see that there a many, many papers and folders with lots of names.")
                    set_glitch_on("output-panel")
                    print_line("")
                end
            },
            writing_table = {
            },
    
            table = {
            },
        },  

    },
}



