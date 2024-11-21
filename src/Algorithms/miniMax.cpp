/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** miniMax
*/

#include "Algorithms/Algorithm.hpp"
#include "Map/Map.hpp"

std::pair<int, int> Algorithm::miniMax(int timeout)
{
    int bestScore = int(-INFINITY);
    std::pair<int, int> bestMove;
    std::vector<std::pair<int, int>> moves = getValidMoves(RADIUS);
    std::vector<std::pair<int, int>> reducedMoves;

    for (std::size_t i = 0; i < moves.size(); i++) {
        if (start.time_since_epoch().count() >= timeout)
            return bestMove;
        _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER1);
        reducedMoves = moves;
        reducedMoves.erase(reducedMoves.begin() + i);
        int score = computeMiniMax(DEPTH - 1, false, int(-INFINITY), int(INFINITY), moves[i].first, moves[i].second, reducedMoves);
        _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
        if (score > bestScore) {
            bestScore = score;
            bestMove = moves[i];
        }
    }
    return bestMove;
}

int Algorithm::computeMiniMax(int depth, bool playerTurn, int alpha, int beta, int x, int y, std::vector<std::pair<int, int>> moves)
{
    if (depth == 0 or moves.size() == 0) {
        if (playerTurn)
            return evaluation(x, y, CellValue::PLAYER2);
        return evaluation(x, y, CellValue::PLAYER1);
    }

    std::vector<std::pair<int, int>> reducedMoves;
    if (playerTurn) {
        int maxEval = int(-INFINITY);
        for (std::size_t i = 0; i < moves.size(); i++) {
            _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER1);
            reducedMoves = moves;
            reducedMoves.erase(reducedMoves.begin() + i);
            int score = computeMiniMax(depth - 1, false, alpha, beta, moves[i].first, moves[i].second, reducedMoves);
            _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
            maxEval = std::max(maxEval, score);
            if (maxEval >= beta)
                return maxEval;
            alpha = std::max(alpha, score);
        }
        return maxEval;
    } else {
        int minEval = int(INFINITY);
        for (std::size_t i = 0; i < moves.size(); i++) {
            _map[moves[i].first][moves[i].second].setValue(CellValue::PLAYER2);
            reducedMoves = moves;
            reducedMoves.erase(reducedMoves.begin() + i);
            int score = computeMiniMax(depth - 1, true, alpha, beta, moves[i].first, moves[i].second, reducedMoves);
            _map[moves[i].first][moves[i].second].setValue(CellValue::NONE);
            minEval = std::min(minEval, score);
            if (score > 1000)
                return score;
            if (alpha >= minEval)
                return minEval;
            beta = std::min(beta, score);
        }
        return minEval;
    }
}
