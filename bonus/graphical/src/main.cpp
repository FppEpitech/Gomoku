/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

#include <mutex>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <sys/select.h>

#include "Map/Map.hpp"
#include "Parser/Parser.hpp"
#include "GraphicLib/GraphicLib.hpp"

std::string command = "";
bool run = true;
std::mutex _mutex;

bool isInputAvailable()
{
    fd_set readfds;
    struct timeval timeout;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;
    int result = select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &timeout);
    if (result == -1) {
        perror("select");
        return false;
    }
    return result > 0;
}

void readThread()
{
    std::string input;
    while (run) {
        if (isInputAvailable()) {
            std::getline(std::cin, input);
            if (input == "END")
                run = false;
            _mutex.lock();
            command = input;
            _mutex.unlock();
        }
    }
}

int main() {
    std::shared_ptr<Map> map = std::make_shared<Map>();
    GameRules gameRule;
    Parser parser;
    GraphicLib graphicLib;
    std::thread threadRead(readThread);

    while (graphicLib.isWindowOpen()) {
        graphicLib.clear();
        graphicLib.startDraw();
        map->displayMapGraphic(&graphicLib);
        if (map->_myTurn && graphicLib.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
            map->clickOnMap(&graphicLib);
        graphicLib.endDraw();
        graphicLib.clear();
        _mutex.lock();
        if (command != "" && !parser.parseCommand(command, map, gameRule))
            std::cerr << "Invalid command." << std::endl;
        command = "";
        _mutex.unlock();
    }
    _mutex.lock();
    run = false;
    _mutex.unlock();
    if (threadRead.joinable())
        threadRead.join();
    return 0;
}
