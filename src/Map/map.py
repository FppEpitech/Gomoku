##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

import random
from enum import Enum

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
