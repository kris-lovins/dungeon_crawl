#include "SpikeTrapRoom.h"

SpikeTrapRoom::SpikeTrapRoom()
{
    tileMap = {
        "################",
        "#..............#",
        "#..............#",
        "#..............#",
        "################"
    };
}

std::string SpikeTrapRoom::name() const
{
    return "SpikeTrapRoom";
}

std::vector<std::string> SpikeTrapRoom::getTileMap() const
{
    return tileMap;
}

void SpikeTrapRoom::onEnter(RoomApi& api)
{
    api.showMessage("A goblin appears!");
    api.spawnEnemy(2, 2, EnemyType::Goblin);
}
