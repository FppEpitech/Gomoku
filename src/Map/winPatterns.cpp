/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"
#include "Algorithms/Algorithm.hpp"

std::optional<std::pair<int, int>>  Map::_checkForWinPattern(CellValue player, int x, int y)
{
    // Algorithm algo(_size, _map);
    if (_map[x][y].getValue() == CellValue::NONE)
        if (_algo->playWinPattern(x, y, player))
            return std::make_pair(x, y);
    return std::nullopt;
}
