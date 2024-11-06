##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## ai
##

from src.Map.map import *
from src.algorithm.mini_max import MiniMax

HORIZONTAL = (0, 1)
VERTICAL = (1, 1)
DIAGONAL_RIGHT = (1, 0)
DIAGONAL_LEFT = (1, -1)

class Ai:

    def __init__(self):
        self.minimax = MiniMax()

    def can_win(self, map: Map, player: CellValue) -> tuple:
        for x in range(map.size):
            for y in range(map.size):
                if map.map[x][y].value == CellValue.NONE:
                    if self.check_win(x, y, map, player):
                        return (x, y)
        return None

    def check_win(self, x: int, y: int, map: Map, player: CellValue) -> bool:
        map.map[x][y].value = player
        win = (self.check_direction(x, y, map, player, *HORIZONTAL) or
               self.check_direction(x, y, map, player, *VERTICAL) or
               self.check_direction(x, y, map, player, *DIAGONAL_RIGHT) or
               self.check_direction(x, y, map, player, *DIAGONAL_LEFT))
        map.map[x][y].value = CellValue.NONE
        return win

    def check_direction(self, x: int, y: int, map: Map, player: CellValue, dx: int, dy: int) -> bool:
        count = 1

        count += self.count_in_direction(x, y, map, player, dx, dy)
        count += self.count_in_direction(x, y, map, player, -dx, -dy)
        return count >= 5

    def count_in_direction(self, x: int, y: int, map: Map, player: CellValue, dx: int, dy: int) -> int:
        count = 0
        while True:
            x += dx
            y += dy
            if 0 <= x < map.size and 0 <= y < map.size:
                if map.map[x][y].value == player:
                    count += 1
                else:
                    break
            else:
                break
        return count

    def play(self, map : Map) -> None:
        winning_move = self.can_win(map, CellValue.PLAYER1)
        avoid_loose = self.can_win(map, CellValue.PLAYER2)

        if winning_move:
            print(f"{winning_move[0]}, {winning_move[1]}")
        elif avoid_loose:
            print(f"{avoid_loose[0]}, {avoid_loose[1]}")
        else:
            x, y = self.minimax.compute(map)
            print(f"{x}, {y}")
