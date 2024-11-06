/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Parser
*/

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>


#pragma once

#include "../Map/Map.hpp"
#include "../GameRules/GameRules.hpp"

class Parser {

    public:

        Parser(void) = default;

        /**
         * @brief Parse the command entered in input.
         *
         * @return true If command was find.
         * @return false If command wasn't find.
         */
        bool parseCommand(std::string command, Map& map, GameRules& rules);

    private:

        void _handleStart(std::size_t size, Map& map);
        void _handleTurn(std::size_t x, std::size_t y, Map& map);
        void _handleBegin(Map& map);
        void _handleBoard(Map& map);
        void _handleInfo(std::string key, std::size_t value, GameRules& map);
        void _handleEnd(void);
        void _handleAbout(void);
};
