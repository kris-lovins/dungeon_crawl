cmake_minimum_required(VERSION 3.28)

add_library(RoomApi)

target_sources(RoomApi
    PRIVATE RoomApi.cpp
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES RoomApi.h
)

################################################################

add_library(Dungeon)

target_sources(Dungeon
    PRIVATE
        DungeonController.cpp
      DungeonEngine.cpp
      GetCh.h
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES
        DungeonController.h
        DungeonEngine.h
        entities/Entity.h
)

target_link_libraries(
    Dungeon
        PUBLIC
            IRoom
)

