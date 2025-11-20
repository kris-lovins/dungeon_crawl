#include <iostream>
#include <chrono>
#include <utility>
#include <thread>

#include "DungeonEngine.h"
#include "rooms/IRoom.h"
#include "GetCh.h"

DungeonEngine::DungeonEngine() :
    running(false),
    quit(false),
    currentRoomIndex(0),
    hasInput(false),
    inputBuffer()
{}

void DungeonEngine::addRoom(std::unique_ptr<IRoom> room)
{
    rooms.push_back(std::move(room));
}

void DungeonEngine::start()
{
    if(rooms.empty())
    {
        std::cout << "No rooms, no dungeon..." << std::endl;
        return;
    }

    // The starting room is always at index 0.
    enterRoom(0);

    running = true;
    std::thread t1(&DungeonEngine::loop, this);
    std::thread t2(&DungeonEngine::getInput, this);

    t1.join();
    t2.join();
}

void DungeonEngine::enterRoom(int roomIndex)
{
    currentRoomIndex = roomIndex;
    rooms[currentRoomIndex]->onEnter(roomApi);
}

void DungeonEngine::getInput()
{
    while (!quit)
    {
        inputBuffer = getSingleChar();

        if (inputBuffer == 'q')
        {
            quit = true;
        }
        else
        {
            hasInput = true;
        }
    }
}

void DungeonEngine::handleInput()
{
    if(hasInput)
    {
        if(inputBuffer == 'm')
        {
            static int x = 1;
            roomApi.showMessage("Hello There! " + std::to_string(x));
            x++;
        }

        inputBuffer = 0;
        hasInput = false;
    }
}

void DungeonEngine::render()
{
    //
    // Clear the screen.
    //

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    
    std::cout << std::endl;

    //
    // Merge the tile maps.
    //

    auto tileMap = rooms[currentRoomIndex]->getTileMap();
    auto enemyList = roomApi.getEnemyList();

    for (int y = 0; y < tileMap.size(); y++)
    {
        for (int x = 0; x < tileMap[y].size(); x++)
        {
            for (auto enemy : enemyList)
            {
                if (enemy.x == x && enemy.y == y)
                {
                    tileMap[y][x] = enemy.glyph;
                }
            }
        }
    }

    //
    // Render the current room.
    //

    for(int y = 0; y < tileMap.size(); y++)
    {
        std::cout << tileMap[y] << std::endl;
    }

    std::cout << std::endl;

    //
    // Render text logs.
    //

    std::cout << "----------- Text Log -----------" << std::endl;

    std::vector<std::string> messages = roomApi.getMessages();

    for (int i = 4; i > 0; i--)
    {
        if(static_cast<int>(messages.size()) - i >= 0)
        {
            std::cout << messages[messages.size() - i] << std::endl;
        }
        else
        {
            std::cout << "" << std::endl;
        }
    }

    std::cout << "--------------------------------" << std::endl;

    //
    // Render player info.
    //

    std::cout << "----------- Player -------------" << std::endl;

    std::cout << "HP: " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "--------------------------------" << std::endl;

    std::cout << std::endl;

    //
    // Render action menu.
    //

    std::cout << "test msg: [m] | quit: [q] " << std::endl;
}

void DungeonEngine::loop()
{
    auto last = std::chrono::steady_clock::now();

    while(running)
    {
        auto now = std::chrono::steady_clock::now();

        int delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - last).count();

        int ENGINE_FRAME_MILLISECONDS = 1000;
        int ENGINE_SLEEP_TIME_MILLISECONDS = 100;

        if(delta < ENGINE_FRAME_MILLISECONDS)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(ENGINE_SLEEP_TIME_MILLISECONDS));
            continue;
        }

        last = now;

        handleInput();

        if (quit)
        {
            running = false;
            break;
        }
        
        render();
    }
}

