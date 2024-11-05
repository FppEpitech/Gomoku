##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

import random
from enum import Enum

HORIZONTAL = (0, 1)
VERTICAL = (1, 1)
DIAGONAL_RIGHT = (1, 0)
DIAGONAL_LEFT = (1, -1)

class CellValue(Enum):
    NONE = "."
    PLAYER1 = "O"
    PLAYER2 = "X"

class Cell:

    def __init__(self) -> None:
        self.value : CellValue = CellValue.NONE

    def setValue(self, value : CellValue) -> None:
        self.value = value

class Map:

    def __init__(self) -> None:
        self.size : int = 0
        self.map : list[list[Cell]] = []

    def create_map(self, size : int) -> None:
        for x in range(size):
            self.map.append([])
            for y in range(size):
                self.map[x].append(Cell())

    def display_map(self) -> None:
        if self.size == 0:
            return
        with open("output.log", "a") as f:
            for x in range(self.size):
                print("===", end="", file=f)
            print("", file=f)
            for x in range(self.size):
                print("", end=" ", file=f)
                for y in range(self.size):
                    print(self.map[x][y].value.value, end="  ", file=f)
                print("", file=f)
            for x in range(self.size):
                print("===", end="", file=f)
            print("", file=f)

    def can_win(self, player: CellValue) -> tuple:
        for x in range(self.size):
            for y in range(self.size):
                if self.map[x][y].value == CellValue.NONE:
                    if self.check_win(x, y, player):
                        return (x, y)
        return None

    def check_win(self, x: int, y: int, player: CellValue) -> bool:
        self.map[x][y].value = player
        win = (self.check_direction(x, y, player, *HORIZONTAL) or
               self.check_direction(x, y, player, *VERTICAL) or
               self.check_direction(x, y, player, *DIAGONAL_RIGHT) or
               self.check_direction(x, y, player, *DIAGONAL_LEFT))
        self.map[x][y].value = CellValue.NONE
        return win

    def check_direction(self, x: int, y: int, player: CellValue, dx: int, dy: int) -> bool:
        count = 1

        count += self.count_in_direction(x, y, player, dx, dy)
        count += self.count_in_direction(x, y, player, -dx, -dy)
        return count >= 5

    def count_in_direction(self, x: int, y: int, player: CellValue, dx: int, dy: int) -> int:
        count = 0
        while True:
            x += dx
            y += dy
            if 0 <= x < self.size and 0 <= y < self.size:
                if self.map[x][y].value == player:
                    count += 1
                else:
                    break
            else:
                break
        return count

    def play(self) -> None:
        winning_move = self.can_win(CellValue.PLAYER1)
        avoid_loose = self.can_win(CellValue.PLAYER2)

        if winning_move:
            print(f"{winning_move[0]}, {winning_move[1]}")
        elif avoid_loose:
            print(f"{avoid_loose[0]}, {avoid_loose[1]}")
        else:
            #To do AI
            print(f"0, 0") # This is shit
