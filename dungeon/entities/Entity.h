#include "Item.h"
#include <vector>

struct position {
    int x;
    int y;
};

class Entity {
    virtual int makeAttack() = 0;
    virtual void takeDamage(int damage) = 0;

    int getHealth() {return health;}
    void setHealth(int newHealth) {health = newHealth;}
    char getEntitySymbol() {return entitySymbol;}
    void setEntitySymbol(char newSymbol) {entitySymbol = newSymbol;}
    
    private:
        int health;
        char entitySymbol;
        position entityPosition;
        std::vector<Item> inventory;
};