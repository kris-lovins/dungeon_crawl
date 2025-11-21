#include <DungeonController.h>
#include <entities/Entity.h>

#include <gtest/gtest.h>

#include <memory>

TEST(DungeonController, fight){
    DungeonController overlord;
    std::shared_ptr<Entity> e1;
    std::shared_ptr<Entity> e2;
    overlord.fight(e1, e2);
}