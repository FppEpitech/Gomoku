#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## board
##

from src.Map.map import *

def handle_board(map: Map) -> None:

    while True:
        line:str = str(input(''))

        if line.upper() == "DONE":
            break

        try:
            x_str, y_str, field_str = line.split(",")
            x = int(x_str)
            y = int(y_str)
            field = int(field_str)

            if field == 1:
                cell_value = CellValue.PLAYER1
            elif field == 2:
                cell_value = CellValue.PLAYER2
            else:
                raise ValueError("Champ de valeur invalide.")
            map[x][y].setValue(cell_value)
            with open("output.log", "a") as f:
                print(f"Case of Map [{x}] | [{y}] <- [{field}] Player", file=f)
        except ValueError:
            with open("output.log", "a") as f:
                print(f"Erreur dans le format des données : {line}", file=f)
            continue
    map.play_random()
