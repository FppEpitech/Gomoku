##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

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

    def __init__(self, size: int) -> None:
        self.size : int = size
        self.map : list[list[Cell]] = []
        self.createMap(self.size)

    def createMap(self, size : int) -> None:
        for x in range(size):
            self.map.append([])
            for y in range(size):
                self.map[x].append(Cell())

    def displayMap(self) -> None:
        for x in range(self.size):
            for y in range(self.size):
                print(self.map[y][x].value.value, end=" ")
            print()
