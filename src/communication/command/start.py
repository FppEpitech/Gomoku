#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## start
##

from src.Map.map import *

def handle_start(size: int, map: Map) -> None:
    if (size != 20):
        print("ERROR size is not 20")
    else:
        map.size = size
        map.create_map(size)
        print("OK")

        with open("output.log", "a") as f:
            print("Map created:", file=f)
        map.display_map()

