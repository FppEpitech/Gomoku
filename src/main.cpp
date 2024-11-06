/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** main
*/

#include "Parser/Parser.hpp"

int main() {
    Map map;
    GameRules gameRule;
    Parser parser;

    while (true) {
        std::string command;
        std::getline(std::cin, command);

        if (!parser.parseCommand(command, map, gameRule))
            std::cerr << "Invalid command." << std::endl;
    }
    return 0;
}