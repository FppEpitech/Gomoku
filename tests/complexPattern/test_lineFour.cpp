/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** test easy win
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <string>

#include "../../src/Map/Map.hpp"
#include "../../src/Parser/Parser.hpp"
#include "../../src/GameRules/GameRules.hpp"

void redirect_all_std_line_four(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

std::vector<std::vector<int>> BOARD_LINE_FOUR_1 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 2, 2, 2, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_LINE_FOUR_ANSWER_1 = "4,1\n";

std::vector<std::vector<int>> BOARD_LINE_FOUR_2 = {
    {0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 2, 2, 2, 0},
    {0, 2, 2, 2, 0, 0}
};
std::string BOARD_LINE_FOUR_ANSWER_2 = "5,4\n";

std::vector<std::vector<int>> BOARD_LINE_FOUR_3 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_LINE_FOUR_ANSWER_3 = "4,3\n";

std::vector<std::vector<int>> BOARD_LINE_FOUR_4 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 2, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_LINE_FOUR_ANSWER_4 = "1,1\n";

std::vector<std::vector<std::vector<int>>> boards_line_four = {
    BOARD_LINE_FOUR_1,
    BOARD_LINE_FOUR_2,
    BOARD_LINE_FOUR_3,
    BOARD_LINE_FOUR_4
};

std::vector<std::string> answers_line_four = {
    BOARD_LINE_FOUR_ANSWER_1,
    BOARD_LINE_FOUR_ANSWER_2,
    BOARD_LINE_FOUR_ANSWER_3,
    BOARD_LINE_FOUR_ANSWER_4
};

void createMapLineFour(std::string file, std::vector<std::vector<int>> board, int size)
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

Test(LineFour, test_complex_line_four1, .timeout = 5, .init = redirect_all_std_line_four)
{
    Parser parser;
    GameRules gameRules;
    int i = 0;

    Map map;
    int size = boards_line_four[i].size();
    map.createMap(size);
    std::string path = "test_line_four.txt";
    createMapLineFour(path, boards_line_four[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers_line_four[i].c_str());
}

Test(LineFour, test_complex_line_four2, .timeout = 5, .init = redirect_all_std_line_four)
{
    Parser parser;
    GameRules gameRules;
    int i = 1;

    Map map;
    int size = boards_line_four[i].size();
    map.createMap(size);
    std::string path = "test_line_four1.txt";
    createMapLineFour(path, boards_line_four[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers_line_four[i].c_str());
}

Test(LineFour, test_complex_line_four3, .timeout = 5, .init = redirect_all_std_line_four)
{
    Parser parser;
    GameRules gameRules;
    int i = 2;

    Map map;
    int size = boards_line_four[i].size();
    map.createMap(size);
    std::string path = "test_line_four2.txt";
    createMapLineFour(path, boards_line_four[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers_line_four[i].c_str());
}

Test(LineFour, test_complex_line_four4, .timeout = 5, .init = redirect_all_std_line_four)
{
    Parser parser;
    GameRules gameRules;
    int i = 3;

    Map map;
    int size = boards_line_four[i].size();
    map.createMap(size);
    std::string path = "test_line_four3.txt";
    createMapLineFour(path, boards_line_four[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers_line_four[i].c_str());
}


