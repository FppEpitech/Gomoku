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

std::optional<std::pair<int, int>> Map::_canWin(CellValue player)
{
    for (int x = 0; x < (int)_size; ++x)
        for (int y = 0; y < (int)_size; ++y)
            if (_map[x][y].getValue() == CellValue::NONE)
                if (_checkWin(x, y, player))
                    return std::make_pair(x, y);
    return std::nullopt;
}

bool Map::_checkWin(int x, int y, CellValue player)
{
    _map[x][y].setValue(player);
    bool win = (_checkDirection(x, y, player, HORIZONTAL) ||
                _checkDirection(x, y, player, VERTICAL) ||
                _checkDirection(x, y, player, DIAGONAL_RIGHT) ||
                _checkDirection(x, y, player, DIAGONAL_LEFT));
    _map[x][y].setValue(CellValue::NONE);
    return win;
}

bool Map::_checkDirection(int x, int y, CellValue player, int dx, int dy)
{
    int count = 1;

    count += _countInDirection(x, y, player, dx, dy);
    count += _countInDirection(x, y, player, -dx, -dy);
    return count >= 5;
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

std::vector<std::pair<int, int>> Map::getCandidateMoves(int radius) {
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

double Map::minimax(int depth, bool playerTurn, double alpha, double beta)
{
    if (depth == 0 || getCandidateMoves(2).empty()) {
        return evaluation();
    }

    if (playerTurn) {
        double maxEval = -std::numeric_limits<double>::infinity();
        for (const auto& move : getCandidateMoves(2)) {
            int x = move.first;
            int y = move.second;
            _map[x][y].setValue(CellValue::PLAYER1);
            double score = minimax(DEPTH - 1, false, alpha, beta);
            _map[x][y].setValue(CellValue::NONE);
            maxEval = std::max(maxEval, score);
            if (maxEval >= beta) {
                return maxEval;
            }
            alpha = std::max(alpha, score);
        }
        return maxEval;
    } else {
        double minEval = std::numeric_limits<double>::infinity();
        for (const auto& move : getCandidateMoves(2)) {
            int x = move.first;
            int y = move.second;
            _map[x][y].setValue(CellValue::PLAYER2);
            double score = minimax(DEPTH - 1, true, alpha, beta);
            _map[x][y].setValue(CellValue::NONE);
            minEval = std::min(minEval, score);
            if (alpha >= minEval) {
                return minEval;
            }
            beta = std::min(beta, score);
        }
        return minEval;
    }
}

void Map::play(void)
{
    auto winningMove = _canWin(CellValue::PLAYER1);
    auto avoidLose = _canWin(CellValue::PLAYER2);
    std::ofstream file("output.log", std::ios_base::app);

    if (winningMove) {
        if (file.is_open())
                file << "Winning move : " << winningMove->first << "," << winningMove->second << std::endl;
        std::cout << winningMove->first << "," << winningMove->second << std::endl;
        _map[winningMove->first][winningMove->second].setValue(CellValue::PLAYER1);
    } else if (avoidLose) {
        if (file.is_open())
                file << "Avoid loosing move : " << avoidLose->first << "," << avoidLose->second << std::endl;
        std::cout << avoidLose->first << "," << avoidLose->second << std::endl;
        _map[avoidLose->first][avoidLose->second].setValue(CellValue::PLAYER1);
    } else {
        auto bestMove = findBestMove();
        if (bestMove.first != -1 && bestMove.second != -1) {
            _map[bestMove.first][bestMove.second].setValue(CellValue::PLAYER1);
            if (file.is_open())
                file << "move : " << bestMove.first << "," << bestMove.second << std::endl;
            std::cout << bestMove.first << "," << bestMove.second << std::endl;
            displayMap();
        }
    }
    file.close();
}
