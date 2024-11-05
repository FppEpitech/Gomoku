#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## Gomoku
## File description:
## tests easy win
##

from src.Map.map import *
from src.communication.command.board import handle_board as BOARD_COMMAND
import unittest
from unittest.mock import patch
from io import StringIO

BOARD1 = [
    [0,0,0,0,0],
    [0,0,0,0,0],
    [1,1,1,1,0],
    [0,0,0,0,0],
    [0,0,0,0,0]
]

BOARD2 = [
    [0,0,0,0,0],
    [0,0,0,0,0],
    [1,1,0,1,1],
    [0,0,0,0,0],
    [0,0,0,0,0]
]

BOARD3 = [
    [0,0,0,0,0],
    [0,0,0,1,0],
    [0,0,1,0,0],
    [0,1,0,0,0],
    [1,0,0,0,0]
]

BOARD4 = [
    [0,0,0,0,1],
    [0,0,0,1,0],
    [0,0,0,0,0],
    [0,1,0,0,0],
    [1,0,0,0,0]
]

def create_board(board) -> str:
    result : list = []
    for x in range(len(board)):
        for y in range(len(board)):
            if board[x][y] == 1 or board[x][y] == 2:
                result.append(f"{x},{y},{board[x][y]}")
    result.append("DONE")
    return result

def tests_easy_wins():
    unittest.main()

class TestBoardControl(unittest.TestCase):
    @patch('builtins.input', side_effect=create_board(BOARD1))
    @patch('sys.stdout', new_callable=StringIO)

    def test_easy_win_side(self, mock_stdout, mock_input):
        map = Map()
        map.size = len(BOARD1)
        map.createMap(map.size)
        BOARD_COMMAND(map)
        printed_output = mock_stdout.getvalue().strip()
        print(printed_output)
        self.assertEqual(printed_output, "4,2")

    @patch('builtins.input', side_effect=create_board(BOARD2))
    @patch('sys.stdout', new_callable=StringIO)
    def test_easy_win_middle(self, mock_stdout, mock_input):
        map = Map()
        map.size = len(BOARD2)
        map.createMap(map.size)
        BOARD_COMMAND(map)
        printed_output = mock_stdout.getvalue().strip()
        print(printed_output)
        self.assertEqual(printed_output, "2,2")

    @patch('builtins.input', side_effect=create_board(BOARD3))
    @patch('sys.stdout', new_callable=StringIO)
    def test_easy_win_diag(self, mock_stdout, mock_input):
        map = Map()
        map.size = len(BOARD3)
        map.createMap(map.size)
        BOARD_COMMAND(map)
        printed_output = mock_stdout.getvalue().strip()
        print(printed_output)
        self.assertEqual(printed_output, "4,0")

    @patch('builtins.input', side_effect=create_board(BOARD4))
    @patch('sys.stdout', new_callable=StringIO)
    def test_easy_win_diag_middle(self, mock_stdout, mock_input):
        map = Map()
        map.size = len(BOARD4)
        map.createMap(map.size)
        BOARD_COMMAND(map)
        printed_output = mock_stdout.getvalue().strip()
        print(printed_output)
        self.assertEqual(printed_output, "2,2")
