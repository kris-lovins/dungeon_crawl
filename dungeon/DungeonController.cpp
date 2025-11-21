#include "DungeonController.h"

void DungeonController::tryPlayerMove(position p)
{
    PointInfo contents = getLocationContents(p);
    if (!contents.wall) {
        if(contents.entity.has_value()) {
            fight(player, contents.entity.value());
            
        } else {
            //move player
            if (contents.items.has_value()){
                // pick up items
            }
        }
    } // if wall, do nothing
}

PointInfo DungeonController::getLocationContents(position p)
{
    return PointInfo{};
}

void DungeonController::fight(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2)
{
    e1->takeDamage(e2->makeAttack());
    e2->takeDamage(e1->makeAttack());
}
