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

void Map::play(void)
{
    auto winningMove = _canWin(CellValue::PLAYER1);
    auto avoidLose = _canWin(CellValue::PLAYER2);

    if (winningMove)
        std::cout << winningMove->first << ", " << winningMove->second << std::endl;
    else if (avoidLose)
        std::cout << avoidLose->first << ", " << avoidLose->second << std::endl;
    else
        std::cout << "0, 0" << std::endl; // To Do AI
}
