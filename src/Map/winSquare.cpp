/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

std::optional<std::pair<int, int>> Map::_canAlignSquare(CellValue player)
{
    for (int x = 0; x < (int)_size; ++x)
        for (int y = 0; y < (int)_size; ++y)
            if (_map[x][y].getValue() == CellValue::NONE)
                if (_checkSquare(x, y, player))
                    return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_checkSquare(int x, int y, CellValue player)
{
    if (x + 1 < _size && y + 1 < _size)
        if (_map[x + 1][y].getValue() == player && _map[x][y + 1].getValue() == player && _map[x + 1][y + 1].getValue() == player)
            return true;

    if (x - 1 >= 0 && y + 1 < _size)
        if (_map[x - 1][y].getValue() == player && _map[x][y + 1].getValue() == player && _map[x - 1][y + 1].getValue() == player)
            return true;

    if (x + 1 < _size && y - 1 >= 0)
        if (_map[x + 1][y].getValue() == player && _map[x][y - 1].getValue() == player && _map[x + 1][y - 1].getValue() == player)
            return true;

    if (x - 1 >= 0 && y - 1 >= 0)
        if (_map[x - 1][y].getValue() == player && _map[x][y - 1].getValue() == player && _map[x - 1][y - 1].getValue() == player)
            return true;

    return false;
}
