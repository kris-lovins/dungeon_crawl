#include <memory>
#include "DungeonEngine.h"
#include "rooms/SpikeTrapRoom.h"

int main(int argc, char** argv)
{
    DungeonEngine engine;

    // Add rooms.
    engine.addRoom(std::make_unique<SpikeTrapRoom>());

    // Start the game.
    engine.start();

    return 0;
}

