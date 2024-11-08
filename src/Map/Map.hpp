/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Map
*/

#include <vector>
#include <string>
#include <fstream>
#include <optional>
#include <iostream>

#define HORIZONTAL 0, 1
#define VERTICAL 1, 1
#define DIAGONAL_RIGHT 1, 0
#define DIAGONAL_LEFT 1, -1

#pragma once

enum class CellValue {
    NONE = '.',
    PLAYER1 = 'O',
    PLAYER2 = 'X'
};

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
         * @brief Play on the map.
         *
         */
        void play(void);

    private:

        /**
         * @brief Check if the player can win.
         *
         * @param player Player to check.
         */
        std::optional<std::pair<int, int>> _canWin(CellValue player);

        /**
         * @brief Check the conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         */
        bool _checkWin(int x, int y, CellValue player);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y
         */
        bool _checkDirection(int x, int y, CellValue player, int dx, int dy);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y
         */
        int _countInDirection(int x, int y, CellValue player, int dx, int dy);


        std::size_t _size;                       // Size of map.
        std::vector<std::vector<Cell>> _map;     // Map where play.
};

