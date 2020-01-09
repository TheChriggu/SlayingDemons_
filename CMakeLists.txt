cmake_minimum_required(VERSION 3.15)
project(SlayingDemons)

set(CMAKE_CXX_STANDARD 17)

# This CMake-File links all libraries for the current Host System.
# This means the Game can only be build for a Target-System on that Target-System
# it also sets the include directories for each library and sets the Project Target

# set executable-files (set Project-Target)
add_executable(${PROJECT_NAME}
               Src/Core/main.cpp
               Src/Core/Application.cpp
               Src/Core/Application.h
               Src/UI/Button.cpp
               Src/UI/Button.h
               Src/TextGlitch.cpp
               Src/TextGlitch.h
               Src/Core/DrawableObject.cpp
               Src/Core/DrawableObject.h
               Src/UI/TextOutput.cpp
               Src/UI/TextOutput.h
               Src/UI/FormattedLine.h
               Src/UI/FormattedLine.cpp
               Src/UI/FormattedWord.h
               Src/UI/FormattedWord.cpp
               Src/UI/InputField.h
               Src/UI/InputField.cpp
               Src/Core/Manageable.h
               Src/Core/Drawable.h
               Src/UI/Panel.cpp
               Src/UI/Panel.h
               Src/IO/UserInput.cpp
               Src/IO/UserInput.h
               Src/IO/FileInput.cpp
               Src/IO/FileInput.h
               Src/World.cpp
               Src/World.h
               Src/Fighter.cpp
               Src/Fighter.h
               Src/Player.cpp
               Src/Player.h
               Src/Vocabulary.cpp
               Src/Vocabulary.h
               Src/Word.cpp
               Src/Word.h
               Src/Combat/Action.cpp
               Src/Combat/Action.h
               Src/Combat/Modifier.cpp
               Src/Combat/Modifier.h
               Src/InputTextProcessor.cpp
               Src/InputTextProcessor.h
               Src/Combat/Fight.cpp
               Src/Combat/Fight.h
               Src/Combat/Attack.cpp
               Src/Combat/Attack.h
               Src/Monster.cpp
               Src/Monster.h
               Src/ScriptEngine/ScriptEngine.cpp
               Src/ScriptEngine/ScriptEngine.h
               Src/ScriptEngine/Script.h
               Src/ScriptEngine/Script.cpp
               Src/Dungeon/MultiTileObject.cpp
               Src/Dungeon/MultiTileObject.h
               Src/Dungeon/Room.cpp
               Src/Dungeon/Room.h
               Src/Dungeon/RoomObject.cpp
               Src/Dungeon/RoomObject.h
               Src/Dungeon/SingleTileObject.cpp
               Src/Dungeon/SingleTileObject.h
               Src/Dungeon/Tilemap.cpp
               Src/Dungeon/Tilemap.h
               Src/UI/MapWindow.cpp
               Src/UI/MapWindow.h
               Src/Dungeon/Floor.cpp
               Src/Dungeon/Floor.h
               Src/Dungeon/Door.cpp
               Src/Dungeon/Door.h
               Src/PlayerState.cpp
               Src/PlayerState.h
               Src/Dungeon/VocabExpansion.cpp
               Src/Dungeon/VocabExpansion.h
               Src/Dungeon/NavigationWord.cpp
               Src/Dungeon/NavigationWord.h
               Src/Event/Subscriber.h
               Src/Event/EventArgs.cpp
               Src/Event/EventArgs.h
               Src/Event/EventSystem.cpp
               Src/Event/EventSystem.h
               Src/Event/Subscriber.cpp
               Src/Event/TextOutputCreatedEventArgs.cpp
               Src/Event/TextOutputCreatedEventArgs.h
               Src/PlayerState.h
               Src/Combat/Stats.cpp
               Src/Combat/Stats.h
               Src/Combat/StatwiseOperation.cpp
               Src/Combat/StatwiseOperation.h
               Src/PlayerVocabulary.cpp
               Src/PlayerVocabulary.h
               Src/UI/PossibleWords.cpp
               Src/UI/PossibleWords.h
               Src/Core/GlobalDefinitions.h
               Src/Event/NewWordCollectedEventArgs.cpp
               Src/Event/NewWordCollectedEventArgs.h
               Src/Event/PlayerVocabChangedEventArgs.cpp
               Src/Event/PlayerVocabChangedEventArgs.h
               Src/Event/LineToOutputEventArgs.cpp
               Src/Event/LineToOutputEventArgs.h
               Src/Event/WalkedThroughDoorEventArgs.cpp
               Src/Event/WalkedThroughDoorEventArgs.h Src/Dungeon/Sofa.cpp Src/Dungeon/Sofa.h Src/Dungeon/Table.cpp Src/Dungeon/Table.h Src/Dungeon/Book.cpp Src/Dungeon/Book.h Src/Dungeon/Goblin.cpp Src/Dungeon/Goblin.h Src/Dungeon/LastRoom.cpp Src/Dungeon/LastRoom.h)

target_include_directories(${PROJECT_NAME} PRIVATE Src)

# add all libraries as subdirectories
add_subdirectory(lua-5.3.5)
add_subdirectory(SFML-2.5.1)
add_subdirectory(sol2-develop)
add_subdirectory(boost)

# find SFML packages in SFML_DIR which was set in SFML-2.5.1 subdirectory
find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

# link executable to SFML Libaries
target_link_libraries(${PROJECT_NAME}
                      sfml-system
                      sfml-window
                      sfml-graphics
                      sfml-network
                      sfml-audio
                      lua
                      Boost::filesystem
                      )
