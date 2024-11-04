#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

from src.communication.parser import parse_command

def main():
    while True:
        command = str(input(''))
        parse_command(command)

if __name__ == "__main__":
    main()
