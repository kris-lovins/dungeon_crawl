#pragma once
#include <string>
#include <vector>

struct Item
{
    Item(int ivalue, char iglyph, std::string idesc);
    int value;
    char glyph;
    std::string desc;
};
Item::Item(int ivalue, char iglyph, std::string idesc)
{
    value = ivalue;
    glyph = iglyph;
    desc = idesc;
}

struct Gold : Item
{
    Gold() : Item(1, 'G', "Gold worth 1G.") {}
};

struct Ruby : Item
{
    Ruby() : Item(5, 'R', "Ruby worth 5G.") {}
};

struct Diamond : Item
{
    Diamond() : Item(50, 'D', "Diamond worth 50G.") {}
};

struct Potion : Item
{
    Potion() : Item(5, '+', "Potion: Heals 15.") {}
    int hp = 15;
};

struct Hi_Potion : Item
{
    Hi_Potion() : Item(15, '+', "Hi-Potion: Heals 50") {}
    int hp = 50;
};

enum class BuffType {
    DEFENSE_BUFF,
    HEALTH_BUFF,
    ATTACK_BUFF
};

enum class GearType {
    BRACELET,
    EARRING,
    RING
};

struct Gear : Item
{
    Gear(int ibuff, BuffType ibuffType, GearType igearType, std::string desc) :
        Item(2, '?', desc),
        buffValue(ibuff),
        buffType(ibuffType),
        gearType(igearType) {}
    int buffValue;
    BuffType buffType;
    GearType gearType;
    std::string description;
};

// List of all gears
struct GearList
{
    GearList();
    std::vector<Gear> gearList;
};
GearList::GearList()
{
    Gear green_bracelet(5, BuffType::HEALTH_BUFF, GearType::BRACELET, "Green Bracelet: Adds 5 Health to max HP.");
    gearList.push_back(green_bracelet);
    Gear red_bracelet(5, BuffType::ATTACK_BUFF, GearType::BRACELET, "Red Bracelet: Adds 5 to Attack Power.");
    gearList.push_back(red_bracelet);
    Gear blue_bracelet(5, BuffType::DEFENSE_BUFF, GearType::BRACELET, "Blue Bracelet: Adds 5 to Defense.");
    gearList.push_back(blue_bracelet);

    Gear green_ring(5, BuffType::HEALTH_BUFF, GearType::RING, "Green Ring: Adds 5 Health to max HP.");
    gearList.push_back(green_ring);
    Gear red_ring(5, BuffType::ATTACK_BUFF, GearType::RING, "Red Ring: Adds 5 to Attack Power.");
    gearList.push_back(red_ring);
    Gear blue_ring(5, BuffType::DEFENSE_BUFF, GearType::RING, "Blue Ring: Adds 5 to Defense.");
    gearList.push_back(blue_ring);

    Gear green_earring(5, BuffType::HEALTH_BUFF, GearType::EARRING, "Green Earring: Adds 5 Health to max HP.");
    gearList.push_back(green_earring);
    Gear red_earring(5, BuffType::ATTACK_BUFF, GearType::EARRING, "Red Earring: Adds 5 to Attack Power.");
    gearList.push_back(red_earring);
    Gear blue_earring(5, BuffType::DEFENSE_BUFF, GearType::EARRING, "Blue Earring: Adds 5 to Defense.");
    gearList.push_back(blue_earring);
}

struct Weapon : Item
{
    Weapon(int iattackPower, std::string desc) : Item(0, 'W', desc), attackPower(iattackPower) {}
    int attackPower;
};

// List of all weapons
struct WeaponList
{
    WeaponList();
    std::vector<Weapon> weaponList;
};
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
