/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include "Map.hpp"
#include "Algorithms/Algorithm.hpp"
#include <memory>

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
    _algo = std::make_shared<Algorithm>(_size, _map);
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
    auto avoidwinningPattern = _checkForWinPattern(CellValue::PLAYER2);
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
    } else if (avoidwinningPattern) {
        if (file.is_open())
                file << "Avoid wining patern move : " << avoidwinningPattern->first << "," << avoidwinningPattern->second << std::endl;
        std::cout << avoidwinningPattern->first << "," << avoidwinningPattern->second << std::endl;
        _map[avoidwinningPattern->first][avoidwinningPattern->second].setValue(CellValue::PLAYER1);
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
            Algorithm algo(_size, _map);
            std::pair<int, int> move = algo.computeTree();
            _map[move.first][move.second].setValue(CellValue::PLAYER1);
            std::cout << move.first << "," << move.second << std::endl;
            if (file.is_open())
                file << "We've played on : " << move.first << "," << move.second << std::endl;
            displayMap();
        }
    }
    file.close();
}
