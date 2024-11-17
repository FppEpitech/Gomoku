/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

std::optional<std::pair<int, int>>  Map::_checkForWinPattern(CellValue player)
{
    for (int x = 0; x < (int)_size; ++x)
        for (int y = 0; y < (int)_size; ++y)
            if (_map[x][y].getValue() == CellValue::NONE)
                if (_playWinPattern(x, y, player))
                    return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_playWinPattern(int x, int y, CellValue player)
{
    std::size_t nbGoodPatterns = 0;

    if (evaluatePattern(x, y, player, HORIZONTAL))
        nbGoodPatterns++;
    if (evaluatePattern(x, y, player, DIAGONAL_RIGHT))
        nbGoodPatterns++;
    if (evaluatePattern(x, y, player, DIAGONAL_LEFT))
        nbGoodPatterns++;
    if (evaluatePattern(x, y, player, VERTICAL))
        nbGoodPatterns++;
    if (nbGoodPatterns >= 2)
        return true;
    return false;
}

bool Map::evaluatePattern(int x, int y, CellValue player, int vx, int vy)
{
    std::tuple<int, int, CellValue> left, right;
    left = _countInDirectionWithBlocks(x, y, player, vx, vy);
    right = _countInDirectionWithBlocks(x, y, player, -vx, -vy);

    if (std::get<0>(left) + std::get<0>(right) >= 3 && (std::get<2>(left) == CellValue::NONE || std::get<2>(right) == CellValue::NONE))
        return true;
    return false;
}

std::tuple<int, int, CellValue> Map::_countInDirectionWithBlocks(int x, int y, CellValue player, int dx, int dy)
{
    int first = 0;
    int second = 0;
    bool isBlank = false;
    CellValue end = CellValue::NONE;

    for (int i = 0; i < 4; i++) {
        x += dx;
        y += dy;
        if (x >= 0 && x < (int)_size && y >= 0 && y < (int)_size) {
            if (_map[x][y].getValue() == player) {
                if (!isBlank)
                    ++first;
                else
                    ++second;
            }
            else if (_map[x][y].getValue() == CellValue::NONE && !isBlank) {
                isBlank = true;
                continue;
            }
            else {
                end = _map[x][y].getValue();
                break;
            }
        } else {
            if (player == CellValue::PLAYER1)
                end = CellValue::PLAYER2;
            else
                end = CellValue::PLAYER1;
            break;
        }
    }
    return {first, second, end};
}
