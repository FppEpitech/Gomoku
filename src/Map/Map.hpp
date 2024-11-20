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

#define HORIZONTAL 0, 1
#define VERTICAL 1, 1
#define DIAGONAL_RIGHT 1, 0
#define DIAGONAL_LEFT 1, -1

#define SCORE_PERCENTAGE 10

#define DEPTH 3
#define RADIUS 2

#define PAWNS_TO_WIN 5
#define PAWNS_FOUR 4

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
         * @brief Play on the map.
         *
         */
        void play(void);

    private:

        /**
         * @brief Check if the player can align X pawns.
         *
         * @param player Player to check.
         * @param nbPawns Nb Pawns to check if the player can align
         * @return std::optional<std::pair<int, int>> Position to play, or null.
         */
        std::optional<std::pair<int, int>> _canAlignNbPawns(CellValue player, int nbPawns);

        /**
         * @brief Check the conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param nbPawns Nb Pawns to check if the player can align
         */
        bool _checkWin(int x, int y, CellValue player, int nbPawns);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y
         * @param nbPawns Nb Pawns to check if the player can align
         */
        bool _checkDirection(int x, int y, CellValue player, int dx, int dy, int nbPawns);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y.
         */
        int _countInDirection(int x, int y, CellValue player, int dx, int dy);

        /**
         * @brief Check if there is a winning pattern.
         *
         * @param player Player to check.
         * @return std::optional<std::pair<int, int>> Position to play, or null.
         */
        std::optional<std::pair<int, int>> _checkForWinPattern(CellValue player);

        /**
         * @brief Check if the player can align X pawns.
         *
         * @param player Player to check.
         */
        std::optional<std::pair<int, int>> _canAlignFourPawns(CellValue player);

        /**
         * @brief Check the conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         */
        bool _checkWinLineFour(int x, int y, CellValue player);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y
         */
        bool _checkDirectionLineFour(int x, int y, CellValue player, int dx, int dy);

        /**
         * @brief Check if the player can align X pawns.
         *
         * @param player Player to check.
         */
        std::optional<std::pair<int, int>> _canAlignMultipleLineOfThree(CellValue player);

        /**
         * @brief Check the conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         */
        bool _checkWinMultipleLineOfThree(int x, int y, CellValue player);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y
         */
        bool _checkDirectionMultipleLineOfThree(int x, int y, CellValue player, int dx, int dy);

        /**
         * @brief Evaluate if a pattern is present.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param vx Direction in X.
         * @param vy Direction in Y.
         * @return true It's a winning pattern.
         * @return false It's not.
         */
        bool evaluatePattern(int x, int y, CellValue player, int vx, int vy);

        /**
         * @brief Check the conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         */
        std::optional<std::pair<int, int>> _canAlignSquare(CellValue player);

        /**
         * @brief Check the conditional play for square.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         */
        bool _checkSquare(int x, int y, CellValue player);

        std::size_t _size;                       // Size of map.
        std::vector<std::vector<Cell>> _map;     // Map where play.
        std::shared_ptr<Algorithm> _algo;   // Algorithm to play.
};
