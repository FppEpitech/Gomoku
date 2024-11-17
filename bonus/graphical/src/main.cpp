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
    // map.setSize(20);
    map.createMap(20);
    // GameRules gameRule;
    // Parser parser;

    GraphicLib graphicLib;

    while (graphicLib.isWindowOpen()) {
        graphicLib.clear();
        graphicLib.startDraw();

        map.displayMapGraphic(&graphicLib);
        if (graphicLib.isMouseButtonReleased(MOUSE_BUTTON_LEFT))
            map.clickOnMap(&graphicLib);
        graphicLib.endDraw();
        // std::string command;
        // std::getline(std::cin, command);


        // if (!parser.parseCommand(command, map, gameRule))
        //     std::cerr << "Invalid command." << std::endl;
    }
    return 0;
}
