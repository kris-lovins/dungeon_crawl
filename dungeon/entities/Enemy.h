// Entity.h
#ifndef ENEMY_H
#define ENEMY_H

#include "entities/Entity.h"

class Enemy : public Entity {
public:
    int makeAttack() override;
    void takeDamage(int damage) override;
    Item dropItem() override;
    std::vector<Item>& dropItems() override;
    void pickupItem() override;

    int getAttackPower() { return attackPower; }
    void setAttackPower(int newAttackPower) { attackPower = newAttackPower; }
    int getDefense() { return defense; }
    void setDefense(int newDefense) { defense = newDefense; }   

private:
        int attackPower;
        int defense;
};
#endif