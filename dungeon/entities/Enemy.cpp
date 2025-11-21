#include "entities/Enemy.h"

int Enemy::makeAttack() {
    return attackPower;
}

void Enemy::takeDamage(int damage) {
    int currentHealth = getHealth();
    setHealth(currentHealth - (damage-defense));
}


Item Enemy::dropItem() {
    std::vector<Item>& inventory = getInventory();
    if (inventory.empty()) {
        return Item(0, ' ', "No Item");
    }
    Item droppedItem = inventory.back();
    inventory.pop_back();
    return droppedItem;
}

std::vector<Item>& Enemy::dropItems() {
    return getInventory();
}

void Enemy::pickupItem() {
    // Enemies do not pick up items
}