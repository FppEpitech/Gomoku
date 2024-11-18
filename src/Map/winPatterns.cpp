/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"
#include "Algorithms/Algorithm.hpp"

std::optional<std::pair<int, int>>  Map::_checkForWinPattern(CellValue player)
{
    Algorithm algo(_size, _map);
    for (int x = 0; x < (int)_size; ++x)
        for (int y = 0; y < (int)_size; ++y)
            if (_map[x][y].getValue() == CellValue::NONE)
                if (algo.playWinPattern(x, y, player))
                    return std::make_pair(x, y);
    return std::nullopt;
}
