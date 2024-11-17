/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

// #include "Parser/Parser.hpp"
#include <iostream>

#include "GraphicLib/GraphicLib.hpp"
#include "Map/Map.hpp"

int main() {
    Map map;
    map.setSize(20);
    // GameRules gameRule;
    // Parser parser;

    GraphicLib graphicLib;

    while (graphicLib.isWindowOpen()) {
        graphicLib.clear();
        graphicLib.startDraw();

        // std::string command;
        // std::getline(std::cin, command);

        graphicLib.endDraw();

        // if (!parser.parseCommand(command, map, gameRule))
        //     std::cerr << "Invalid command." << std::endl;
    }
    return 0;
}
