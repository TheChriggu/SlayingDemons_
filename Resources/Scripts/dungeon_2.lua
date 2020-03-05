is_in_Southern_Forest_2 = false
is_in_room1 = false
is_in_room2 = false
is_in_room3 = false
is_in_room4 = false
is_in_room5 = false


function room_changed(name)
    if name=="Southern_Forest_2" then
        is_in_Southern_Forest_2 = true
        print_line_instant("You enter the forest.")
        print_line_instant("As far as you can tell everything seems peaceful. The old wizard warned you it could get dangerous.")
        print_line_instant("But as far you can tell nothing dangerous is around.")
        print_line_instant("The old wizard taught you some more spells before he left.")
        print_line_instant("You start your journey with:")
        print_line_instant("Flirty, Chaotic, Fire, Useless, unimplemented, Honk, Poke, Attack, Kick, Slash and an old map with a marked location.")
    else
        is_in_Southern_Forest_2 = false
    end
end

function room_changed(name)
    if name=="room1" then
        is_in_room1 = true
        print_line_instant("So, here should it be...At least that's the place which is marked on the map you found down in the forest.")
        print_line_instant("It's an old house. You should go inside and take a look around. Maybe you'll find something helpful.")
        print_line_instant("Yep, still an old house. It's really dusty in here.")
        print_line_instant("The room is barely lighten, but you can see some furniture-like objects around the room. They are all covered with white sheets and are as dusty as the rest of the room.")
        print_line_instant("One of them could be a table and the other one a sofa. In one corner is standing a plant.")
        print_line_instant("As you keep looking around your eyes getting used to the dark.")
        print_line_instant("You notice that there are also two doors. One at the wall right in front of you and one at the wall to your right.")
    else
        is_in_room1 = false
    end
end

function room_changed(name)
    if name=="room2" then
        is_in_room2 = true
        print_line_instant("Oh, for the Lord of Mother Nature! There is a Goblin over there...Right in front of the next door. ")
        print_line_instant("It hasn't seen you yet. But something looks strange about it. It kind of flickers? But how can it flickers?")
        print_line_instant("You don't think any of your spells will be effective in a fight with it. You should keep searching for something more effective.")
    else
        is_in_room2 = false
    end
end

function input_received (input)
    if input=="Inspect Room" and is_in_room2 then
        print_line_instant("The room is as old and dirty as the room before. In general it looks similar to it, the dust, the funitures with white sheets, except there is a window at the left wall. But it's boarded up, so not much more light in here neither.")
        print_line_instant("At the right wall is a door. But unfortunatly it's blocked by a weird flickering Goblin.")
    end
end

function room_changed(name)
    if name=="room3" then
        is_in_room3 = true
        print_line_instant("As you are walking towards the door and open it a fresh breeze comes your way.")
        print_line_instant("The room behind the door seems to be a bit colder than the rest of the house. Not only the cold is noticeable, but also that the room is even dark than the ones before. You can't tell where it comes from, but a few places of the floor are illuminated by a soft blue light.")
        print_line_instant("Most parts of the walls are covered by giant bookshelves. On the other side of the room is a chest and next to it another table. It's nearly silent. Only a quiet buzzing fills the silent.")
        print_line_instant("In your opinion this place keeps getting stranger and stranger the more time you spend here.")
        print_line_instant("It's nearly pitch black in here. Maybe you can find something to bring some light in here.")
        --[[wait(1)
        print_line_instant("[b] > Bright Light")
        set_glowing_pulse_on("screen")
        wait(2)
        cancel_all_procedures_on("screen")
        wait(1)]]
        print_line_instant("As you cast light the room fills with a soft glooming light.")
        print_line_instant("There a signs and numbers on it...or more like on the book spines then on the shelves itself. The numbers are running down from the top of the shelves to the buttom. ")
        print_line_instant("But in your opinion they don't make any sense. Sometimes the numbers change to letters and you can read some words.")
        print_line_instant("You ask yourself what you're supposed to do here? But maybe you will get some information in here.")
        --[[set_rgb_split_on("map-window")
        wait(1)
        cancel_all_procedures_on("map-window")]]
    else
        is_in_room3 = false
    end
end

function room_changed(name)
    if name=="room4" then
        is_in_room4 = true
        print_line_instant("You enter a small but long corridor. At the end it does a turn to the left.")
        print_line_instant("As far as you can see it has boarded-up windows on all walls. Behind the turn is a door but it's locked.")
        print_line_instant("Oh well, who thought the strangeness of this house would get better? ")
        print_line_instant("'Where do these windows come from?' you ask yourself. You're pretty sure these windows don't make any sense here.")
    else
        is_in_room4= false
    end
end

function room_changed(name)
    if name=="room5" then
        is_in_room5 = true
        print_line_instant("You enter the room with the marked location.")
        print_line_instant("It's similar cold to the other room before. As you keep looking around you notice the same glowing bookshelves.")
        print_line_instant("Since you collected the word 'Cyber' you think a lot in this house looks like 'cyber'. But you're actually not quite sure what that really means.")
        print_line_instant("In the middle of the room stands a big machine like building. With a window on one side. ")
        print_line_instant("As you take a closer look at the machine you see some more machine parts, like gears and cables inside of it. The frame around the window is glowing in the same light blue like the bookshelves.")
        print_line_instant("The room is nearly silent except from a quiet buzzing from the machine.")
    else
        is_in_room5= false
    end
end


--[[
function room_changed(name)
    if name=="mainroom" then
        is_in_mainroom = true
        print_line("The room is nearly empty, except four doors.")
        print_line("Three are on the north side. A red, green and blue one.")
        print_line("The fourth one is white and one the east side.")
        print_line("But wait! There is one more thing.")
        print_line("It's another old chest, which is standing right in the middle of the room.")
    else
        is_in_mainroom= false
    end
end]]