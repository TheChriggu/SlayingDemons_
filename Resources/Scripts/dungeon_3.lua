is_in_green_room = false


function input_received (input)
    if input=="Inspect Room" and is_in_green_room then
        print_line("[color=255,0,144,255]Test")
    end
end

--[[function room_changed(name)
    print("ROOM changed")
    --print_line("[color=255,0,144,255]Room changed!")
    if name=="green_room" then
        is_in_green_room = true
    else
        is_in_green_room = false
    end
end]]