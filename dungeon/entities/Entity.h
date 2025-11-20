// Entity.h
#ifndef ENTITY_H
#define ENTITY_H

#include "items/Item.h"
#include <vector>
#include <string>

struct position {
    int x;
    int y;
};

class Entity {
public:
    virtual int makeAttack() = 0;
    virtual void takeDamage(int damage) = 0;
    virtual Item dropItem() = 0;
    virtual std::vector<Item>& dropItems() = 0;
    virtual void pickupItem() = 0;
     
    
    int getHealth() {return health;}
    void setHealth(int newHealth) {health = newHealth;}
    char getEntitySymbol() {return entitySymbol;}
    void setEntitySymbol(char newSymbol) {entitySymbol = newSymbol;}
    position getEntityPosition() {return entityPosition;}
    void setEntityPosition(position newPosition) {entityPosition = newPosition;}
    std::vector<Item>& getInventory() {return inventory;}
    void setInventory(std::vector<Item>& newInventory) {inventory = newInventory;}
    
private:
    int health;
    char entitySymbol;
    position entityPosition;
    std::vector<Item> inventory;
};

#endif