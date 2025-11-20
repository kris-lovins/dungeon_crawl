#include <iostream>

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <string>

class IRoom
{
    public:
        virtual ~IRoom() {}
        virtual std::string const name() const = 0;
//        virtual std::string const description() const = 0;
//        virtual std::vector<char> const & tileMap();
//        virtual void onEnter(Player& player, Dungeon& dungeon) = 0;
//        virtual void onPlayerStep(Player& player, Dungeon& dungeon) = 0;
//        virtual void onTick(Player& player, Dungeon& dungeon) = 0;
//        virtual bool isComplete() const = 0;        
};

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

class SpikeTrapRoom : public IRoom
{
    std::string const name() const
    {
        return "SpikeTrapRoom";
    }
};

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

#include <chrono>
#include <thread>

class DungeonEngine
{
    public:
        DungeonEngine()
        {
            // TODO
        }

        void addRoom(std::unique_ptr<IRoom> room)
        {
            rooms.push_back(std::move(room));
        }

        void start()
        {
            if(rooms.empty())
            {
                std::cout << "No rooms, no dungeon..." << std::endl;
            }

            // The starting room is always at index 0.
            enterRoom(0);

            running = true;
            std::thread t(&DungeonEngine::loop, this);
            t.join();           
        }

    private:
        void enterRoom(int roomIndex)
        {
            currentRoomIndex = roomIndex;
        }

        void loop()
        {
            auto last = std::chrono::steady_clock::now();

            while(running)
            {
                auto now = std::chrono::steady_clock::now();

                int delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - last).count();

                int ENGINE_FRAME_MILLISECONDS = 1000;
                int ENGINE_SLEEP_TIME_MILLISECONDS = 500;

                if(delta < ENGINE_FRAME_MILLISECONDS)
                {
                    std::cout << "Sleeping..." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(ENGINE_SLEEP_TIME_MILLISECONDS));
                    continue;
                }

                last = now;

                std::cout << rooms[currentRoomIndex]->name() << std::endl;
            }
        }

        bool running;
        int currentRoomIndex;
        std::vector<std::unique_ptr<IRoom>> rooms;
};

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
    DungeonEngine engine;

    // Add rooms.
    engine.addRoom(std::make_unique<SpikeTrapRoom>());

    // Start the game.
    engine.start();

    return 0;
}

