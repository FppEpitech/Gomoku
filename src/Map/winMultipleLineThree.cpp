/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

std::optional<std::pair<int, int>> Map::_canAlignMultipleLineOfThree(CellValue player, int x, int y)
{
    if (_map[x][y].getValue() == CellValue::NONE)
        if (_checkWinMultipleLineOfThree(x, y, player))
            return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_checkWinMultipleLineOfThree(int x, int y, CellValue player)
{
    _map[x][y].setValue(player);
    bool winHorizontal = _checkDirectionMultipleLineOfThree(x, y, player, HORIZONTAL);
    bool winVertical = _checkDirectionMultipleLineOfThree(x, y, player, VERTICAL);
    bool winDiagonalRight = _checkDirectionMultipleLineOfThree(x, y, player, DIAGONAL_RIGHT);
    bool winDiagonalLeft = _checkDirectionMultipleLineOfThree(x, y, player, DIAGONAL_LEFT);
    _map[x][y].setValue(CellValue::NONE);

    if ((winHorizontal + winVertical + winDiagonalRight + winDiagonalLeft) >= 2)
        return true;
    else
        return false;
}

bool Map::_checkDirectionMultipleLineOfThree(int x, int y, CellValue player, int dx, int dy)
{
    int count = 1;

    int countPositiv = _countInDirection(x, y, player, dx, dy);
    int countNegativ = _countInDirection(x, y, player, -dx, -dy);

    if (countPositiv + countNegativ + count < 3)
        return false;


    int end1_x = x + (dx * countPositiv) + dx;
    int end1_y = y + (dy * countPositiv) + dy;

    int end2_x = x - (dx * countNegativ) - dx;
    int end2_y = y - (dy * countNegativ) - dy;

    bool end1_free = (end1_y >= 0 && end1_y < (int) _size && end1_x >= 0 && end1_x < (int) _size && _map[end1_x][end1_y].getValue() == CellValue::NONE);
    bool end2_free = (end2_y >= 0 && end2_y < (int) _size && end2_x >= 0 && end2_x < (int) _size && _map[end2_x][end2_y].getValue() == CellValue::NONE);

    return end1_free && end2_free;
}
