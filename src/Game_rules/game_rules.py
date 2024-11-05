##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## main
##

class Game_rules:

    def __init__(self) -> None:
        self.timeout_turn : int = 0
        self.timeout_match : int = 0
        self.max_memory : int = 0
        self.time_left : int = 0
        self.game_type : int = 0
        self.rule : int = 0
        self.evaluate : int = 0
        self.folder : int = 0
