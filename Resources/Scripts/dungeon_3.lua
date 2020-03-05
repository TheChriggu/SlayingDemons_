is_in_green_room = false
is_in_blue_room = false
is_in_red_room = false
is_in_main_room = false


function player_profile_deleted()
    --print_line("player_profile_deleted")
end

function self_destruct_added()
    print_line("self_destruct_added")
end

function input_received (input) 
    if input=="Inspect Room" and is_in_green_room then

    end
end



function room_changed(name)
    if name=="main_room" then
        is_in_main_room = true
        set_noisy_lines_medium_on("text-output")
        print_line_instant("You      ɯǝɹo˥ ʇsǝ 🄼🄰🄶🄽🄰 ")
        set_rgb_offset_weak_on("possible-words")
        print_line_instant("You procced your way deeper inside the house and eeeeeeeeeeeeeeeenter another room.")
        set_rgb_split_on("screen")
        print_line_instant("[font=code][size=27]Error 82: Unexcepted Input")
        cancel_all_procedures_on("possible-words")
        cancel_all_procedures_on("screen")
        print_line_instant("You walk down a long corridor and enter a new room.")
        print_line_instant("It's a big room with four doors in different colors. ")
        print_line_instant("The room is nearly empty, except those doors.")
        print_line_instant("Three are on the north side. A red, green and blue one.")
        print_line_instant("The fourth one is white and one the east side.")
        print_line_instant("But wait! There is one more thing.")
        cancel_all_procedures_on("text-output")
        set_noisy_lines_weak__on("background_panel")
        print_line_instant("It's another old chest, which is standing right in the middle of the room.")
    else
        is_in_main_room = false
    end
end

function room_changed(name)
    --print("ROOM changed")
    --print_line("[color=255,0,144,255]Room changed!")
    if name=="green_room" then
        is_in_green_room = true
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
    else
        is_in_green_room = false
    end
end

function room_changed(name)
    if name=="blue_room" then
        is_in_blue_room = true
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
    else
        is_in_blue_room = false
    end
end

function room_changed(name)
    if name=="red_room" then
        is_in_red_room = true
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
        print_line_instant("")
    else
        is_in_red_room = false
    end
end



