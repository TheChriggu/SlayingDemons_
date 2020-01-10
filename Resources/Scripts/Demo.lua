--
-- Created by IntelliJ IDEA.
-- User: felix
-- Date: 09.01.20
-- Time: 18:32
-- To change this template use File | Settings | File Templates.
--

encounter = false

function room_changed(is_last_room)
    if true then
        print_line("???: Nosiness and Stubbornness are disturbing human characteristics")
        print_line("???: And dangerous ones...")
        print_line("")

        set_glitch_on("output-panel")
        --set_glitch_on("map-window")
        --set_weakglitch_on("background_panel")

        print_line("Alert: power connection Malfunction!")
        print_line("System is running low on Energy!")
        print_line("")

        encounter = true;
    end
end

function input_received()
    if encounter then
        print_line("")
        print_line("???: Unexpected but pointless")

        set_demoglitch_on("")
        --print_line("")
    end
end

