/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** test create complex pattern
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <string>

#include "../../src/Map/Map.hpp"
#include "../../src/Parser/Parser.hpp"
#include "../../src/GameRules/GameRules.hpp"

void redirect_all_std_create_complex_pattern(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

std::vector<std::vector<int>> BOARD_CREATE_COMPLEX_PATTERN_WIN1 = {
    {0, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_CREATE_COMPLEX_PATTERN_ANSWER_1 = "4,2\n";

std::vector<std::vector<std::vector<int>>> boardsCreatePattern = {
    BOARD_CREATE_COMPLEX_PATTERN_WIN1,

};

std::vector<std::string> answersCreatePattern = {
    BOARD_CREATE_COMPLEX_PATTERN_ANSWER_1,
};

void createMapPattern(std::string file, std::vector<std::vector<int>> board, int size)
{
    FILE *input_file = fopen(file.c_str(), "w+");
    if (!input_file)
        cr_assert_fail("Could not open file for writing");

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (board[y][x] != 0) {
                fprintf(input_file, "%d,%d,%d\n", y, x, board[y][x]);
            }
        }
    }
    fprintf(input_file, "DONE\n");
    fflush(input_file);
    fclose(input_file);
}

Test(CreateComplexPatterns, test_create_complex_patterns1, .timeout = 5, .init = redirect_all_std_create_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 0;

    Map map;
    int size = boardsCreatePattern[i].size();
    map.createMap(size);
    std::string path = "test_create_complex_pattern1.txt";
    createMapPattern(path, boardsCreatePattern[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answersCreatePattern[i].c_str());
}
