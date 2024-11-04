#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## start
##

def handle_start(size: int) -> None:
    if (size != 20):
        print("ERROR size is not 20")
    else:
        print("OK")
