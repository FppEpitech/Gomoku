#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## begin
##

from src.Map.map import *

def handle_begin(map: Map) -> None:
    map.playRandom()
