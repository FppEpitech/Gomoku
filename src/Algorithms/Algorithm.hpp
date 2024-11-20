#pragma once

#include <vector>
#include <utility>

enum class CellValue;
class Cell;

class Algorithm {
    public:

        Algorithm(std::size_t &size, std::vector<std::vector<Cell>> &map) : _map(map), _size(size) {}

        /**
         * @brief Compute the tree with minimax.
         *
         * @return std::pair<int, int> Position to play.
         */
        std::pair<int, int> miniMax();

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
        int computeMiniMax(int depth, bool playerTurn, int alpha, int beta, int x, int y, std::vector<std::pair<int, int>> moves);

        /**
         * @brief Get the Valid Moves list.
         *
         * @param radius Radius arround played moves.
         * @return std::vector<std::pair<int, int>> List of valid moves.
         */
        std::vector<std::pair<int, int>> getValidMoves(int radius);

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
        std::size_t evaluateLine(int x, int y, CellValue player, int vx, int vy);

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
        std::tuple<int, int, CellValue> _countInDirectionEvaluation(int x, int y, CellValue player, int dx, int dy);

        bool playWinPattern(int x, int y, CellValue player);

    private:

        /**
         * @brief Evaluate the creation of patterns.
         *
         * @param x X of conditional play.
         * @param y Y of conditional play.
         * @param player Player to check.
         * @return std::size_t Score.
         */
        std::size_t _evalCreatePattern(int x, int y, CellValue player);

        bool _evaluatePattern(int x, int y, CellValue player, int vx, int vy);
        std::tuple<int, int, CellValue> _countInDirectionWithBlocks(int x, int y, CellValue player, int dx, int dy);
        std::size_t _evalCreateSquarePattern(int x, int y, CellValue player);

        std::vector<std::vector<Cell>> &_map;
        std::size_t &_size;
};
