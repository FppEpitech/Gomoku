#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## info
##

from src.Game_rules.game_rules import *

def handle_info(key: str, value: int, game_rule: Game_rules) -> None:
    key_mapping = {
        "timeout_match": "timeout_match",
        "timeout_turn": "timeout_turn",
        "max_memory": "max_memory",
        "time_left": "time_left",
        "game_type": "game_type",
        "rule": "rule"
    }

    if key in key_mapping:
        setattr(game_rule, key_mapping[key], value)
