/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#pragma once

#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <optional>
#include <iostream>
#include <memory>

#include "GraphicLib/GraphicLib.hpp"

enum class CellValue {
    NONE = '.',
    PLAYER1 = 'O',
    PLAYER2 = 'X'
};

class Algorithm;

class Cell {

    public:

        /**
         * @brief Construct a new Cell object.
         *
         */
        Cell(void);

        /**
         * @brief Set the Value object.
         *
         * @param value Value to set in cell.
         */
        void setValue(CellValue value);

        /**
         * @brief Get the Value object.
         *
         * @return CellValue The value of the cell.
         */
        CellValue getValue(void) const;

    private:
        CellValue _value; // Value of a cell.
};

class Map {

    public:

        /**
         * @brief Construct a new Map object.
         *
         */
        Map(void);

        /**
         * @brief Set the Size object
         *
         */
        void setSize(std::size_t size);

        /**
         * @brief Get the Size object.
         *
         * @return std::size_t Size of map.
         */
        std::size_t getSize(void);

        /**
         * @brief Get the Size object.
         *
         * @return std::size_t Size of map.
         */
        std::vector<std::vector<Cell>>& getMap(void);

        /**
         * @brief Create a Map object.
         *
         * @param size Size of map to create.
         */
        void createMap(std::size_t size);

        /**
         * @brief Display the map in log file.
         *
         */
        void displayMap(void);

        /**
         * @brief Display map on a graphical window.
         *
         * @param graphicLib Graphical library.
         */
        void displayMapGraphic(GraphicLib *graphicLib);

        /**
         * @brief Mouse button click on map.
         *
         * @param graphicLib Graphical library.
         */
        void clickOnMap(GraphicLib *graphicLib);

        bool _myTurn;

    private:

        std::size_t _size;                       // Size of map.
        std::vector<std::vector<Cell>> _map;     // Map where play.
        std::shared_ptr<Algorithm> _algo;   // Algorithm to play.
};
