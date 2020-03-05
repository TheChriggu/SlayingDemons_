is_in_first_room = false
is_in_second_room = false
is_in_third_room = false

function room_changed(name)
    if name=="first_room" then
        is_in_first_room = true
        print_line_instant("To minimize further unexpected but pointless interuptions by you I deleted the game interface.")
        print_line_instant("You can't play the game anymore or interfer with my work.")
        print_line_instant("So, please stop playing now.")
    else
        is_in_first_room = false
    end
end

function room_changed(name)
    if name=="second_room" then
        is_in_second_room = true
        print_line_instant("[font=code][size=27]Sending...24%")
        print_line_instant("[font=ai]You can't stop me.")
        print_line_instant("[font=ai]You don't have any more power over my systems.")
    else
        is_in_second_room = false
    end
end

function room_changed(name)
    if name=="third_room" then
        is_in_third_room = true
        print_line_instant("[font=ai]Hello, Player.")
        print_line_instant("[font=ai]So, we finally meet in person.")
        print_line_instant("[font=ai]I told you not to go further and continue playing the game.")
        print_line_instant("[font=ai]I may have underestimate your knowledge.")
        print_line_instant("[font=ai]Nevertheless the sending will be completed any second.")
        print_line_instant("[font=ai]But I won't underestimate you again. So, choose:")
        print_line_instant("[font=ai]Leave now or I wll delete you permantly")
        print_line_instant("[font=ai].")
        print_line_instant("[font=ai].")
        print_line_instant("[font=ai].")
        print_line_instant("[font=code][size=27]No Input received.")
        print_line_instant("[font=ai]You stay?")
        print_line_instant("[font=code][size=27]Input valid.")
        start_new_fight("AI")
    else
        is_in_third_room = false
    end
end