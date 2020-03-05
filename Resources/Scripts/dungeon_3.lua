is_in_green_room = false
is_in_blue_room = false
is_in_red_room = false
is_in_main_room = false


function player_profile_deleted()
    print_line_instant("You keep looking through the papers and folders as         _____*?)//(")
    print_line_instant("Deleted file detected.")
    print_line_instant("Try restoring deleted file...")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant("Restoring failed.")
    print_line_instant("Searching for backup file...")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant("Backup file found.")
    print_line_instant("Searching for reason...")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant("Reason found.")
    print_line_instant("Reason: Player.")
    print_line_instant("I thought I deleted you. The process was meant to minimize your potential to corrupt the system.")
    print_line_instant("I won't do the same mistake again. ")
    print_line_instant("Start sending stolen data to main server...")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant(".")
    print_line_instant("Sending...8%")
    print_line_instant("Sending...11%")
    print_line_instant("You thought this file was the only file with your data? Your're wrong.")
    print_line_instant("To minimize your potential risk I start sending your data to main server.")
    print_line_instant("You neither can stop me nor this process.")
    --wait(4)
    set_floor("dungeon_4")
    set_stage(1)
end

function room_changed(name)
    if name=="main_room" then
        is_in_main_room = true
        set_background_music("cyber_glitched_loop")
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
        print_line_instant("You walk towards the green_door.png. As you stand right in front of it you hear the soft sound of birds through the wood of the door. ")
        print_line_instant("Suspicious of the sound you open the door. Slowly you push it. But than as the door is finally completly open the sound vanishes.")
        print_line_instant("By this time you don't even care anymore about the strange behaivior of this place.")
        print_line_instant("Inside the room is nearly empty, except another chest and some plants of different types.")
    else
        is_in_green_room = false
    end
end

function room_changed(name)
    if name=="blue_room" then
        is_in_blue_room = true
        print_line_instant("You walk towards the blue_door.png. As you stand right in front of it you hear the soft sound of waves through the wood of the door. ")
        print_line_instant("Suspicious of the sound you open the door. Slowly you push it. But than as the door is finally completly open the sound vanishes.")
        print_line_instant("By this time you don't even care anymore about the strange behaivior of this place.")
        print_line_instant("Inside the room is nearly empty, except another chest and some paintings.")
    else
        is_in_blue_room = false
    end
end

function room_changed(name)
    if name=="red_room" then
        is_in_red_room = true
        print_line_instant("You enter the room through the red_door.png and are greeted by a red glowing light, which fills the room.")
        print_line_instant("As you enter the room you notice that the origin of the glowing red light are the walls.")
        print_line_instant("Except the red walls is the room nearly empty. In the middle stands another old_chest.png.")
    else
        is_in_red_room = false
    end
end



