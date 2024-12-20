/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** evaluation
*/

#include "Algorithms/Algorithm.hpp"
#include "Map/Map.hpp"

std::tuple<int, int, CellValue> Algorithm::_countInDirectionEvaluation(int x, int y, CellValue player, int dx, int dy)
{
    int first = 0;
    int second = 0;
    bool isBlank = false;
    CellValue end = CellValue::WALL;
    int i = 0;

    for (; i < 4; i++) {
        x += dx;
        y += dy;
        if (x >= 0 && x < (int)_size && y >= 0 && y < (int)_size) {
            if (_map[x][y].getValue() == player) {
                if (!isBlank)
                    ++first;
                else
                    ++second;
            } else if (_map[x][y].getValue() == CellValue::NONE && !isBlank) {
                end = CellValue::NONE;
                isBlank = true;
                continue;
            }else {
                end = _map[x][y].getValue();
                break;
            }
        } else {
            if (!(isBlank && second == 0))
                end = CellValue::WALL;
            break;
        }
    }
    if (i == 4) {
        x += dx;
        y += dy;
        if (x >= 0 && x < (int)_size && y >= 0 && y < (int)_size) {
            end = _map[x][y].getValue();
        } else
            end = CellValue::WALL;
    }

    return {first, second, end};
}

std::size_t Algorithm::computeMaxLineScore(int length, CellValue left, CellValue right)
{
    if (length > 5)
        length = 5;
    length *= SCORE_PERCENTAGE;
    if (left == CellValue::NONE && right == CellValue::NONE)
        length *= 2;
    else if (left != CellValue::NONE && right != CellValue::NONE)
        length = 0;
    return length;
}

std::size_t Algorithm::evaluateLine(int x, int y, CellValue player, int vx, int vy)
{
    std::tuple<int, int, CellValue> left, right;
    left = _countInDirectionEvaluation(x, y, player, vx, vy);
    right = _countInDirectionEvaluation(x, y, player, -vx, -vy);

    int l, m, r = 0;
    m = std::get<0>(left) + std::get<0>(right);
    l = std::get<1>(left) + std::get<0>(left) + std::get<0>(right);
    r = std::get<0>(left) + std::get<0>(right) + std::get<1>(right);

    CellValue endLeft = std::get<2>(left);
    CellValue endRight = std::get<2>(right);

    int countM = 0;
    if (std::get<1>(left) == 0 && std::get<1>(right) == 0)
        countM = computeMaxLineScore(m, endLeft, endRight);
    else if (std::get<1>(left) != 0 && std::get<1>(right) == 0)
        countM = computeMaxLineScore(m, CellValue::NONE, endRight);
    else if (std::get<1>(left) == 0 && std::get<1>(right) != 0)
        countM = computeMaxLineScore(m, endLeft, CellValue::NONE);
    else
        countM = computeMaxLineScore(m, CellValue::NONE, CellValue::NONE);


    int countL = 0;
    if (std::get<1>(right) != 0)
        countL = computeMaxLineScore(l, endLeft, CellValue::NONE);
    else
        countL = computeMaxLineScore(l, endLeft, endRight);


    int countR = 0;
    if (std::get<1>(left) != 0)
        countR = computeMaxLineScore(r, CellValue::NONE, endRight);
    else
        countR = computeMaxLineScore(r, endLeft, endRight);

    int count = std::max(countL, countR);
    count = std::max(count, countM);

    return count;
}

std::size_t Algorithm::_evalCreatePattern(int x, int y, CellValue player)
{
    if (player == CellValue::PLAYER1 && playWinPattern(x, y, player))
        return 2000;
    return 0;
}

int Algorithm::evaluation(int x, int y, CellValue player)
{
    std::size_t score = 0;
    score += _evalCreatePattern(x, y, player);
    score += evaluateLine(x, y, player, HORIZONTAL);
    score += evaluateLine(x, y, player, DIAGONAL_RIGHT);
    score += evaluateLine(x, y, player, DIAGONAL_LEFT);
    score += evaluateLine(x, y, player, VERTICAL);
    return score;
}

bool Algorithm::playWinPattern(int x, int y, CellValue player)
{
    std::size_t nbGoodPatterns = 0;

    if (_evaluatePattern(x, y, player, HORIZONTAL))
        nbGoodPatterns++;
    if (_evaluatePattern(x, y, player, DIAGONAL_RIGHT))
        nbGoodPatterns++;
    if (_evaluatePattern(x, y, player, DIAGONAL_LEFT))
        nbGoodPatterns++;
    if (_evaluatePattern(x, y, player, VERTICAL))
        nbGoodPatterns++;
    if (nbGoodPatterns >= 2)
        return true;
    return false;
}

bool Algorithm::_evaluatePattern(int x, int y, CellValue player, int vx, int vy)
{
    std::tuple<int, int, CellValue> left, right;
    left = _countInDirectionWithBlocks(x, y, player, vx, vy);
    right = _countInDirectionWithBlocks(x, y, player, -vx, -vy);

    if (std::get<0>(left) + std::get<0>(right) >= 3 && (std::get<2>(left) == CellValue::NONE || std::get<2>(right) == CellValue::NONE))
        return true;
    return false;
}

std::tuple<int, int, CellValue> Algorithm::_countInDirectionWithBlocks(int x, int y, CellValue player, int dx, int dy)
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
            end = CellValue::NONE;
            break;
        }
    }
    return {first, second, end};
}
