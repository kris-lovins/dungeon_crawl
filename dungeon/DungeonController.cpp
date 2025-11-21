#include "DungeonController.h"

void DungeonController::tryMove(std::shared_ptr<Entity> e, position p)
{
    PointInfo contents = getLocationContents(p);
    if (!contents.wall) {
        if(contents.entity.has_value()) {
            int damage = e->makeAttack();
            contents.entity.value()->takeDamage(damage);
            
        } else {
            //move entity
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
