#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## about
##

import sys

from src.Map.map import *
from src.communication.command.start import handle_start
from src.communication.command.turn import handle_turn
from src.communication.command.begin import handle_begin
from src.communication.command.board import handle_board
from src.communication.command.info import handle_info
from src.communication.command.end import handle_end
from src.communication.command.about import handle_about

def parse_command(command: str, map_ground: Map) -> None:
    parts = command.split()
    cmd = parts[0].upper()

    with open("output.log", "a") as f:
        command = command.replace("\r", "")
        print(f"\nCurrent commande: [{command}]", file=f)

    commands = {
        "START": lambda parts: handle_start(int(parts[1]), map_ground),
        "TURN": lambda parts: handle_turn(*map(int, parts[1].split(',')), map_ground),
        "BEGIN": lambda parts: handle_begin(map_ground),
        "BOARD": lambda parts: handle_board(map_ground),
        "INFO": lambda parts: handle_info(str(parts[1]), int(parts[2])),
        "END": lambda parts: handle_end(),
        "ABOUT": lambda parts: handle_about(),
    }

    if cmd in commands:
        try:
            commands[cmd](parts)
        except (IndexError, ValueError):
            print("Erreur de syntaxe pour la commande :", command)
    else:
        print("Commande non reconnue :", cmd)
