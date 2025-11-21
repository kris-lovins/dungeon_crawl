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

    player.symbol = 'P';
    player.hp = 100;
    player.attack = 10;
    player.defense = 10;
    player.level = 1;
    player.x = 3;
    player.y = 3;
    Item sword = Item("sword");
    player.equiped.push_back(sword);
    Item potion = Item("potion");
    player.inventory.push_back(potion);
    Item ruby = Item("ruby");
    player.inventory.push_back(ruby);

    roomApi.setPlayer(player);

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
        if(inputBuffer == 'w')
        {
            player.y -= 1;
            roomApi.showMessage("Moved Up");
        }
        else if(inputBuffer == 'a')
        {
            player.x -= 1;
            roomApi.showMessage("Moved Left");
        }
        else if (inputBuffer == 's')
        {
            player.y += 1;
            roomApi.showMessage("Moved Down");
        }
        else if (inputBuffer == 'd')
        {
            player.x += 1;
            roomApi.showMessage("Moved Right");
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
    auto player = roomApi.getPlayer();

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

            if (player.x == x && player.y == y)
            {
                tileMap[y][x] = player.symbol;
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

    // stats
    std::cout << "HP: " << player.hp << std::endl;
    std::cout << "ATK: " << player.attack << std::endl;
    std::cout << "DEF: " << player.defense << std::endl;
    std::cout << "LVL: " << player.level << std::endl;

    // equiped
    std::cout << "EQU: ";
    for (auto itr = player.equiped.begin(); itr != player.equiped.end(); ++itr)
    {
        std::cout << (*itr).name << ", ";
    }
    std::cout << std::endl;

    // inventory
    std::cout << "INV: ";
    for (auto itr = player.inventory.begin(); itr != player.inventory.end(); ++itr)
    {
        std::cout << (*itr).name << ", ";
    }
    std::cout << std::endl;

    std::cout << "--------------------------------" << std::endl;

    std::cout << std::endl;

    //
    // Render action menu.
    //

    std::cout << "movement: [w][a][s][d] | quit: [q] " << std::endl;
}

//bool DungeonEngine::isCombat()
//{
//    bool retval = false;
//    auto player = roomApi.getPlayer();
//    auto enemyList = roomApi.getEnemyList();
//    for (auto enemy : enemyList)
//    {
//        if (enemy.x == player.x && enemy.y == player.y)
//        {
//            enemy.hp -= player.attack - enemy.def;
//            // update enemy? use itrs?
//            player.hp -= enemy.atk - player.defense;
//            roomApi.setPlayer(player);
//        }
//    }
//    return retval;
//}

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
        
        roomApi.setPlayer(player);

        render();
    }
}

