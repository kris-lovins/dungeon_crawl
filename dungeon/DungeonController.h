#pragma once

#include "entities/Entity.h"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

class Item;
class Player : public Entity{};
class Room;

struct PointInfo
{
    std::optional<std::shared_ptr<Entity>> entity;
    std::optional<std::vector<Item>> items;
    bool wall;
};

class DungeonController
{
public:
    void tryMove(std::shared_ptr<Entity> e, position p);
    PointInfo getLocationContents(position p);

private:
    std::shared_ptr<Player> player;
    int currentRoom;
    std::vector<std::shared_ptr<Room>> rooms;
};