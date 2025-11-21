#include "DungeonController.h"

void DungeonController::tryPlayerMove(position p)
{
    PointInfo contents = getLocationContents(p);
    if (!contents.wall) {
        if(contents.entity.has_value()) {
            //fight
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
    rooms[currentRoom];
}