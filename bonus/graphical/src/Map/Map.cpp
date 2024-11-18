/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include <memory>
#include "Map.hpp"
#include "Rules.hpp"

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
    _myTurn = false;
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

void Map::displayMapGraphic(GraphicLib *graphicLib)
{
    float width = GetScreenWidth() - 100;
    float height = GetScreenHeight() - 100;

    width /= _size;
    height /= _size;

    float cellSize = (width > height) ? height : width;

    for (std::size_t x = 0; x < _size; x++) {
        for (std::size_t y = 0; y < _size; y++) {
            graphicLib->drawRectangle(x * cellSize + 50, y * cellSize + 50, cellSize, cellSize);
            if (_map[x][y].getValue() == CellValue::PLAYER1)
                graphicLib->drawTexture(ASSET_PLAYER_1, x * cellSize - 3000 * 0.02 / 8 + 50, y * cellSize - 3000 * 0.02 / 8 + 50, 0.02, WHITE);
            else if (_map[x][y].getValue() == CellValue::PLAYER2)
                graphicLib->drawTexture(ASSET_PLAYER_1, x * cellSize - 3000 * 0.02 / 8 + 50, y * cellSize - 3000 * 0.02 / 8 + 50, 0.02, GRAY);
        }
    }
}

void Map::clickOnMap(GraphicLib *graphicLib)
{
    float width = GetScreenWidth() - 100;
    float height = GetScreenHeight() - 100;
    width /= _size;
    height /= _size;
    float cellSize = (width > height) ? height : width;
    std::pair<int, int> mousePos = graphicLib->getMousePosition();

    int x = (mousePos.first - 50) / cellSize;
    int y = (mousePos.second - 50) / cellSize;

    if (x < int(_map.size()) && y < int(_map[x].size()) && _map[x][y].getValue() == CellValue::NONE) {
        _map[x][y].setValue(CellValue::PLAYER1);
        _myTurn = false;
        std::cout << x << "," << y << std::endl;
    }
}
