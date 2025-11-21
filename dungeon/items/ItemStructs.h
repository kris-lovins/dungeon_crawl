#pragma once
#include "Item.h"
#include <string>

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
};

struct Weapon : Item
{
    Weapon(int iattackPower, std::string desc) : Item(0, 'W', desc), attackPower(iattackPower) {}
    int attackPower;
};