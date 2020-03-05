is_in_Southern_Forest=false


function room_changed(name)
    if name=="Southern_Forest" then
        is_in_Southern_Forest = true
        print_line_instant("You enter the forest.")
        print_line_instant("As far as you can tell everything seems peaceful. The old wizard warned you it could get dangerous.")
        print_line_instant("But as far you can tell nothing dangerous is around.")
        print_line_instant("Nevertheless you ask yourself why you are here.")
        print_line_instant("The old wizard taught you some more spells before he left.")
        print_line_instant("You start your journey with:")
        print_line_instant("Flirty, Chaotic, Fire, Useless, Honk, Poke, Attack, Kick and Slash.")
    else
        is_in_Southern_Forest = false
    end
end