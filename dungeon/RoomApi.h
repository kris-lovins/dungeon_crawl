#pragma once

#include <memory>
#include <vector>
#include "entities/MonsterStructs.h"

enum EnemyType
{
    Goblin
};

struct Enemy
{
    EnemyType type;
    int x;
    int y;
    int hp;
    int atk;
    int def;
    char glyph;
};

class RoomApi
{
    public:
        RoomApi();
        
        void showMessage(std::string const & message);
        std::vector<std::string> getMessages();

        void spawnEnemy(int x, int y, EnemyType enemyType);
        std::vector<Enemy> getEnemyList();

    private:
        std::vector<std::string> messages;
        std::vector<Enemy> enemyList;
};

