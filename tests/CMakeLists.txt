
include(GoogleTest)

add_executable(dungeon_tests)

target_sources(
    dungeon_tests 
    PRIVATE SpikeRoomTest.cpp
)

target_link_libraries(
    dungeon_tests
        PRIVATE
            gtest_main
            Dungeon
)

gtest_discover_tests(dungeon_tests)
