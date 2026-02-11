#pragma once

#include <string>
#include <vector>
#include "RoomApi.h"

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

void RoomApi::spawnEnemy(int x, int y, EnemyType enemyType)
{
    if (enemyType == EnemyType::Goblin)
    {
        Enemy e;
        e.x = x;
        e.y = y;
        e.atk = 2;
        e.def = 0;
        e.hp = 10;
        e.type = enemyType;
        e.glyph = 'g';

        enemyList.push_back(e);
    }
}

void RoomApi::setPlayer(Player newPlayer)
{
    player = newPlayer;
}

std::vector<Enemy> RoomApi::getEnemyList()
{
    return enemyList;
}

Player RoomApi::getPlayer()
{
    return player;
}