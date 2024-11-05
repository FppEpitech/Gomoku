#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

from src.Map.map import *
from src.communication.parser import parse_command

def main():
    map:Map = Map()

    while True:
        command:str = str(input(''))
        parse_command(command, map)

if __name__ == "__main__":
    main()
