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

    count += _countInDirection(x, y, player, dx, dy, false);
    count += _countInDirection(x, y, player, -dx, -dy, false);
    return count >= 5;
}

int Map::_countInDirection(int x, int y, CellValue player, int dx, int dy, bool isEvaluationMode)
{
    int count = 0;
    int counter = 0;
    bool isBlank = false;

    while (true) {
        if (isEvaluationMode && counter == 4)
            break;
        counter++;
        x += dx;
        y += dy;
        if (x >= 0 && x < (int)_size && y >= 0 && y < (int)_size) {
            if (_map[x][y].getValue() == player)
                ++count;
            else if (_map[x][y].getValue() == CellValue::NONE && isEvaluationMode && !isBlank) {
                isBlank = true;
                continue;
            }
            else
                break;
        } else {
            break;
        }
    }
    return count;
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
        std::vector<std::pair<int, int>> empty_cells;
        for (int x = 0; x < (int)_size; ++x) {
            for (int y = 0; y < (int)_size; ++y) {
                if (_map[x][y].getValue() == CellValue::NONE)
                    empty_cells.emplace_back(x, y);
            }
        }

        if (!empty_cells.empty()) {
            std::srand(std::time(nullptr));
            auto [x, y] = empty_cells[std::rand() % empty_cells.size()];

            _map[x][y].setValue(CellValue::PLAYER1);
            if (file.is_open())
                file << "We've want to play on : " << x << "," << y << std::endl;
            std::cout << x << "," << y << std::endl;

            if (file.is_open())
                file << "We've played on : " << x << "," << y << std::endl;

            displayMap();
        }
    }
    file.close();
}

std::size_t Map::evaluateLine(int x, int y, CellValue player, int vx, int vy, std::size_t scoreMax)
{
    int count = 1;
    count += _countInDirection(x, y, player, vx, vy, true);
    count += _countInDirection(x, y, player, -vx, -vy, true);

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
