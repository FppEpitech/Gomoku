#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## begin
##

from src.Map.map import *
from src.algorithm.ai import *

def handle_begin(map: Map, ai: Ai) -> None:
    ai.play(map)
