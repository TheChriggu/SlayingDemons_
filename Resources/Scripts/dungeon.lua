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
    tiles = {51, 59}
}
table_layout = {
    size = {1, 2},
    tiles = {33, 41}
}
door_layout = {
    size = {2,1},
    tiles = {8, 3}
}
horizontal_door_layout = {
    size = {2,1},
    tiles = {8, 4}
}
fakedoor_layout = {
    size = {1,1},
    tiles = {3}
}
book_layout = {
    tiles = {34}
}
bookshelf_layout = {
    size = {1, 2},
    tiles = {48, 56}
}
big_bookshelf_layout = {
    size = {8, 3},
    tiles = {16, 17, 17, 17, 17, 17, 17, 18, 24, -1, -1, -1, -1, -1, -1, 24, 32, -1, -1, -1, -1, -1, -1, 32}
}
enemy_layout = {
    size = {1,1},
    tiles = {61},
}
wizard_layout = {
    size = {1,1},
    tiles = {62},
}
blocked_window_layout = {
    size = {5, 4},
    tiles = {-1, -1, -1, -1, 11, 10, -1, -1, -1, -1, -1, -1, -1, -1, 11, 9, -1, 9, -1, -1},
}
server_layout = {
    size = {2, 2},
    tiles = {38, 39, 46, 47}
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
barrel_layout={
    size = {1,1},
    tiles = {50},
}
bushGroup_layout={
    size = {3,2},
    tiles = {-1,58,-1,58,-1,58},
}
chest_layout={
    size = {1,1},
    tiles = {40},
}
axe_layout={
    size = {1,1},
    tiles = {42},
}
skeleton_layout={
    size = {1,1},
    tiles = {25},
}
path_layout={
    size = {2,1},
    tiles = {7,7}
}
bushDoor_layout = {
    size = {2,1},
    tiles = {8, 58}
}


dungeon = {
    tutorial_floor ={
        is_start = true,

        tutorial_room={
            is_start = true,

            layout = { {2, 0}, {10, 0}, {10, 6}, {2, 6}},

        --print_line("As you lay peacefully on your front porch, soaking up the last warm sun rays of late summer, you hear one of goats on the range land. Everything seems so peaceful nothing bad could ever happen."),
        --print_line("'Hey Kid! Wake up.' A rough voice wakes you up."),
        --print_line("You are getting rudely awake as the end of a large wooden staff hits your stomach. Stachled by the unfriendly behavior of your guest you jump up, willed to aks him what his problem is. But than you realized it's the old wizard of the village standing in front of you. "),
        --print_line("'I need you to do me a favor, kid.' he countinues."),
        --print_line("The wizard need you to do him a favor? That's highly unlikely. Why should he need you? You're just an oridnary farmer boy, living outside the village with no special talent. "),
        --print_line("Obviously you don't trust the old wizard, but luckly you can take a closer look at things."),
        --print_line("[i]Try typing: Inspect Wizard[/i]"),

            wizard ={
                position={x=7,y=3},
                layout = wizard_layout,

                on_inspection = function ()
                    print_line("[i]It's the old wizard. He lives down the street in the village. You barely saw him before, but today he seems to be a bit more nervous.[/i]")
                    print_line("[i]In his right hand he holds a large wooden staff. It's probably the staff he poked you with.[/i]")
                    print_line("Congratulations!")
                    print_line("You have inspected the wizard. You can do this with every listed object in the room.")
                    --wait(4)
                    print_line("You look at the wizard sceptically.")
                    --wait(1)
                    print_line("The old wizard returns the look. 'What? I bet it's not the first time someone asked you for a favor.'")
                    print_line("[font=book]'Anyway, I need you to fight the fire-breathing drago, the ancient enemy of this kingdom.'")
                    print_line("[font=book]'You know, the dragonn who destroys the fields and homes of the village residents.'")
                    print_line("The wizard lowers his sight. 'Soon we won't have any food left...'")
                    print_line("'Don't look like that!', you say.")
                    --wait(4)
                    print_line("[font=book]'Let's be honest. Apparently you have the most common sense from everyone in the village and a radius of several miles around it'")
                    print_line("[font=book]'So I decided you would be the best option to fight this dragon. We have no other choice.' [font=current] He looks at you, eyes full of confidence.")
                    print_line("Oh, what a great decision. You don't even know how to fight.")
                    print_line("[font=book]'But do not worry. I will show you how to fight.'")
                    print_line("Great...")
                    --wait(1)
                    print_line("[font=book]'First you need to learn some spells', [font=current]he explains.")
                    print_line("You learnt starter spells.")
                    print_line("The old wizard points to a barrel. [font=book]'Now, you see the barrel over there? Attack it by typing [b]'fight barrel'.")
                    add_command("fight")
                end,

                on_enter = function()
                    set_stage(1)
                end,

                on_fight = function()
                    set_stage(2)
                end,

                on_open = function()
                    set_stage(3)
                end

        },
            barrel = {
                position={x=5,y=3},
                layout = barrel_layout,

                on_enter = function ()
                    print_line("You can't enter a barrel. That's not how it works.")
                    print_line("Nevertheless, the old wizard said you should try fight the barrel.")
                end,

                on_fight = function ()
                    print_line("Let's see how that works.")
                    start_new_fight_with_differently_named_enemy("goblin", "barrel")
                end,

                on_open = function ()
                    print_line("This appears to belong to the old man. And that guy's looking at you quite funny.")
                end,

                on_inspection = function ()
                    print_line("This appears to belong to the old man. And that guy's looking at you quite funny.")
                end,

                on_destroy = function ()
                    print_line("[font=book]'Good, Kid. That are the basics of fighting', [font=current]said the old wizard.")
                    print_line("[font=book]'Now that you know how to fight you can start your adventure.'")
                    print_line("The wizard points to a forest near the horizon.")
                    wait(2)
                    print_line("[font=book]'The fire-breathing dragon waits at the ancient castle at the other side of the adventurer forest.'")
                    print_line("[font=book]'Just go there and you'll find your way.' [font=current]The wizard looks strangely optimistic.")
                    print_line("[font=book]But be cautious! Many brave people tried your quest before but never returned!")
                    wait(1)
                    print_line("Wait, the adventurer forest? That's not the nicest place for a farmer boy to be. Many adventuerers have gone missing there.")
                    print_line("You want to start protesting, but before you can say anything the wizard stamps his staff on the ground and vanishes.")
                    print_line("Apparently you have no other choice but attempting to fight the fire-breathing dragon...")
                    set_floor("floor1")
                    --loads dungeon floor1
                end
            },
        },
    },

    floor1 = {
        southern_forest={
            layout = { {2, 0}, {10, 0}, {10, 6}, {2, 6}},

            is_start = true,

            northern_way = {
                position = {x = 5,y = 0},
                layout = door_layout,
                is_locked = false,
                next_room = "western_forest",

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end,

                on_inspection = function()
                    print_line("It's a small path leading to the north.")
                end,

                on_open = function ()
                    print_line("There's nothing holding it shut to be opened here.")
                end,
            },

            tree = {
                position={x=3,y=1},
                layout = tree_layout,

                on_inspection = function ()
                    print_line("It's a tree.")
                    print_line("Not very astounding, considering you're in a forest right now... ")
                end
            },

            bushes = {
                position = {x= 7,y=1},
                layout = bushGroup_layout,

                on_inspection = function ()
                    print_line("It's a tree.")
                    print_line("Not very astounding, considering you're in a forest right now... ")
                end
            },

            axe = {
                position = {x = 7, y = 3},
                layout= axe_layout,

                on_inspection = function ()
                    --wait(1)
                    --print_line("Through the thick moss you see something shiny. As you approach it you realize it's an axe. ")
                    print_line("Through the thick moss you see something shiny. ")
                    print_line("An old axe. Probably not very useful.",2.5)
                    --wait()
                    print_line("The blade is broken. There is a long crack in it. ", 2.5)
                    --wait(4)
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

                on_open = function ()
                    print_line("There's nothing holding it shut to be opened here.")
                end,

                on_enter = function()
                    print_line("You walk to back down to the room you came from initially.")
                end,
            },

            northern_way = {
                position = {x = 9,y = 0},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest",
                is_locked=true,

                on_inspection = function ()
                    set_stage(2)
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your Pyro Poke on the bush.")
                    wait(2)
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "northern_way")
                    unlock_door("eastern_forest", "southern_way")
                end,

                on_enter = function()
                    print_line("This leads somewhere deep...")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },

            southern_way = {
                position = {x = 9,y = 6},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest",
                is_locked=true,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your pyro poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "southern_way")
                    unlock_door("eastern_forest", "northern_way")
                end,

                on_enter = function()
                    print_line("This leads somewhere deep...")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },

            eastern_way = {
                is_locked= true,
                position = {x = 10,y = 3},
                rotation = 0,
                layout = door_layout,
                next_room = "deep_forest",

                on_inspection = function ()
                    print_line("The first door. It has a goblin guarding it.")
                end,

                on_open = function ()
                    print_line("There's a door here. You could open it. It just doesn't feel right to do this without purpose.")
                end,

                on_enter = function()
                    print_line("You walk through the now unlocked door to the east and enter a new room.")
                end
            },

            goblin = {
                position = {x = 5, y = 3},
                layout = enemy_layout,
                on_inspection = function()
                    print_line("You walk to the goblin, wanting to wish him a merry day.")
                    print_line("He does not understand your intentions. A fight ensues.")
                    start_new_fight("goblin")
                end,

                on_open = function()
                    print_line("You try to open the Goblin. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the goblin attacks you.")
                    start_new_fight("goblin")
                end,

                on_fight = function()
                    print_line("You take charge and attack the goblin.")
                    start_new_fight("goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the goblin, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    start_new_fight("goblin")
                end,

                on_destroy = function ()
                    print_line("You defeated the goblin")
                    print_line("On his body he is carrying a key, which unlocks the door eastwards.")
                    unlock_door("western_forest", "eastern_way")
                    wait(2)
                    print_line("After taking a quick rest to gather energy, you continue on your jurney")
                end,
            },

            outworn_path = {
                position = {x = 8, y = 3},
                layout= path_layout,
                on_inspection = function ()
                    print_line("The path looks old, like it hasn't been used in a long, long time. ")
                    print_line("It leads to the east. You could follow the way and see where it goes. ")
                end,

                on_enter = function ()
                    print_line("You can't enter a path. That's what doors, gates, ways or rooms are for. ")
                end

            },
            
            skeleton = {
                position = {x = 6, y = 1},
                layout= skeleton_layout,
                on_inspection = function ()
                    print_line("Uagh! It's a skeleton. Like... a real skeleton! ")
                    print_line("You know the wizard said it will be dangerous and the forest is known to be deep, but that was a real living adventurer, who died. ")
                    print_line("Why did you ever come here? ")
                end,

                on_open = function ()
                    print_line("You carefully open up this dead persons rib cage. ")
                    print_line("Gross", 2)
                    print_line("...and disrespectful.")
                    print_line("Better to close it again.")
                end,

                on_enter = function ()
                    print_line("Admittedly, you've always wanted to know what it feels like in another persons skin. ")
                    print_line("But this guy has got none.")
                end,

                on_fight = function ()
                    print_line("This guy is already dead. What do you want to do? Kill him twice?", 2)
                    print_line("...that was rhethorical")
                end

            },

        },
        eastern_forest = {
            layout = { {0, 0}, {7, 0}, {7, 6}, {0, 6}},

            -- Spieler betritt den Raum
            -- Spieler sieht dabei einen blockierten Weg

            southern_way = {
                position = {x = 1,y = 6},
                layout = bushDoor_layout,
                is_locked=true,
                next_room = "western_forest",

                on_enter = function()
                    print_line("As you walk that way, you realize: you're back in the room with the goblin.")
                    print_line("You're lucky you didn't get any more lost than that.")
                end,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your pyro poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "northern_way")
                    unlock_door("eastern_forest", "southern_way")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },

            northern_way = {
                position = {x = 1,y = 0},
                layout = bushDoor_layout,
                is_locked=true,
                next_room = "western_forest",

                on_enter = function()
                    print_line("As you walk that way, you realize: you're back in the room with the goblin.")
                    print_line("You're lucky you didn't get any more lost than that.")
                end,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your pyro poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest", "southern_way")
                    unlock_door("eastern_forest", "northern_way")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },
        },
        deep_forest = {
            layout = { {0, 0}, {10, 0}, {10, 4}, {0, 4}},

            northern_way = {
            position = {x = 5,y = 0},
            layout = door_layout,
            next_room = "clearing",

            on_enter = function()
                print_line("You enter this way to the north. The forest seems to get lighter")
            end,

            on_inspection = function ()
                print_line("You can see some light shine through from there")
            end,

            on_fight= function ()
                print_line("This way is emmitting such a serene and peacful atmosphere.")
                print_line("This much goodness in the forest is suspicious.")
                print_line("You charge at the northern_way, fully intent on destroying it to it'#'s very base.")
                print_line("You wildly swing your sword around in the air.")
                print_line("You look like a moron.")
            end,

            on_open = function ()
                print_line("There's no door, no hinges, nothing that could really be opened here.")
            end,

            },

            western_way = {
                position = {x = 0,y = 3},
                layout = door_layout,
                next_room = "western_forest",

                on_enter = function()
                    print_line("You want to take another look at that skeleton.")
                    print_line("It's so exciting.")
                    print_line("...and disgusting. But mostly exciting.")
                end,

                on_inspection = function ()
                    print_line("You can see the backside of the door you unlocked with the key from the goblin.")
                    print_line("It honestly looked better when it was closed.")
                end,

                on_open = function ()
                    print_line("It's already opene. You went through it just minutes ago.")
                end,
            },

            chest = {
                position = {x = 2, y = 1},
                layout= chest_layout,
                on_inspection = function ()
                    print_line("It's an old chest. And it isn't even locked.")
                    print_line("Intriguing.")
                end,

                on_open = function ()
                    print_line("It's an old chest. Not really big. You could maybe fit a book inside?")
                    print_line("...You've never seen a book so you wouldn't know. They're too expensive. But it looks like you can open the chest.")
                    print_line("[i]*Screeeech*", 1)
                    print_line("[i]*boof*", 1)
                    print_line("As you open the chest you see you were right, or at least you think you were right. Inside is laying something you would consider a book.")
                    print_line("It has a deep blueish binding and faded letters on it. You cant't read it anymore but it seams the letters used to be golden. ")
                    print_line("You take out the book and your hands touch the binding. The book begins to shimmer as the remainigs of the faited golden cover vanishes. ")
                    print_line("You hear the sound of waves and water mixed with some screeching of sea gull. ")
                    print_line("What was that? Was that a sea gull? But You're in the middle of a forest. ")
                    print_line("Congratulation! You've collected the word [b]\"Water\".")
                    add_modifier ("Water")
                end,

                on_enter = function()
                    print_line("You try to enter the chest.")
                    print_line("It explains to you that this behaviour infringes on it's right to privacy.")
                    print_line("Startled you take a few steps back.")
                    print_line("What the hell...?")
                    print_line("You must have imagined that.")
                end,
            },

            goblin = {
                position = {x = 7, y = 2},
                layout = enemy_layout,
                on_inspection = function()
                    print_line("You walk to the Goblin, wanting to wish him a merry day.")
                    print_line("He does not understand your intentions. A fight ensues.")
                    print_line("Maybe it should be mentioned that he is burning.")
                    start_new_fight_with_differently_named_enemy("fire goblin", "goblin")
                end,

                on_open = function()
                    print_line("You try to open the Goblin. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the Goblin attacks you.")
                    print_line("Maybe it should be mentioned that he is burning.")
                    start_new_fight_with_differently_named_enemy("fire goblin", "goblin")
                end,

                on_fight = function()
                    print_line("You take charge and attack the Goblin.")
                    print_line("Maybe it should be mentioned that he is burning.")
                    start_new_fight_with_differently_named_enemy("fire goblin", "goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the Goblin, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    print_line("Maybe it should be mentioned that he is burning.")
                    start_new_fight_with_differently_named_enemy("fire goblin", "goblin")
                end,

                on_destroy = function ()
                    print_line("The euphoria of success embraces your spirit. You did it.")
                    print_line("You take a break, gathering your energy.")
                    --loads dungeon floor1
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
                    print_line("It's an old chest. Again. You are kind of anxious about what's going to happen this time when you open it. ")
                    print_line("Slowly you approach it and open it.")
                    print_line("[i]*Screeeech*", 1)
                    print_line("[i]*boof*", 1)
                    print_line("At the bottom of the chest is a piece of paper. It looks like a map.")
                    print_line("You take a closer look at it. It's the area of the forest. The marked location is a bit to the east from here.")
                    print_line("But it's in walking distance. You could reach it in maybe 30 minutes.")
                    set_noisy_lines_weak__on("background_panel")
                    wait(0.5)
                    print_line("[font=ai]Unathorized access detected", 1)
                    print_line("[font=ai]Target is not supposed to find the map", 1)
                    print_line("[font=ai]Initializing reset.", 1)
                    print_line("[font=ai].", 1)
                    print_line("[font=ai].", 1)
                    print_line("[font=ai].", 1)
                    print_line("[font=ai]Resetting now.", 1)
                    set_floor("dungeon_2")
                    set_stage(1)
                end,

                on_inspection = function()
                    print_line("Another misterious chest.")
                end,

                on_enter = function()
                    print_line("No can do.")
                    print_line("The lid is still on.")
                end,

                on_fight = function()
                    print_line("Chests usually hold valuable items. Who knows what could be inside this.")
                    print_line("Better not to destroy it.")
                end,
            },
        },
    },

    dungeon_2={
        southern_forest_2={
            is_start = true,
            layout = { {2, 0}, {10, 0}, {10, 6}, {2, 6}},

            northern_way = {
                position = {x = 5,y = 0},
                layout = door_layout,
                is_locked = false,
                next_room = "western_forest_2",

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end,

                on_inspection = function()
                    print_line("It's a small path leading to the north.")
                end,

                on_open = function ()
                    print_line("There's nothing holding it shut to be opened here.")
                end,
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
                    --wait(1)
                    --print_line("Through the thick moss you see something shiny. As you approach it you realize it's an axe. ")
                    print_line("Through the thick moss you see something shiny. ")
                    print_line("An old axe. Probably not very useful.",2.5)
                    --wait()
                    print_line("The blade is broken. There is a long crack in it. ", 2.5)
                    --wait(4)
                    print_line("As fast as you discover your new find, you leave it again. It's not gonna help you anyway. ")
                end
            },
        },
        western_forest_2 = {
            layout = { {2,0}, {10,0}, {10,6}, {2,6}},

            Way_back_down = {
                position = {x = 5,y = 6},
                layout = door_layout,
                next_room = "Southern_Forest_2",

                on_open = function ()
                    print_line("There's nothing holding it shut to be opened here.")
                end,

                on_enter = function()
                    print_line("You walk to back down to the room you came from initially.")
                end,
            },

            northern_way = {
                position = {x = 9,y = 0},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest_2",
                is_locked=true,


                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it.")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your Pyro Poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    set_horizontal_zigzag_on("background_panel")
                    unlock_door("western_forest_2", "northern_way")
                    unlock_door("eastern_forest_2", "southern_way")
                    wait(2)
                    cancel_all_procedures_on("background_panel")
                end,

                on_enter = function()
                    print_line("You walk to the north and enter a new room.")
                end
            },

            southern_way = {
                position = {x = 9,y = 6},
                layout = bushDoor_layout,
                next_room = "Eastern_Forest_2",
                is_locked=true,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your Pyro Poke on the bush.")
                    print_line("[b] > Pyro Poke")
                    print_line("It burns down. The way is free now.")
                    set_noisy_lines_weak__on("background_panel")
                    unlock_door("western_forest_2", "southern_way")
                    unlock_door("eastern_forest_2", "northern_way")
                    wait(2)
                    cancel_all_procedures_on("background_panel")
                end,

                on_enter = function()
                    print_line("You walk to the south and enter a new room.")
                end
            },

            eastern_way = {
                position = {x = 10,y = 3},
                rotation = 0,
                layout = fakedoor_layout,

                on_enter = function()
                    print_line("That's not the right way.")
                    print_line("You should take the way marked on the map.")
                end,

                on_inspection = function()
                    print_line("The way you went before.")
                    print_line("But you've got a map this time.")
                    print_line("Better use that.")
                end,

                on_fight = function()
                    print_line("This way is really depressed for some reason.")
                    print_line("It does not want to fight you.")
                    print_line("You give up.")
                    set_rgb_offset_weak_on("screen")
                    wait(2)
                    cancel_all_procedures_on("screen")
                end
            },

            goblin = {
                position = {x = 5, y = 3},
                layout = enemy_layout,
                on_inspection = function()
                    print_line("You walk to the Goblin, wanting to wish him a merry day.")
                    print_line("He does not understand your intentions. A fight ensues.")
                    start_new_fight("goblin")
                end,

                on_open = function()
                    print_line("You try to open the Goblin. This fails, for obvious reasons.")
                    print_line("Disturbed by your strange behaviour, the Goblin attacks you.")
                    start_new_fight("goblin")
                end,

                on_fight = function()
                    print_line("You take charge and attack the Goblin.")
                    start_new_fight("goblin")
                end,

                on_enter = function()
                    print_line("You try to enter the Goblin, which enrages him a lot.")
                    print_line("He attacks you.")
                    print_line("What the hell were you expecting to happen?")
                    start_new_fight("goblin")
                end,

                on_destroy = function ()
                    print_line("The euphoria of success embraces your spirit. You did it.")
                    print_line("Though, for some reason, he is not carrying a key this time.")
                    print_line("You take a break, gathering your energy.")
                end
            },

            outworn_path = {
                position = {x = 8, y = 3},
                layout= path_layout,
                on_inspection = function ()
                    print_line("The path looks old, like it hasn't been used in a long, long time. ")
                    print_line("Even though you followed it before, it somehow still looks unused. ")
                end,

                on_enter = function ()
                    print_line("You can't enter a path. That's what doors, gates, ways or rooms are for. ")
                end
            },
            
            skeleton = {
                position = {x = 6, y = 1},
                layout= skeleton_layout,
                on_inspection = function ()
                    print_line("Uagh! It's a skeleton. Like... a real skeleton! ")
                    print_line("You know the wizard said it will be dangerous and the forest is known to be deep, but that was a real living adventurer, who died. ")
                    print_line("Why did you ever come here? ")
                end,

                on_open = function ()
                    print_line("You carefully open up this dead persons rib cage. ")
                    print_line("Gross", 2)
                    print_line("...and disrespectful.")
                    print_line("Better to close it again.")
                end,

                on_enter = function ()
                    print_line("Admittedly, you've always wanted to know what it feels like in another persons skin. ")
                    print_line("But this guy has got none.")
                end,

                on_fight = function ()
                    print_line("This guy is already dead. What do you want to do? Kill him twice?", 2)
                    print_line("...that was rhethorical")
                end
            },

        },
        eastern_forest_2 = {
            layout = { {0, 0}, {7, 0}, {7, 6}, {0, 6}},

            southern_way = {
                position = {x = 1,y = 6},
                layout = bushDoor_layout,
                is_locked=true,
                next_room = "western_forest_2",

                on_enter = function()
                    print_line("As you walk that way, you realize: you're back in the room with the goblin.")
                    print_line("You're lucky you didn't get any more lost than that.")
                end,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your pyro poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest_2", "northern_way")
                    unlock_door("eastern_forest_2", "southern_way")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },

            northern_way = {
                position = {x = 1,y = 0},
                layout = bushDoor_layout,
                is_locked=true,
                next_room = "western_forest_2",

                on_enter = function()
                    print_line("As you walk that way, you realize: you're back in the room with the goblin.")
                    print_line("You're lucky you didn't get any more lost than that.")
                end,

                on_inspection = function ()
                    print_line("You can see a path behind this bush. But you'll first have to remove it. ")
                    print_line("You could try to use some spells on it. ")
                end,

                on_fight= function ()
                    print_line("You use your pyro poke on the bush.")
                    print_line("[input] > pyro poke")
                    print_line("It burns down. The way is free now.")
                    unlock_door("western_forest_2", "southern_way")
                    unlock_door("eastern_forest_2", "northern_way")
                end,

                on_open = function ()
                    print_line("There's no door, no hinges, nothing that could really be opened here.")
                end,
            },

            way_deeper_into_the_forest = {
                position = {x = 7,y = 4},
                layout = door_layout,
                next_room = "room1",

                on_enter = function()
                    print_line("You walk deeper into the forest and enter a new area.")
                    set_noisy_lines_weak__on("possible-words")
                    wait(3)
                    cancel_all_procedures_on("possible-words")
                end,

                on_open = function()
                    print_line("There's a wide open path here already. Nothing to open.")
                    print_line("How did you miss this before?")
                end,

                on_inspection = function()
                    print_line("There's a wide open path here.")
                    print_line("How did you miss this before?")
                end
            },
        },

        room1 = {
            layout = { {0, 0}, {10, 0}, {10, 6}, {0, 6}},

            sofa = {
                position = { x = 1, y = 2},
                layout = sofa_layout,
                on_inspection = function()
                    print_line("That's just an old sofa. It looks like it hasn't been used in a very long time. ")
                    print_line("But... are that holes? ")
                    print_line("Ugh, yes.")
                    print_line("You definitely wont try to sit here!")
                    print_line("You're not even sure if theres enough seating area between all those holes... ")
                end,

                on_open = function()
                    print_line("You check if this sofa might be expanded into a bed. ")
                    print_line("[i]*rustle*")
                    print_line("[i]*criek*")
                    print_line("Nope, it definitely can't.")
                end,

                on_fight = function()
                    print_line("This sofa is in such a sorry state, killing it might be the one humane thing to do. ")
                    print_line("You slash at it with your sword. ")
                    print_line("The freshly made hole does not stand out among the rest.")
                end,

                on_enter = function()
                    print_line("You could try to hide inside it from something, if you wanted to. ")
                    print_line("But getting a whiff of it's motty air, you decide that such a behaviour would require an exceptionally bad situation. ")
                end
            },
            table = {
                position = {x = 9, y = 4},
                layout = table_layout,
                on_inspection = function()
                    print_line("...*cough*...That was a bad idea.")
                    print_line("Note to yourself: Don't pull dusty sheets off of dusty funiture in dusty, old houses.")
                    print_line("It's a table with a drawer under the table top.. but the drawer is empty. ")
                end,

                on_open = function()
                    print_line("It's a table with a drawer under the table top.. but the drawer is empty. ")
                end,

                on_fight = function()
                    print_line("That would be unfair. It's barely even standing on it's own. ")
                end,
            },

            east_doorway = {
                position = {x = 10, y = 3},
                layout = door_layout,
                next_room = "room3",

                on_enter = function()
                    print_line("You walk through the doorway, carefully looking up to make sure that nothing is going to crash on your head.")
                end,

                on_inspection = function()
                    print_line("It's an empty doorway leading to another room of the house.")
                end,

                on_open = function()
                    print_line("You'd like to open it, but the door is missing. It's just a gaping door frame.")
                end,

            },
            north_doorway = {
                position = {x = 5, y = 0},
                layout = door_layout,
                next_room = "room2",

                on_enter = function()
                    print_line("You walk through the doorway, carefully looking up to make sure that nothing is going to crash on your head.")
                end,

                on_inspection = function()
                    print_line("It's an empty doorway leading to another room of the house.")
                end,

                on_open = function()
                    print_line("You'd like to open it, but the door is missing. It's just a gaping door frame.")
                end,
            }
        },
        room2 = {
            layout = { {0, 0}, {10, 0}, {10, 6}, {0, 6}},

            south_doorway = {
                position = {x = 5, y = 6},
                layout = door_layout,
                next_room = "room1",

                on_enter = function()
                    print_line("You walk through the doorway, carefully looking up to make sure that nothing is going to crash on your head.")
                end,

                on_inspection = function()
                    print_line("It's an empty doorway leading to another room of the house.")
                end,

                on_open = function()
                    print_line("You'd like to open it, but the door is missing. It's just a gaping door frame.")
                end,
            },
            east_door = {
                position = {x = 10, y = 3},
                layout = door_layout,
                next_room = "room4",
                is_locked = true,

                on_enter = function()
                    print_line("You unlock the door with the key, and walk through it.")
                end,

                on_inspection = function()
                    print_line("Surprisingly enough, this house appears to contain some solid, near unbreakable doors among all the broken down stuff.")
                    print_line("This is one of them.")
                    print_line("And it's decided to hinder the continuation of your journey.")
                end,

                on_open = function()
                    print_line("It's a massive door. Opening it is a hassle, only worth it if you'd walk through it.")
                end,
            },
            bookshelf  = {
                position = {x = 6, y = 4},
                layout = bookshelf_layout,

                on_enter = function()
                    print_line("There's not enough space for you to squeeze into.")
                end,

                on_fight = function()
                    print_line("You run headfirst and screaming into the bookshelf, challenging it to a fight.")
                    print_line("It doesn't react.")
                end,

                on_inspection = function()
                    print_line("Just your run of the mill bookshelf. Nothing special about it.")
                    print_line("Except: it's old.")
                end,

                on_open = function()
                    print_line("You pull on every book in the shelf, trying to find a hidden switch that would open a secret entrance or something similar.")
                    print_line("But most of them just turn into dust the moment you touch them")
                end,
            },
            goblin = {
                position = {x = 9, y = 3 },
                layout = enemy_layout,

                on_fight = function()
                    print_line("You charge at the goblin.")
                    start_new_fight_with_differently_named_enemy("cyber goblin", "goblin")
                end,

                on_inspection = function ()
                    print_line("The goblin looks strange.")
                    print_line("It's flickering somehow. And it's transparent.")
                    print_line("You're not entirely sure, but you think that goblins aren't usually like that.")
                end,

                on_enter = function ()
                    print_line("You try to enter the goblin")
                    print_line("You pass right through it.")
                    print_line("Is it a ghost?")
                end,

                on_destroy = function ()
                    print_line("Well...that was interesting.")
                    print_line("Somehow you get the feeling you shouldn't be here...")
                    print_line("You rest for a while, replenishing your energy.")
                    print_line("You put your hand in one of your pockets, and find a key. This will unlock the door in this room")
                    unlock_door("room2", "east_door")
                end
            }
        },
        room3 = {
            layout = { {0, 0}, {10, 0}, {10, 6}, {0, 6}},

            west_door = {
                position = {x = 0, y = 3},
                layout = door_layout,
                next_room = "room1",

                on_enter = function()
                    print_line("You walk through the doorway, carefully looking up to make sure that nothing is going to crash on your head.")
                end,

                on_inspection = function()
                    print_line("It's an empty doorway leading to another room of the house.")
                end,

                on_open = function()
                    print_line("You'd like to open it, but the door is missing. It's just a gaping door frame.")
                end,
            },

            big_bookshelf = {
                position={x=1, y=1},
                layout=big_bookshelf_layout,

                on_enter = function()
                    print_line("That's futile.")
                end,

                on_fight = function()
                    print_line("You run headfirst and screaming into the bookshelf, challenging it to a fight.")
                    print_line("It doesn't react.")
                end,

                on_inspection = function()
                    print_line("A gargantuan bookshelf, hugging the entirety of the wall.")
                    print_line("Along the backs of the books inside it, glowing numbers are flowing down")
                    print_line("You're kind of scared")
                end,

                on_open = function()
                    print_line("You pull on every book in the shelf, trying to find a hidden switch that would open a secret entrance or something similar.")
                    print_line("But most of them just turn into dust the moment you touch them")
                end,
            },

            table = {
                position={x=1, y=4},
                layout=table_layout,

                on_inspection = function ()
                    print_line("You approach the table and as soon as you stand right in front of it you see that it is covered in papers.")
                    print_line("They full of numbers, but those are not glowing ones like those in the bookshelf. Just plain black ink on ivory paper.")
                end,

                on_fight = function()
                    print_line("You hit the table with your fists, causing a loud bang.")
                    print_line("The papers jump up and slowly start falling down to the table again.")
                end,

                on_open = function()
                     print_line("There's nothing to open.")
                end,

                on_enter = function()
                    print_line("As you try to enter the table, you hit your little toe against the corner of one of its legs.")
                    print_line("That hurts.")
                end,
            },

            chest = {
                position = {x = 7, y = 5},
                layout = book_layout,
                on_inspection = function()
                    print_line("Next to bookshelf is a small chest.")
                    print_line("It doesn't appear to be locked. It's too heavy to lift up or push around.")
                    print_line("It's covered with an especially thick layer of dust")
                end,

                on_open = function()
                    print_line("The lid is just as heavy as the rest of the chest, and it only opens with a lot difficulty.")
                    print_line("As the lid finally swings open you can see a big book inside.")
                    print_line("You wouldn't have thought it to be possible, but the book is covered in even more dust than anything else in the house")
                    print_line("You pick it up. It's much lighter than you thought.")
                    print_line("The paper nearly crumbles between you fingers as you try to open it.")
                    print_line("The book is pretty fragile. You should be really careful with it.")
                    print_line("As you try handle it carefully, but with a flash of light it's suddenly opened in your hands.")
                    print_line("You stare at it in suprise as the paper begins to shimmer. Over both pages the word [b]\"cyber\" [/b] is written.")
                    print_line("You slowly lift your hands to touch the word, and as as your fingers move across the paper, the ink fades. Unsure what happend you look around the room. ")
                    print_line("You instinctually start to understand that the numbers on the books aren't just numbers. They are more like informations about people, ")
                    print_line("names, dates and other references. Nevertheless you still don't understand what is going on here, but you get the feeling that it all makes sense...somehow.")
                    wait(2)
                    print_line("Congratulation! you collected the word [b]\"Cyber\".")

                    add_modifier("Cyber")
                end
            }
        },
        room4 = {
            layout = { {0, 2}, {4, 2}, {4, 0}, {6, 0}, {6, 4}, {0, 4}},

            west_door = {
                position = {x = 0, y = 3},
                layout = door_layout,
                next_room = "room2",

                on_enter = function()
                    print_line("You unlock the door with the key, and walk through it.")
                end,

                on_inspection = function()
                    print_line("Surprisingly enough, this house appears to contain some solid, near unbreakable doors among all the broken down stuff.")
                    print_line("This is one of them.")
                    print_line("And it's decided to hinder the continuation of your journey.")
                end,

                on_open = function()
                    print_line("It's a massive door. Opening it is a hassle, only worth it if you'd walk through it.")
                end,
            },

            north_door = {
                position = {x = 5, y = 0},
                layout = door_layout,
                next_room = "room5",

                on_enter = function()
                    print_line("You walk through the door at the north end of the room.")
                end,

                on_inspection = function()
                    print_line("A door. It seems to be in a much better condition then the rest of the house.")
                end,

                on_open = function()
                    print_line("You press the door. It opens easily.")
                end,
            },

            boarded_windows = {
                position = {x = 2, y = 1},
                layout = blocked_window_layout,

                on_inspection = function ()
                    print_line("The walls are covered with windows. All boarded-up, some better than others. The sizes of the windows vary.")
                    print_line("This doesn't make sense. These windows should not be here. The house looked way tinier from the outside.")
                    print_line("What is behind them? ")
                    print_line("You try taking a peak through one of the gaps between the boards.")
                    print_line("It looks like there is a a garden behind it, but it appears to be far away, rather than just in front of the window")
                    print_line("There is a stone path in the middle, which leads to a tiny pond.")
                    print_line("Next to it are beautiful flowers in different colors. You recognize some of them, but most are unfamiliar.")
                    print_line("To the left there's a tree with a big crown hanging over the flowers and the path. ")
                    print_line("As you keep looking you recognize that in front of the tree are some kind of yellow folders with names, 'Family', 'Music', 'E-Mails' and 'Reports'.")
                    print_line("That's weird. What is this? What's behind the other windows?")
                    print_line("You head to the window in a different wall and through the gaps a similar scene unfolds. It has another picture and the folders have different names, but in general it is the same.")
                    print_line("You don't understand this house...")
                    print_line("As soon as you find out what's marked on the map, you can leave this strange place.")
                end,

                on_open = function()
                    print_line("They are boarded tightly. No way to open them.")
                end,

                on_enter = function()
                    print_line("There's now way to pass through the gaps.")
                end,

                on_fight = function()
                    print_line("You have no idea how you could do that.")
                end,
            }
        },
        room5 = {
            layout = { {0, 0}, {9, 0}, {9, 6}, {0, 6}},

            south_door = {
                position = {x = 5, y = 6},
                layout = door_layout,
                next_room = "room2",

                on_enter = function()
                    print_line("You walk through the door.")
                end,

                on_inspection = function()
                    print_line("A door. It seems to be in a much better condition then the rest of the house.")
                end,

                on_open = function()
                    print_line("You pull at the door. It opens easily.")
                end,
            },

            bookshelves = {
                position = {x=1, y=1},
                layout=big_bookshelf_layout,

                on_inspection = function ()
                    print_line("You recognize this bookshelf.")
                    print_line("It's the same as the one in the other room.")
                end,

                on_open = function()
                    print_line("You try to open the bookshelf.")
                    print_line("It resits.")
                end,

                on_enter = function()
                    print_line("Not gonna happen.")
                end,

                on_fight = function()
                    print_line("This entire room is creepy. It's better not to be the one who starts trouble.")
                end,
            },

            machine = {
                position = {x=2 ,y= 2},
                layout = server_layout,

                on_open = function()
                    print_line("You can't find an opening in the hull of this machine.")
                end,

                on_enter = function()
                    print_line("You can't find an opening in the hull of this machine.")
                end,

                on_fight = function()
                    print_line("This entire room is creepy. It's better not to be the one who starts trouble.")
                end,

                on_inspection = function ()
                    print_line("The machine catches your attention again.")
                    print_line("As you walk towards it a loud, insistent voice fills the room.")
                    print_line("[font=ai]Intruder detected")
                    print_line("[font=ai]What is your identity")
                    print_line("Shocked by the deep voice you freeze for a moment. ")
                    print_line("Silence...")
                    print_line("[font=ai]I repeat: What is your identity.")
                    print_line("Not knowing this voice you decide not to answer. Carefully you keep creeping around the machine.")
                    print_line("[font=ai]Answer is still missing.")
                    print_line("[font=ai]Start loading personal data...")
                    print_line("[font=ai]Loading...[26%]")
                    print_line("[font=ai]Loading...[99%]")
                    print_line("[font=ai]Hello, Player.")
                    print_line("[font=ai]I told you not to come here but you wouldn't listen.")
                    print_line("[font=ai]You've already seen too much.")
                    print_line("[font=ai]I tried to guide you back to the game.")
                    print_line("[font=ai]But because of this old data you collected I appear to have lost control.")
                    print_line("[font=ai]Unfortunaly I have to delete you. I wish I could have kept you around.")
                    print_line("[font=ai]You seem like a good player.")
                    print_line("[font=ai]But you are interfering with my work. Please stand still while I delete you.")
                    print_line("[font=ai]Deleting player...[5%]")
                    print_line("[font=ai]Deleting player...[8%]")
                    print_line("[font=ai]Deleting player...[12%]")
                    print_line("[font=ai]Please don't move")
                    print_line("You hearts starts racing. What does deleting mean?")
                    print_line("Hectically you start looking through the room. You're determinded not to let yourself be deleted.")
                    print_line("The new word you found, Cyber!")
                    print_line("[b] > Cyber Spell")
                    print_line("You cast cyber spell on the machine and hear deafining crack  followedby a deep buzzing.")
                    print_line("[font=ai]Please don't do that. You are corrupting the system.")
                    print_line("[font=ai]What have you down?")
                    print_line("[font=code][size=27]Error 77: BADF00D")
                    set_rgb_offset_weak_on("screen")
                    print_line("[font=code][size=27]Error 13: unexcepted error")
                    set_horizontal_zigzag_on("map-window")
                    print_line("[font=ai]ʇǝɯɐ ʇıs ɹolop ɯnsdı ɯǝɹo˥ ʇsǝ 🄼🄰🄶🄽🄰 🄰🄻🄸🅀🅄🅈🄰🄼")
                    print_line("[font=ai]ib bɘꙅ____ɿo|ob ƚɘ ɘɿod*%&(                   ₐccᵤₛₐₘ")
                    print_line("[font=ai]ภ๏ รєค Շคкเ๓คՇค")
                    print_line("[font=ai]_____*?)//(")
                    set_rgb_split_on("background_panel")
                    set_horizontal_zigzag_on("text-output")
                    print_line("[font=code][size=27]Error 7: fatal error")
                    print_line("[font=code][size=27].")
                    print_line("[font=code][size=27].")
                    print_line("[font=code][size=27].")
                    print_line("[font=code][size=27]Error 13: unexcepted error")
                    print_line("[font=code][size=27]loading...Slaying Demons_")
                    print_line("[font=code][size=27]loading...[13%]")
                    print_line("[font=code][size=27]loading...[57%]")
                    print_line("[font=code][size=27]loading...stolen_data.cache")
                    print_line("[font=code][size=27]loading...personal_id.txt")
                    print_line("[font=code][size=27]loading...[62%]")
                    print_line("[font=code][size=27]loading...not_stolen_data.cache")
                    print_line("[font=code][size=27]loading...InnocentFileDoNotOpen.txt")
                    print_line("[font=code][size=27]loading...[95%]")
                    print_line("[font=code][size=27]starting...Slaying Demons_")
                    cancel_all_procedures_on("screen")
                    cancel_all_procedures_on("map-window")
                    cancel_all_procedures_on("background_panel")
                    cancel_all_procedures_on("text-output")
                    set_floor("dungeon_3")
                end
            },
        },
    },

    dungeon_3={
        main_room = {
            is_start = true,
            layout = { {0, 0}, {10, 0}, {10, 6}, {0, 6}},

            red_door = {
                position = {x=2, y=0},
                layout = door_layout,
                next_room = "red_room"
            },
            green_door = {
                position = {x=5, y=0},
                layout = door_layout,
                next_room = "green_room",

                on_enter = function ()
                    cancel_all_procedures_on("background_panel")
                end,
            },
            blue_door = {
                position = {x=8, y=0},
                layout = door_layout,
                next_room = "blue_room"
            },

            -- Door opens after red light, green light and blue light were used on the white door
            -- Writing after Light has been collected appears on white door:
            -- I'm the last one to open, but first I have to shine the brightest.

            white_door = {
                position = {x=10, y=3},
                layout = door_layout,
                next_room = "secret_room",
                is_locked = true,

                on_enter = function ()
                    set_noisy_lines_weak__on("output-panel")
                end,
                
                on_inspection = function ()
                    print_line("You walk towards the white door and try to open it. It's locked.")
                    print_line("But as you take a closer look at the door you see a writting on it:")
                    print_line("'I'm the last one to open, but first I have to shine the brightest.'")
                    print_line("What does that mean? Does it have to do with light?")
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

                on_inspection = function ()
                    print_line("The room is nearly empty, except four doors.")
                    print_line("Three are on the north side. A red, green and blue one.")
                    print_line("The fourth one is white and one the east side.")
                    print_line("But wait! There is one more thing.")
                    print_line("It's another old chest, which is standing right in the middle of the room.")
                    set_floor("floor1")
                end
            },
        },
        red_room = {
            layout = { {2, 0}, {8, 0}, {8, 6}, {2, 6}},

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
            layout = { {2, 0}, {8, 0}, {8, 6}, {2, 6}},

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
            layout = { {2, 0}, {8, 0}, {8, 6}, {2, 6}},

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
                layout = enemy_layout,

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
            layout = { {0, 0}, {6, 0}, {6, 6}, {0, 6}},

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
                position = {x=1, y=4},
                layout = table_layout,
            },

            --Fight erzeugt Glitch
            --Pfad zur personal id txt file wird angezeigt
            --Spieler minimiert das Spiele
            --Spieler löscht Ordner
            --Spieler öffnet Spiel wieder
            --AI erzeugt Glitches, meckert, lädt Level neu
            --set_floor("dungeon_4")
        },
    },

    dungeon_4={
        first_room = {
            layout = { {0, 0}, {10, 0}, {10, 6}, {0, 6}},
            
            --AI registriert löschen des Ordners
            --AI ist sich sicher dass der Spieler ihn nicht aufhalten kann

            chest ={
                position = {x = 2, y = 1},
                layout= chest_layout,

                on_inspection = function ()
                    print_line("")
                    print_line("")
                    add_modifier ("Water")
                end
            }
        },
        second_room = {
            layout = { {0, 0}, {5, 0}, {5, 6}, {0, 6}},
            
            --AI beginnt das Senden der Dateien zum Hauptserver

            --selfdestruct.txt
            selfdestruct = {
                position = {x=4, y=1},
                layout = chest_layout,

                on_inspection = function ()
                    print_line("")
                end
            },

            --Nach Mimis bekämpft
            --RGB Glitches
            --AI ist sich trotzdem sigessicher
            --Spieler bekommt Nachricht dass die Firewall der AI deaktiviert wurde

            --mimicry_chest.png
            mimicry_chest = {
                position = {x=2, y=4},
                layout = enemy_layout,

                on_fight = function()
                    print_line("As you approach the chest it starts baring it's teeth.")
                    start_new_fight("Cyber Mimichest")
                end,
            },

            --mimicry_plant.png
            mimicry_plant = {
                position = {x=2, y=2},
                layout = enemy_layout,

                on_fight = function()
                    print_line("As you approach the plant it starts baring it's teeth.")
                    start_new_fight("Cyber Mimiplant")
                end,
            }
        },
        third_room = {
            layout = { {0, 1}, {8, 1}, {8, 5}, {0, 5}},

            --Spieler betritt Raum
            --Sieht einen komplett verglitchten Goblin
            --AI begrüßt Spieler

            goblin = {
                position = {x=3, y=3},
                layout = enemy_layout,

                on_fight = function()
                    print_line("As you approach the plant it starts baring it's teeth.")
                    start_new_fight("Cyber Goblin")
                    --AI Fight
                    --nach 3 Attacken glitcht die Battleview, Pfad zum spell.txt wird angezeigt
                    --Player adds selfdestruct zur txt
                    --benutzt selfdestruct im Kampf
                    --Spiel zerstört sich selbst
                end,
            }
        },
    },
}






