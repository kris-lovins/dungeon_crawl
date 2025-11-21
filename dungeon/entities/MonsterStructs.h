#include "entities/Enemy.h"

enum class MonsterType {
    GOBLIN,
    HOBGOBLIN,
    ORC,
    TROLL,
    DRAGON,
    SKELETON,
    ZOMBIE,
    VAMPIRE
};

struct Goblin : public Enemy {
    Goblin() {
        setHealth(30);
        setAttackPower(5);
        setDefense(0);
        setEntitySymbol('G');
    }
};

struct Hobgoblin : public Enemy {
    Hobgoblin() {
        setHealth(50);
        setAttackPower(8);
        setDefense(1);
        setEntitySymbol('H');
    }
};

struct Orc : public Enemy {
    Orc() {
        setHealth(80);
        setAttackPower(8);
        setDefense(4);
        setEntitySymbol('O');
    }
};

struct Troll : public Enemy {
    Troll() {
        setHealth(120);
        setAttackPower(12);
        setDefense(6);
        setEntitySymbol('T');
    }
};

struct Dragon : public Enemy {
    Dragon() {
        setHealth(300);
        setAttackPower(20);
        setDefense(10);
        setEntitySymbol('D');
    }
};

struct Skeleton : public Enemy {
    Skeleton() {
        setHealth(40);
        setAttackPower(6);
        setDefense(2);
        setEntitySymbol('S');
    }
};

struct Zombie : public Enemy {
    Zombie() {
        setHealth(60);
        setAttackPower(7);
        setDefense(3);
        setEntitySymbol('Z');
    }
};

struct Vampire : public Enemy {
    Vampire() {
        setHealth(100);
        setAttackPower(15);
        setDefense(5);
        setEntitySymbol('V');
    }
};