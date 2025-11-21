#ifndef EnemyTests_H
#define EnemyTests_H

#include <gtest/gtest.h>
#include "entities/Enemy.h"

TEST(EnemyTest, Creation) {
    Enemy testEnemy;
    testEnemy.setHealth(100);
    testEnemy.setDefense(5);
    testEnemy.takeDamage(30);
    EXPECT_EQ(testEnemy.getHealth(), 75);
}

#endif
