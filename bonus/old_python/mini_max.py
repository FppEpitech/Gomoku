##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## mini max algorithm
##

from src.Map.map import *

import math

DEPTH = 3

class MiniMax:

    def __init__(self):
        pass
        
    def get_valid_moves(self, map : Map) -> list[(int, int)]:
        moves : list[(int, int)] = []
        for x in range(map.size):
            for y in range(map.size):
                if map.map[x][y].value == CellValue.NONE:
                    moves.append((x, y))
        return moves

    def compute(self, map):
        best_value = -math.inf
        best_move = None
        for move in self.get_valid_moves(map):
            x, y = move
            map.map[x][y].setValue(CellValue.PLAYER1)
            score = self.minimax(map, DEPTH - 1, False, -math.inf, math.inf)
            map.map[x][y].setValue(CellValue.NONE)
            if score > best_value:
                best_value = score
                best_move = move
        return best_move

    def evaluation(self):
        return random.randint(-100, 100)

    def minimax(self, map : Map, depth : int, playerTurn : bool, alpha, beta):
        if depth == 0 or len(self.get_valid_moves(map)) == 0:
            return self.evaluation()

        if playerTurn:
            max_eval = -math.inf
            for move in self.get_valid_moves(map):
                x, y = move
                map.map[x][y].setValue(CellValue.PLAYER1)
                score = self.minimax(map, depth - 1, False, alpha, beta)
                map.map[x][y].setValue(CellValue.NONE)
                max_eval = max(max_eval, score)
                if max_eval >= beta:
                    return max_eval
                alpha = max(alpha, score)
            return max_eval

        else:
            min_eval = math.inf
            for move in self.get_valid_moves(map):
                x, y = move
                map.map[x][y].setValue(CellValue.PLAYER2)
                score = self.minimax(map, depth -1, True, alpha, beta)
                map.map[x][y].setValue(CellValue.NONE)
                min_eval = min(min_eval, score)
                if alpha >= min_eval:
                    return min_eval
                beta = min(beta, score)
            return min_eval
