#include "items/GearList.h"

GearList::GearList()
{
    Gear green_bracelet(5, BuffType::HEALTH_BUFF, GearType::BRACELET, "Green Bracelet: Adds 5 to max health.");
    gearList.push_back(green_bracelet);
    Gear red_bracelet(5, BuffType::ATTACK_BUFF, GearType::BRACELET, "Red Bracelet: Adds 5 to base attack.");
    gearList.push_back(red_bracelet);
    Gear blue_bracelet(5, BuffType::DEFENSE_BUFF, GearType::BRACELET, "Blue Bracelet: Adds 5 to defense.");
    gearList.push_back(red_bracelet);

    Gear green_ring(5, BuffType::HEALTH_BUFF, GearType::RING, "Green Ring: Adds 5 to max health.");
    gearList.push_back(green_ring);
    Gear red_ring(5, BuffType::ATTACK_BUFF, GearType::RING, "Red Ring: Adds 5 to base attack.");
    gearList.push_back(red_ring);
    Gear blue_ring(5, BuffType::DEFENSE_BUFF, GearType::RING, "Blue Ring: Adds 5 to defense.");
    gearList.push_back(blue_ring);

    Gear green_earring(5, BuffType::HEALTH_BUFF, GearType::EARRING, "Green Earring: Adds 5 to max health.");
    gearList.push_back(green_ring);
    Gear red_earring(5, BuffType::ATTACK_BUFF, GearType::EARRING, "Red Earring: Adds 5 to base attack.");
    gearList.push_back(red_ring);
    Gear blue_earring(5, BuffType::DEFENSE_BUFF, GearType::EARRING, "Blue Earring: Adds 5 to defense.");
    gearList.push_back(blue_ring);
}