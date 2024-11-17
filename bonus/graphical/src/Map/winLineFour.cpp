/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

std::optional<std::pair<int, int>> Map::_canAlignFourPawns(CellValue player)
{
    for (int x = 0; x < (int)_size; ++x)
        for (int y = 0; y < (int)_size; ++y)
            if (_map[x][y].getValue() == CellValue::NONE)
                if (_checkWinLineFour(x, y, player))
                    return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_checkWinLineFour(int x, int y, CellValue player)
{
    _map[x][y].setValue(player);
    bool win = (_checkDirectionLineFour(x, y, player, HORIZONTAL) ||
                _checkDirectionLineFour(x, y, player, VERTICAL) ||
                _checkDirectionLineFour(x, y, player, DIAGONAL_RIGHT) ||
                _checkDirectionLineFour(x, y, player, DIAGONAL_LEFT));
    _map[x][y].setValue(CellValue::NONE);
    return win;
}

bool Map::_checkDirectionLineFour(int x, int y, CellValue player, int dx, int dy)
{
    int count = 1;

    int countPositiv = _countInDirection(x, y, player, dx, dy);
    int countNegativ = _countInDirection(x, y, player, -dx, -dy);

    if (countPositiv + countNegativ + count < 4)
        return false;


    int end1_x = x + (dx * countPositiv) + dx;
    int end1_y = y + (dy * countPositiv) + dy;

    int end2_x = x - (dx * countNegativ) - dx;
    int end2_y = y - (dy * countNegativ) - dy;

    bool end1_free = (end1_y >= 0 && end1_y < (int) _size && end1_x >= 0 && end1_x < (int) _size && _map[end1_y][end1_x].getValue() == CellValue::NONE);
    bool end2_free = (end2_y >= 0 && end2_y < (int) _size && end2_x >= 0 && end2_x < (int) _size && _map[end2_y][end2_x].getValue() == CellValue::NONE);

    return end1_free && end2_free;
}
