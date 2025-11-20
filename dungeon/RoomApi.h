#pragma once

#include <memory>
#include <vector>

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

struct Item
{
    std::string name;
};

struct Player
{
    char symbol;
    int hp;
    int attack;
    int defense;
    int level;
    int x;
    int y;
    std::vector<Item> equiped;
    std::vector<Item> inventory;
};

class RoomApi
{
    public:
        RoomApi();
        
        void showMessage(std::string const & message);
        std::vector<std::string> getMessages();

        void spawnEnemy(int x, int y, EnemyType enemyType);
        void setPlayer(Player newPlayer);
        std::vector<Enemy> getEnemyList();
        Player getPlayer();

    private:
        std::vector<std::string> messages;
        std::vector<Enemy> enemyList;
        Player player;
};

