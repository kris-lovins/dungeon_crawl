#pragma once

#include "entities/Entity.h"

#include <memory>
#include <optional>
#include <variant>
#include <vector>

class Item;
class Player : public Entity{};
class Room;

struct position
{
    int x;
    int y;
};

struct PointInfo
{
    std::optional<std::shared_ptr<Entity>> entity;
    std::optional<std::vector<Item>> items;
    bool wall;
};

class DungeonController
{
public:
    void tryPlayerMove(position p);
    PointInfo getLocationContents(position p);

    void fight(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);

private:
    std::shared_ptr<Player> player;
    int currentRoom;
    std::vector<Room> rooms;
};