/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** test easy win
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../../src/Map/Map.hpp"
#include "../../src/Parser/Parser.hpp"
#include "../../src/GameRules/GameRules.hpp"

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int BOARD1[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int BOARD2[5][5] = {
    {0, 2, 0, 0, 1},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 2},
    {0, 1, 0, 0, 0},
    {1, 0, 0, 0, 0}
};

int BOARD3[5][5] = {
    {0, 2, 1, 0, 1},
    {0, 0, 1, 2, 0},
    {1, 2, 1, 1, 2},
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0}
};

Test(Easy_win, test_easy_win_side_line, .timeout = 5, .init = redirect_all_std)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_win_line.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_win_line.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD1[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD1[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_win_line.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_win_line.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("2,4\n");
    fclose(input_redirected);
    remove("test_input_win_line.txt");
}

Test(Easy_win, test_easy_win_side_diago, .timeout = 5, .init = redirect_all_std)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_win_diago.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_win_diago.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD2[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD2[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_win_diago.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_win_diago.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("2,2\n");
    fclose(input_redirected);
    remove("test_input_win_diago.txt");
}

Test(Easy_win, test_easy_win_side_col, .timeout = 5, .init = redirect_all_std)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_win_col.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_win_col.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD3[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD3[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_win_col.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_win_col.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("3,2\n");
    fclose(input_redirected);
    remove("test_input_win_col.txt");
}
