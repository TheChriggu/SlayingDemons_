is_in_intro = false


function input_received (input)
    if input=="Inspect Room" and is_in_intro then
        print_line("[color=255,0,144,255]Test")
    end
end

function room_changed(name)
    if name=="intro" then
        is_in_intro = true
    else
        is_in_intro = false
    end
end