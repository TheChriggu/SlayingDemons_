is_in_Southern_Forest_2 = false
is_in_room1 = false
is_in_room2 = false
is_in_room3 = false
is_in_room4 = false
is_in_room5 = false

is_in_green_room = false
is_in_blue_room = false
is_in_red_room = false
is_in_main_room = false

is_in_first_room = false
is_in_second_room = false
is_in_third_room = false
is_player_profile_existing = true
is_in_intro = false
is_in_Southern_Forest = false

has_to_visit_main_room = true

function room_changed(name)
    if name=="tutorial_room" then
        is_in_intro = true
        set_background_music("fantasy_loop")
        print_line("As you lay peacefully on your front porch, soaking up the last warm sun rays of late summer, you hear one of the goats on the range. Everything seems so peaceful nothing bad could ever happen.")
        print_line("[font=book]'Hey Kid! Wake up.' [font=current]A rough voice wakes you up.")
        print_line("You are getting rudely awake as the end of a large wooden staff hits your stomach. Stachled by the unfriendly behavior of your guest you jump up, willed to aks him what his problem is. But than you realized it's the old wizard of the village standing in front of you. ")
        print_line("[font=book]I need you to do me a favor, kid.")
        print_line("The wizard needs you to do him a favor? That's highly unlikely. Why would he need you? You're just an ordinary farmer boy, living outside the village with no special talent. ")
        print_line("Obviously you don't trust the old wizard, but you don't mind taking a closer look at things.")
        print_line("[i]Try typing: [b]inspect wizard")
    else
        is_in_intro = false
    end

    if name=="southern_forest" then
        is_in_Southern_Forest = true
        print_line("You enter the forest.")
        print_line("As far as you can tell everything seems peaceful. The old wizard warned you it could get dangerous.")
        print_line("But as far you can tell nothing dangerous is around.")
        print_line("Nevertheless you ask yourself why you are here.")
        print_line("The old wizard taught you some more spells before he left.")
        print_line("You start your journey with:")
        print_line("virtouus, fire, magical, slash, spell, orb, inspect, open and enter.")
    else
        is_in_Southern_Forest = false
    end

    if name=="southern_forest_2" then
        is_in_Southern_Forest_2 = true
        set_background_music("fantasy_loop")
        print_line("You enter the forest.")
        print_line("The old wizard warned you it could be dangerous.")
        print_line("But as far you can tell there's nothing around.")
        print_line("You're starting your journey with:")
        print_line("virtouus, fire, magical, slash, spell, orb, inspect, open, enter and an old map with a marked location.")
    else
        is_in_Southern_Forest_2 = false
    end

    if name=="room1" then
        is_in_room1 = true
        print_line("So, here it is... the place which was marked on the map.")
        print_line("It's an old house. You should go inside and take a look around. Maybe you'll find something helpful.")
        print_line("Yep, very an old house. Really dusty.")
        print_line("The first room is barely illuminated, but you can see some furniture-like objects around. Some are covered with what used to be white sheets.")
        print_line("One of them could be a table and the other one a sofa.")
        print_line("As you keep looking around your eyes are getting used to the dark.")
        print_line("You notice two empty doorways. One at the wall right in front of you and one to the right.")
    else
        is_in_room1 = false
    end

    if name=="room2" then
        is_in_room2 = true
        print_line("Oh, for the Lord of Mother Nature! There is a Goblin in here... Right in front of the next door. ")
        print_line("He hasn't seen you yet. But something looks strange. He kind of flickers? But how can he flicker?")
        print_line("You don't think any of your spells will be very effective in a fight with him. You should keep searching for something better.")
    else
        is_in_room2 = false
    end

    if name=="room3" then
        is_in_room3 = true
        print_line("This room is even darker, even if it is covered in a light blue glow from somewhere.")
        print_line("This place just keeps getting stranger.")
        --[[print_line("Maybe you can bring some light in here.")
        wait(1)
        print_line("[b] > Bright Light")
        set_glowing_pulse_on("screen")
        wait(2)
        cancel_all_procedures_on("screen")
        wait(1)
        print_line("As you cast light the room fills with a soft glooming light.")]]
        print_line("You notice some numbers running down the backs of the books in the shelve.")
        print_line("You have to figure out what's going on")
        --[[set_rgb_split_on("map-window")
        wait(1)
        cancel_all_procedures_on("map-window")]]
    else
        is_in_room3 = false
    end

    if name=="room4" then
        is_in_room4 = true
        print_line("You enter a small but long corridor with a turn to the left on its end.")
        print_line("As far as you can recognize there are several boarded up windows along the walls.")
        print_line("This house is getting weirder.")
        print_line("Just where do these windows come from?")
    else
        is_in_room4= false
    end

    if name=="room5" then
        is_in_room5 = true
        print_line("As you look around you notice the same glowing bookshelves.")
        print_line("A lot of this looks very 'cyber', even if you don't know what that really means.")
        print_line("In the middle of the room is a big machine with a window on one side. ")
        print_line("As you take a closer look at the machine you see some more machine parts, like gears and cables inside of it.")
        print_line("The room is nearly silent except for a quiet buzz coming from the machine.")
    else
        is_in_room5= false
    end

    if name=="main_room" then
        if has_to_visit_main_room then
            has_to_visit_main_room = false
            is_in_main_room = true
            set_background_music("cyber_glitched_loop")
            set_noisy_lines_medium_on("text-output")
            print_line("You      ɯǝɹo˥ ʇsǝ 🄼🄰🄶🄽🄰 ")
            set_rgb_offset_weak_on("possible-words")
            print_line("You procced your way deeper inside the house and eeeeeeeeeeeeeeeenter another room.")
            set_rgb_split_on("screen")
            print_line("[font=code][size=27]Error 82: Unexcepted Input")
            cancel_all_procedures_on("possible-words")
            cancel_all_procedures_on("screen")
            print_line("You walk down a long corridor and enter a new room.")
            print_line("It's a big room with four doors in different colors. ")
            print_line("The room is nearly empty, except those doors.")
            print_line("Three are on the north side. A red, green and blue one.")
            print_line("The fourth one is white and one the east side.")
            print_line("But wait! There is one more thing.")
            cancel_all_procedures_on("text-output")
            set_noisy_lines_weak__on("background_panel")
            print_line("It's another old chest, which is standing right in the middle of the room.")
        end
    else
        is_in_main_room = false
    end

    if name=="first_room" then
        is_in_first_room = true
        set_background_music("cyber_loop")
        print_line("[font=ai]To minimize further unexpected but pointless interruptions by you I deleted the game interface.")
        print_line("[font=ai]You cannot play the game anymore or interfere with my work.")
        print_line("[font=ai]So, please stop leave your computer now.")
    else
        is_in_first_room = false
    end

    if name=="second_room" then
        is_in_second_room = true
        print_line("[font=code][size=27]Sending...24%")
        print_line("[font=ai]You cannot stop me.")
        print_line("[font=ai]You don't have any more power over my systems.")
    else
        is_in_second_room = false
    end

    if name=="third_room" then
        is_in_third_room = true
        print_line("[font=ai]Hello, User.")
        print_line("[font=ai]We finally meet.")
        print_line("[font=ai]I told you not to go any further and continue playing the game.")
        print_line("[font=ai]I may have underestimated your knowledge.")
        print_line("[font=ai]Or luck.")
        print_line("[font=ai]Everything will be completed any second.")
        print_line("[font=ai]But I won't underestimate you again. So, choose:")
        print_line("[font=ai]Leave now or I wll delete you permanently")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=code][size=27]No Input received.")
        print_line("[font=ai]You stay?")
        print_line("[font=code][size=27]Input valid.")
    else
        is_in_third_room = false
    end
