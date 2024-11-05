#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## create boards to tests
##

def create_board(board) -> str:
    result : list = []
    for x in range(len(board)):
        for y in range(len(board)):
            if board[x][y] == 1 or board[x][y] == 2:
                result.append(f"{x},{y},{board[x][y]}")
    result.append("DONE")
    return result
