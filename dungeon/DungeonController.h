#pragma once

#include "entities/Entity.h"

#include <memory>
#include <variant>
#include <vector>

class Item;
class Player;
class Room;

struct position
{
    int x;
    int y;
};

using EnemyOrItems = std::variant<std::weak_ptr<Entity>, std::vector<Item>>;
class DungeonController
{
public:
    EnemyOrItems getLocationContents(position p);

private:
    std::shared_ptr<Player> player;
    std::vector<Room> rooms;
};