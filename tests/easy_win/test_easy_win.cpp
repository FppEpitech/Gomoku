/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** test easy win
*/

#include "CriterionHeaders.hpp"
#include "Map/Map.hpp"
#include "Parser/Parser.hpp"
#include "GameRules/GameRules.hpp"

int BOARD1[5][5] {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

Test(Easy_win, test_easy_win_side, .timeout = 5, .init = redirect_all_std)
{
    Map map;
    Parser parser;
    GameRules gameRules;

    map.createMap(5);
    FILE *input_file = fopen("test_input.txt", "w+");
    fprintf(input_file, "1,1,1\nDONE\n");
    rewind(input_file);
    FILE *original_stdin = stdin;
    stdin = input_file;
    parser.parseCommand("BOARD", map, gameRules);
    stdin = original_stdin;
    fclose(input_file);
    cr_assert_stderr_eq_str("2, 4");
}
