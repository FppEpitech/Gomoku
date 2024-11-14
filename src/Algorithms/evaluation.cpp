/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** evaluation
*/

#include "Algorithms/Algorithm.hpp"
#include "Map/Map.hpp"

std::pair<int, int> Algorithm::_countInDirectionEvaluation(int x, int y, CellValue player, int dx, int dy)
{
    int first = 0;
    int second = 0;
    bool isBlank = false;

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
            else
                break;
        } else {
            break;
        }
    }
    return {first, second};
}

std::size_t Algorithm::evaluateLine(int x, int y, CellValue player, int vx, int vy, std::size_t scoreMax)
{
    std::pair<int, int> left, right;
    left = _countInDirectionEvaluation(x, y, player, vx, vy);
    right = _countInDirectionEvaluation(x, y, player, -vx, -vy);

    int l, m, r = 0;
    m = left.first + right.first;
    l = left.second + left.first + right.first;
    r = left.first + right.first + right.second;

    int count = std::max(m, l);
    count = std::max(count, r);
    count++;

    if (count > 5)
        count = 5;
    count *= SCORE_PERCENTAGE;
    if (count > (int)scoreMax)
        scoreMax = count;

    return scoreMax;
}

int Algorithm::evaluation(int x, int y, CellValue player)
{
    std::size_t score = 0;
    score = evaluateLine(x, y, player, HORIZONTAL, score);
    score = evaluateLine(x, y, player, DIAGONAL_RIGHT, score);
    score = evaluateLine(x, y, player, DIAGONAL_LEFT, score);
    score = evaluateLine(x, y, player, VERTICAL, score);
    return score;
}
