/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"

Cell::Cell(void)
{
    _value = CellValue::NONE;
}

void Cell::setValue(CellValue value)
{
    _value = value;
}

CellValue Cell::getValue(void) const
{
    return _value;
}

Map::Map(void)
{
    _size = 0;
}

void Map::setSize(std::size_t size)
{
    _size = size;
}


std::size_t Map::getSize(void)
{
    return _size;
}

std::vector<std::vector<Cell>>& Map::getMap(void)
{
    return _map;
}

void Map::createMap(std::size_t size)
{
    _size = size;
    _map.resize(size, std::vector<Cell>(size));
}

void Map::displayMap(void)
{
    if (_size == 0)
        return;

    std::ofstream file("output.log", std::ios_base::app);

    for (std::size_t x = 0; x < _size; ++x)
        file << "===";
    file << std::endl;
    for (std::size_t x = 0; x < _size; ++x) {
        file << " ";
        for (std::size_t y = 0; y < _size; ++y)
            file << static_cast<char>(_map[x][y].getValue()) << "  ";
        file << std::endl;
    }
    for (std::size_t x = 0; x < _size; ++x)
        file << "===";
    file << std::endl;
    file.close();
}

void Map::play(void)
{
    auto winningMove = _canAlignNbPawns(CellValue::PLAYER1, PAWNS_TO_WIN);
    auto avoidLoose = _canAlignNbPawns(CellValue::PLAYER2, PAWNS_TO_WIN);
    auto winningPattern = _checkForWinPattern(CellValue::PLAYER1);
    auto avoidLineFour = _canAlignNbPawns(CellValue::PLAYER2, PAWNS_FOUR);
    std::ofstream file("output.log", std::ios_base::app);

    if (winningMove) {
        if (file.is_open())
                file << "Winning move : " << winningMove->first << "," << winningMove->second << std::endl;
        std::cout << winningMove->first << "," << winningMove->second << std::endl;
        _map[winningMove->first][winningMove->second].setValue(CellValue::PLAYER1);
    } else if (avoidLoose) {
        if (file.is_open())
                file << "Avoid loosing move : " << avoidLoose->first << "," << avoidLoose->second << std::endl;
        std::cout << avoidLoose->first << "," << avoidLoose->second << std::endl;
        _map[avoidLoose->first][avoidLoose->second].setValue(CellValue::PLAYER1);
    } else if (winningPattern) {
        if (file.is_open())
                file << "Wining patern move : " << winningPattern->first << "," << winningPattern->second << std::endl;
        std::cout << winningPattern->first << "," << winningPattern->second << std::endl;
        _map[winningPattern->first][winningPattern->second].setValue(CellValue::PLAYER1);
    } else if (avoidLineFour) {
        if (file.is_open())
                file << "Avoid Line of Four loosing move : " << avoidLineFour->first << "," << avoidLineFour->second << std::endl;
        std::cout << avoidLineFour->first << "," << avoidLineFour->second << std::endl;
        _map[avoidLineFour->first][avoidLineFour->second].setValue(CellValue::PLAYER1);
    } else {
        std::vector<std::pair<int, int>> empty_cells;
        for (int x = 0; x < (int)_size; ++x) {
            for (int y = 0; y < (int)_size; ++y) {
                if (_map[x][y].getValue() == CellValue::NONE)
                    empty_cells.emplace_back(x, y);
            }
        }

        if (!empty_cells.empty()) {
            std::pair<int, int> move = computeTree();
            _map[move.first][move.second].setValue(CellValue::PLAYER1);
            std::cout << move.first << "," << move.second << std::endl;
            if (file.is_open())
                file << "We've played on : " << move.first << "," << move.second << std::endl;
            displayMap();
        }
    }
    file.close();
}

std::pair<int, int> Map::_countInDirectionEvaluation(int x, int y, CellValue player, int dx, int dy)
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

std::size_t Map::evaluateLine(int x, int y, CellValue player, int vx, int vy, std::size_t scoreMax)
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

int Map::evaluation(int x, int y, CellValue player)
{
    std::size_t score = 0;
    score = evaluateLine(x, y, player, HORIZONTAL, score);
    score = evaluateLine(x, y, player, DIAGONAL_RIGHT, score);
    score = evaluateLine(x, y, player, DIAGONAL_LEFT, score);
    score = evaluateLine(x, y, player, VERTICAL, score);
    return score;
}

std::vector<std::pair<int, int>> Map::getValidMoves(int radius) {
    std::set<std::pair<int, int>> candidates;

    for (std::size_t x = 0; x < _size; ++x) {
        for (std::size_t y = 0; y < _size; ++y) {
            if (_map[x][y].getValue() != CellValue::NONE) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    for (int dy = -radius; dy <= radius; ++dy) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < (int)_size && ny >= 0 && ny < (int)_size && _map[nx][ny].getValue() == CellValue::NONE) {
                            candidates.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }
    return std::vector<std::pair<int, int>>(candidates.begin(), candidates.end());
}

std::pair<int, int> Map::computeTree()
{
    int bestScore = int(-INFINITY);
    std::pair<int, int> bestMove;
    std::vector<std::pair<int, int>> moves = getValidMoves(RADIUS);
    std::vector<std::pair<int, int>> reducedMoves;

    for (std::size_t i = 0; i < moves.size(); i++) {
        _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER1);
        reducedMoves = moves;
        reducedMoves.erase(reducedMoves.begin() + i);
        int score = miniMax(DEPTH - 1, false, int(-INFINITY), int(INFINITY), moves[i].first, moves[i].second, reducedMoves);
        _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
        if (score > bestScore) {
            bestScore = score;
            bestMove = moves[i];
        }
    }
    return bestMove;
}

int Map::miniMax(int depth, bool playerTurn, int alpha, int beta, int x, int y, std::vector<std::pair<int, int>> moves)
{
    if (depth == 0 or moves.size() == 0) {
        if (playerTurn)
            return evaluation(x, y, CellValue::PLAYER2);
        return evaluation(x, y, CellValue::PLAYER1);
    }

    std::vector<std::pair<int, int>> reducedMoves;
    if (playerTurn) {
        int maxEval = int(-INFINITY);
        for (std::size_t i = 0; i < moves.size(); i++) {
            _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER1);
            reducedMoves = moves;
            reducedMoves.erase(reducedMoves.begin() + i);
            int score = miniMax(depth - 1, false, alpha, beta, moves[i].first, moves[i].second, reducedMoves);
            _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
            maxEval = std::max(maxEval, score);
            if (maxEval >= beta)
                return maxEval;
            alpha = std::max(alpha, score);
        }
        return maxEval;
    } else {
        int minEval = int(INFINITY);
        for (std::size_t i = 0; i < moves.size(); i++) {
            _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER2);
            reducedMoves = moves;
            reducedMoves.erase(reducedMoves.begin() + i);
            int score = miniMax(depth - 1, true, alpha, beta, moves[i].first, moves[i].second, reducedMoves);
            _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
            minEval = std::min(minEval, score);
            if (alpha >= minEval)
                return minEval;
            beta = std::min(beta, score);
        }
        return minEval;
    }
}
