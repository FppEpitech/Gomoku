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

void redirect_all_std_complex_pattern(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN1 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_1 = "4,5\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN2 = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_2 = "4,1\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN3 = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_3 = "4,4\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN4 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_4 = "4,1\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN5 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_5 = "1,1\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN6 = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_6 = "1,4\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN7 = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_7 = "1,3\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN8 = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_8 = "4,3\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN9 = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_9 = "4,3\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN10 = {
    {0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 2, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 2, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_10 = "4,1\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN11 = {
    {0, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_11 = "1,1\n";

std::vector<std::vector<int>> BOARD_COMPLEX_PATTERN_WIN12 = {
    {0, 0, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0},
    {0, 0, 2, 0, 0, 0},
    {0, 0, 0, 2, 0, 0},
    {0, 2, 2, 2, 0, 0},
    {0, 0, 0, 0, 0, 0}
};
std::string BOARD_COMPLEX_PATTERN_ANSWER_12 = "4,4\n";

std::vector<std::vector<std::vector<int>>> boards = {
    BOARD_COMPLEX_PATTERN_WIN1,
    BOARD_COMPLEX_PATTERN_WIN2,
    BOARD_COMPLEX_PATTERN_WIN3,
    BOARD_COMPLEX_PATTERN_WIN4,
    BOARD_COMPLEX_PATTERN_WIN5,
    BOARD_COMPLEX_PATTERN_WIN6,
    BOARD_COMPLEX_PATTERN_WIN7,
    BOARD_COMPLEX_PATTERN_WIN8,
    BOARD_COMPLEX_PATTERN_WIN9,
    BOARD_COMPLEX_PATTERN_WIN10,
    BOARD_COMPLEX_PATTERN_WIN11,
    BOARD_COMPLEX_PATTERN_WIN12
};

std::vector<std::string> answers = {
    BOARD_COMPLEX_PATTERN_ANSWER_1,
    BOARD_COMPLEX_PATTERN_ANSWER_2,
    BOARD_COMPLEX_PATTERN_ANSWER_3,
    BOARD_COMPLEX_PATTERN_ANSWER_4,
    BOARD_COMPLEX_PATTERN_ANSWER_5,
    BOARD_COMPLEX_PATTERN_ANSWER_6,
    BOARD_COMPLEX_PATTERN_ANSWER_7,
    BOARD_COMPLEX_PATTERN_ANSWER_8,
    BOARD_COMPLEX_PATTERN_ANSWER_9,
    BOARD_COMPLEX_PATTERN_ANSWER_10,
    BOARD_COMPLEX_PATTERN_ANSWER_11,
    BOARD_COMPLEX_PATTERN_ANSWER_12
};

void createMap(std::string file, std::vector<std::vector<int>> board, int size)
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

Test(ComplexPatterns, test_complex_patterns1, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 0;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern1.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns2, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 1;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern2.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns3, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 2;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern3.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns4, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 3;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern4.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns5, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 4;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern5.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns6, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 5;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern6.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns7, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 6;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern7.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns8, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 7;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern8.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns9, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 8;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern9.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns10, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 9;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern10.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns11, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 10;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern11.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}

Test(ComplexPatterns, test_complex_patterns12, .timeout = 5, .init = redirect_all_std_complex_pattern)
{
    Parser parser;
    GameRules gameRules;
    int i = 11;

    Map map;
    int size = boards[i].size();
    map.createMap(size);
    std::string path = "test_complex_pattern12.txt";
    createMap(path, boards[i], size);
    FILE *input_redirected = freopen(path.c_str(), "r", stdin);
    if (!input_redirected)
        cr_assert_fail("Failed to redirect stdin to file");
    parser.parseCommand("BOARD", map, gameRules);
    fclose(input_redirected);
    remove(path.c_str());
    cr_assert_stdout_eq_str(answers[i].c_str());
}
