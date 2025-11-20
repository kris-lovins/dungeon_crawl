#include "rooms/IRoom.h"

class SpikeTrapRoom : public IRoom
{
    public:
        SpikeTrapRoom();

        std::string name() const;
        std::vector<std::string> getTileMap() const;
        void onEnter(RoomApi& api);

    private:
        std::vector<std::string> tileMap;
};

