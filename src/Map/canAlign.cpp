/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

std::optional<std::pair<int, int>> Map::_canAlignNbPawns(CellValue player, int nbPawns, int x, int y)
{
    if (_map[x][y].getValue() == CellValue::NONE)
        if (_checkWin(x, y, player, nbPawns))
            return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_checkWin(int x, int y, CellValue player, int nbPawns)
{
    _map[x][y].setValue(player);
    bool win = (_checkDirection(x, y, player, HORIZONTAL, nbPawns) ||
                _checkDirection(x, y, player, VERTICAL, nbPawns) ||
                _checkDirection(x, y, player, DIAGONAL_RIGHT, nbPawns) ||
                _checkDirection(x, y, player, DIAGONAL_LEFT, nbPawns));
    _map[x][y].setValue(CellValue::NONE);
    return win;
}

bool Map::_checkDirection(int x, int y, CellValue player, int dx, int dy, int nbPawns)
{
    int count = 1;

    count += _countInDirection(x, y, player, dx, dy);
    count += _countInDirection(x, y, player, -dx, -dy);
    return count >= nbPawns;
}

int Map::_countInDirection(int x, int y, CellValue player, int dx, int dy)
{
    int count = 0;

    while (true) {
        x += dx;
        y += dy;
        if (x >= 0 && x < (int)_size && y >= 0 && y < (int)_size) {
            if (_map[x][y].getValue() == player)
                ++count;
            else
                break;
        } else {
            break;
        }
    }
    return count;
}
