#include "items/WeaponList.h"

WeaponList::WeaponList()
{
    Weapon short_sword(3, "Short sword: Attck Power 3");
    weaponList.push_back(short_sword);

    Weapon long_sword(5, "Long sword: Attck Power 5");
    weaponList.push_back(long_sword);

    Weapon hammer(4, "Hammer: Attck Power 4");
    weaponList.push_back(hammer);

    Weapon spear(4, "Spear: Attck Power 4");
    weaponList.push_back(spear);
}