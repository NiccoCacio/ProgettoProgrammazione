cmake_minimum_required(VERSION 3.7)
project(ProjectProgrammazione)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        BlackSmith.cpp BlackSmith.h
        Buff.cpp Buff.h
        Fighting.cpp Fighting.h
        GameCharacter.cpp GameCharacter.h
        Hero.cpp Hero.h
        Reward.cpp Reward.h
        main.cpp
        PowerUp.cpp PowerUp.h
        SlotMachine.cpp SlotMachine.h
        Villain.cpp Villain.h
        Game.cpp Game.h
        GameState.cpp GameState.h
        Animator.cpp Animator.h)

add_executable(ProjectProgrammazione ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ProjectProgrammazione ${SFML_LIBRARIES})
endif()