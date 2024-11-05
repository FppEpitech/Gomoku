#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

from src.Map.map import *
from src.Game_rules.game_rules import *
from src.communication.parser import parse_command

def main():
    map: Map = Map()
    game_rule: Game_rules = Game_rules()

    while True:
        command:str = str(input(''))
        parse_command(command, map, game_rule)

if __name__ == "__main__":
    main()
