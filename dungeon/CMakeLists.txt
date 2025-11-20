cmake_minimum_required(VERSION 3.28)

add_library(Dungeon)

target_sources(Dungeon
    PRIVATE
        DungeonEngine.cpp
        GetCh.h

        RoomApi.cpp
        rooms/SpikeTrapRoom.cpp

    PUBLIC FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_LIST_DIR}
        FILES 
            DungeonEngine.h

            entities/Entity.h

            items/Item.h

            RoomApi.h
            rooms/IRoom.h
            rooms/SpikeTrapRoom.h
)


