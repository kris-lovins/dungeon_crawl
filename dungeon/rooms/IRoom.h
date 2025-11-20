#pragma once
#include <string>
#include <vector>
#include "RoomApi.h"

class IRoom
{
    public:
        virtual ~IRoom() {}
        virtual std::string name() const = 0;
        virtual std::vector<std::string> getTileMap() const = 0;
        virtual void onEnter(RoomApi& api) = 0;
//        virtual void onPlayerStep(Player& player, RoomApi& api) = 0;
//        virtual void onTick(Player& player, RoomApi& api) = 0;
//        virtual bool isComplete() const = 0;        
};

