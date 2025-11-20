cmake_minimum_required(VERSION 3.28)

project(DungeonCrawl)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/1b96fa13f549387b7549cc89e1a785cf143a1a50.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_subdirectory(dungeon)
add_subdirectory(tests)

################################################################

add_executable(
    DungeonCrawl
        main.cpp
)

target_link_libraries(
    DungeonCrawl
        PRIVATE
            Dungeon
)

install(
    TARGETS
        DungeonCrawl
)
