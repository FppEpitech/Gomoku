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

void redirect_all_std_avoid_loose(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

int BOARD4[5][5] = {
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {2, 2, 2, 0, 2},
    {0, 1, 0, 0, 0},
    {1, 1, 1, 0, 0}
};

int BOARD5[5][5] = {
    {0, 1, 0, 0, 2},
    {0, 0, 0, 2, 0},
    {2, 2, 2, 2, 1},
    {0, 2, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int BOARD6[5][5] = {
    {0, 1, 2, 0, 2},
    {0, 0, 0, 1, 0},
    {2, 1, 2, 1, 1},
    {0, 1, 2, 0, 0},
    {2, 0, 2, 0, 0}
};

Test(Avoid_loose, test_easy_loose_side_line, .timeout = 5, .init = redirect_all_std_avoid_loose)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_loose_line.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_loose_line.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD4[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD4[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_loose_line.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_loose_line.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("2,3\n");
    fclose(input_redirected);
    remove("test_input_loose_line.txt");
}

Test(Avoid_loose, test_easy_loose_side_diago, .timeout = 5, .init = redirect_all_std_avoid_loose)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_loose_diago.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_loose_diago.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD5[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD5[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_loose_diago.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_loose_diago.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("4,0\n");
    fclose(input_redirected);
    remove("test_input_loose_diago.txt");
}

Test(Avoid_loose, test_easy_loose_side_col, .timeout = 5, .init = redirect_all_std_avoid_loose)
{
    Map map;
    Parser parser;
    GameRules gameRules;
    map.createMap(5);

    FILE *input_file = fopen("test_input_loose_col.txt", "w+");
    if (!input_file)
        cr_assert_fail("Could not open test_input_loose_col.txt for writing");

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 5; ++x) {
            if (BOARD6[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, BOARD6[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);

    FILE *input_redirected = freopen("test_input_loose_col.txt", "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to test_input_loose_col.txt");


    parser.parseCommand("BOARD", map, gameRules);

    cr_assert_stdout_eq_str("1,2\n");
    fclose(input_redirected);
    remove("test_input_loose_col.txt");
}
