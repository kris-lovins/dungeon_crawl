
include(GoogleTest)

add_executable(dungeon_tests)

target_sources(
    dungeon_tests 
    PRIVATE
        DungeonController.test.cpp
        SpikeRoomTest.cpp
        EnemyTests.cpp
)

target_link_libraries(
    dungeon_tests
        PRIVATE
            gtest_main
            Dungeon
)

gtest_discover_tests(dungeon_tests)
