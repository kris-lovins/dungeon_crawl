cmake_minimum_required(VERSION 3.28)

add_library(Dungeon)

target_sources(Dungeon
    PRIVATE
        DungeonEngine.cpp
        GetCh.h

        entities/Enemy.cpp
        
        items/Item.cpp
        items/GearList.cpp
        items/WeaponList.cpp

        RoomApi.cpp
        rooms/SpikeTrapRoom.cpp

    PUBLIC FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_LIST_DIR}
        FILES 
            DungeonEngine.h

            entities/Entity.h
            entities/Enemy.h
            entities/MonsterStructs.h

            items/Item.h
            items/ItemStructs.h
            items/GearList.h
            items/WeaponList.h

            RoomApi.h
            rooms/IRoom.h
            rooms/SpikeTrapRoom.h
)