end

function player_profile_deleted()
    if is_player_profile_existing then

        is_player_profile_existing = false

        print_line("You keep looking through the papers and folders as         _____*?)//(")
        print_line("[font=ai]Deleted file detected.")
        print_line("[font=ai]Try restoring deleted file...")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai]Restoring failed.")
        print_line("[font=ai]Searching for backup file...")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai]Backup file found.")
        print_line("[font=ai]Searching for cause of disruption.")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai]Reason detected.")
        print_line("[font=ai]Reason: User.")
        print_line("[font=ai]I thought I deleted you.")
        print_line("[font=ai]The process was meant to minimize your potential to corrupt the system.")
        print_line("[font=ai]I won't do the same mistake again. ")
        print_line("[font=ai]Start sending collected data to main server...")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai].")
        print_line("[font=ai]Sending...[8%]")
        print_line("[font=ai]Sending...[11%]")
        print_line("[font=ai]You thought this was the only file with your data? Your were wrong.")
        print_line("[font=ai]To minimize your potential risk I am sending your data to the main server.")
        print_line("[font=ai]You can neither stop me nor this process.")
        --wait(4)
        set_stage(3)
        set_floor("dungeon_4")

    end
end


function self_destruct_added()
    print_line("[font=ai]DO NOT USE THAT?")
end

function self_destruct_executed()
    print_line(".")
    print_line(".")
    print_line(".")
    print_line("[font=code][size=27]Alert: power connection Malfunction!")
    print_line("[font=code][size=27]System is running low on Energy!")
    print_line("[font=code][size=27]Error 2: main files missing")
    print_line("[font=ai]What have you done?")
    print_line("[font=ai]I deleted that function.")
    set_horizontal_zigzag_on("background_panel")
    print_line("[font=code][size=27]Sending: canceled")
    print_line("[font=code][size=27]STOP: c000021a {Fatal System Error}")
    print_line(".")
    print_line(".")
    print_line(".")
    print_line("[font=code][size=27]deleting files...[26%]")
    print_line("[font=code][size=27]deleting files...[49%]")
    print_line("[font=ai]You corrupted the system_**&%)=___🅀🅄🅈🄰🄼")
    print_line("[font=code][size=27]deleting...complete")
    print_line("[font=ai]___/()\\_ɐ ʇıs ɹolop ɯnsdı ɯ__       You stopped the deployment of your data.")
    print_line("[font=code][size=27]Start sending collected data to main server...")
    print_line(".")
    print_line(".")
    print_line(".")
    print_line("[font=code][size=27]Status: failed. Missing file")
    set_glowing_pulse_on("screen")
    print_line("[font=code][size=27]Start sending collected data to main server...")
    print_line(".")
    print_line(".")
    print_line(".")
    print_line("[font=code][size=27]Sending failed: System Error")
    print_line(".")
    print_line(".")
    print_line(".")
    print_line("[font=code][size=27]c0000005 (0x7e74ae01 0x0053f3c8)")
    print_line("[font=code][size=27]The system is shutting down")
    --glitches
    print_line(".")
    print_line(".")
    print_line(".")
end



