//
// Created by felix on 06.01.20.
//

#ifndef SLAYINGDEMONS_EVENTARGS_H
#define SLAYINGDEMONS_EVENTARGS_H


namespace sd {
    class EventArgs {
    public:
        enum class Type {
            None = 0,
            TextOutputCreated,
            NewWordCollected,
            PlayerVocabChanged,
            LineToOutput,
            WalkedThroughDoor,
            RoomLayoutChanged,
            StartFightWithGoblin,
            GoblinDefeated,
            PlayerStateCreated,
            FightStarted
        };

        EventArgs();
        virtual ~EventArgs() = default;

        Type type;
    };
}


#endif //SLAYINGDEMONS_EVENTARGS_H
