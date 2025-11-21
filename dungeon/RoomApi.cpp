#pragma once

#include <string>
#include <vector>
#include "RoomApi.h"
#include "entities/MonsterStructs.h"

RoomApi::RoomApi()
{
}

void RoomApi::showMessage(std::string const & message)
{
    messages.push_back(message);
}

std::vector<std::string> RoomApi::getMessages()
{
    return messages;
}

void RoomApi::spawnEnemy(int x, int y, MonsterType monsterType)
{
    Enemy enemy;
    switch (monsterType)
    {
    case MonsterType::GOBLIN:
        enemy = Goblin();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::HOBGOBLIN:
        enemy = Hobgoblin();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::ORC:
        enemy = Orc();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::TROLL:
        enemy = Troll();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::DRAGON:
        enemy = Dragon();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::SKELETON:
        enemy = Skeleton();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::ZOMBIE:
        enemy = Zombie();
        enemy.setEntityPosition({x, y});
        break;
    case MonsterType::VAMPIRE:
        enemy = Vampire();
        enemy.setEntityPosition({x, y});
        break;
    default:
        break;
    }
    enemyList.push_back(enemy);
}

std::vector<Enemy> RoomApi::getEnemyList()
{
    return enemyList;
}
