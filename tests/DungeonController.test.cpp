#include <DungeonController.h>
#include <entities/Entity.h>
#include <entities/Enemy.h>

#include <gtest/gtest.h>

#include <memory>

TEST(DungeonController, tryPlayerMove){
    DungeonController overlord;
    std::shared_ptr<Entity> e = std::make_shared<Enemy>();
    overlord.tryMove(e, {2,3});
}