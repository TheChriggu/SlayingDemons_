is_in_intro = false


function room_changed(name)
    if name=="tutorial_room" then
        is_in_intro = true

        print_line_instant("As you lay peacefully on your front porch, soaking up the last warm sun rays of late summer, you hear one of goats on the range land. Everything seems so peaceful nothing bad could ever happen.")
        print_line_instant("'Hey Kid! Wake up.' A rough voice wakes you up.")
        print_line_instant("You are getting rudely awake as the end of a large wooden staff hits your stomach. Stachled by the unfriendly behavior of your guest you jump up, willed to aks him what his problem is. But than you realized it's the old wizard of the village standing in front of you. ")
        print_line_instant("'I need you to do me a favor, kid.' he countinues.")
        print_line_instant("The wizard need you to do him a favor? That's highly unlikely. Why should he need you? You're just an oridnary farmer boy, living outside the village with no special talent. ")
        print_line_instant("Obviously you don't trust the old wizard, but luckly you can take a closer look at things.")
        print_line_instant("[i]Try typing: Inspect Wizard")
    else
        is_in_intro = false
    end
end