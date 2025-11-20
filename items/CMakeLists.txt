cmake_minimum_required(VERSION 3.28)

add_library(Item)

target_sources(Item
    PUBLIC FILE_SET HEADERS
    BASE_DIRS .
    FILES Item.h
)

target_link_libraries(Item
    PUBLIC Dungeon
)

