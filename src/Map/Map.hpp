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

        /**
         * @brief This method evaluate the placement of a point
         * on the map and return it score.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @return int Score of the evaluation.
         */
        int evaluation(int x, int y, CellValue player);

        /**
         * @brief Evaluate the score of a line.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param vx Direction in X.
         * @param vy Direction in Y.
         * @param scoreMax Score max of the current point.
         * @return std::size_t Return the Score max.
         */
        std::size_t evaluateLine(int x, int y, CellValue player, int vx, int vy, std::size_t scoreMax);

    private:

        /**
         * @brief Check if the player can align X pawns.
         *
         * @param player Player to check.
         * @param nbPawns Nb Pawns to check if the player can align
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
         * @brief Check all direction of conditional play.
         * This function is used by the evaluation method.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y.
         * @return std::pair<int, int> first is values before space, second is value after space.
         */
        std::pair<int, int> _countInDirectionEvaluation(int x, int y, CellValue player, int dx, int dy);

        /**
         * @brief Compute the tree with minimax.
         *
         * @return std::pair<int, int> Position to play.
         */
        std::pair<int, int> computeTree();

        /**
         * @brief Minimax algorithm.
         *
         * @param depth Depth to visualize.
         * @param playerTurn True = player 1, false = player2.
         * @param alpha Alpha value.
         * @param beta Beta value.
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param moves List of available moves.
         * @return int Score.
         */
        int miniMax(int depth, bool playerTurn, int alpha, int beta, int x, int y, std::vector<std::pair<int, int>> moves);

        /**
         * @brief Get the Valid Moves list.
         *
         * @param radius Radius arround played moves.
         * @return std::vector<std::pair<int, int>> List of valid moves.
         */
        std::vector<std::pair<int, int>> getValidMoves(int radius);

        /**
         * @brief Check if there is a winning pattern.
         *
         * @param player Player to check.
         * @return std::optional<std::pair<int, int>> Position to play, or null.
         */
        std::optional<std::pair<int, int>> _checkForWinPattern(CellValue player);

        /**
         * @brief Try to play a pattern.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @return true Pattern matched.
         * @return false Pattern don't matched.
         */
        bool _playWinPattern(int x, int y, CellValue player);

        /**
         * @brief Check all direction of conditional play.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @param dx Direction in X.
         * @param dy Direction in Y.
         * @return std::tuple<int, int, CellValue> Return number of first alignement of pieces,
         * the second alignement, and the value which separate first and second.
         */
        std::tuple<int, int, CellValue> _countInDirectionWithBlocks(int x, int y, CellValue player, int dx, int dy);

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

        std::size_t _size;                       // Size of map.
        std::vector<std::vector<Cell>> _map;     // Map where play.
};
