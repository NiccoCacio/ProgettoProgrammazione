cmake_minimum_required(VERSION 3.7)
project(ProjectProgrammazione)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GameCharacter.cpp GameCharacter.h Buff.cpp Buff.h Hero.cpp Hero.h SlotMachine.cpp SlotMachine.h BlackSmith.cpp BlackSmith.h Loot.cpp Loot.h Villain.cpp Villain.h Fighting.cpp Fighting.h)
add_executable(ProjectProgrammazione ${SOURCE_FILES})