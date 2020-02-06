//
// Created by felix on 06.01.20.
//

#ifndef _EVENTARGS_H_
#define _EVENTARGS_H_


namespace sd {
    class EventArgs {
    public:
        enum class Type {
            NONE = 0,
            TEXT_OUTPUT_CREATED,
            NEW_WORD_COLLECTED,
            PLAYER_VOCAB_CHANGED,
            LINE_TO_OUTPUT,
            WALKED_THROUGH_DOOR,
            ROOM_LAYOUT_CHANGED,
            START_FIGHT_WITH_GOBLIN,
            GOBLIN_DEFEATED,
            PLAYER_STATE_CREATED,
            FIGHT_STARTED,
            FIGHT_ENDED,
            FONTS_CREATED,
            POSSIBLE_WORDS_CREATED
        };

        EventArgs();
        virtual ~EventArgs() = default;

        Type type;
    };
}


#endif //_EVENTARGS_H_
