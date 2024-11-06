#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## turn
##

from src.Map.map import *
from src.algorithm.ai import *

def handle_turn(x: int, y: int, map: Map, ai: Ai) -> None:
    if 0 <= x < map.size and 0 <= y < map.size:
        map.map[x][y].setValue(CellValue.PLAYER2)
    ai.play(map)
