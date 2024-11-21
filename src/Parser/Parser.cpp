/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Parser
*/

#include "Parser.hpp"
#include <future>
#include <fstream>

void Parser::_handleStart(std::size_t size, Map& map)
{
    if (size != 20) {
        std::cout << "ERROR size is not 20" << std::endl;
    } else {
        map.setSize(size);
        map.createMap(size);
        std::cout << "OK" << std::endl;

        std::ofstream file("output.log", std::ios_base::app);
        if (file.is_open()) {
            file << "Map created:" << std::endl;
        } else {
            std::cerr << "Unable to open output.log" << std::endl;
        }
        file.close();
        map.displayMap();
    }
}

void Parser::_handleTurn(std::size_t x, std::size_t y, Map& map, int timeout)
{
    std::vector<std::vector<Cell>> &playGround = map.getMap();

    if (playGround.size() == 0)
        return;
    playGround[x][y].setValue(CellValue::PLAYER2);
    auto future = std::async(std::launch::async, [&]() { map.play(); });
    if (future.wait_for(std::chrono::milliseconds(timeout - 1000)) == std::future_status::timeout) {
        map.shouldStop = true;
        std::cout << 5 << "," << 5 << std::endl;
        std::ofstream("o.log", std::ios_base::app) << "5,5" << std::endl;
        map.getMap()[5][5].setValue(CellValue::PLAYER1);
    }
    // map.play();
}

void Parser::_handleBegin(Map& map)
{
    std::ofstream file("output.log", std::ios_base::app);
    if (file.is_open())
        file << "BEGIN move : " << MIDDLE_X << "," << MIDDLE_Y << std::endl;
    file.close();
    std::cout << MIDDLE_X << "," << MIDDLE_Y << std::endl;

    std::vector<std::vector<Cell>> &playGround = map.getMap();
    playGround[MIDDLE_X][MIDDLE_Y].setValue(CellValue::PLAYER1);
}

void Parser::_handleBoard(Map& map)
{
    std::string line;
    std::vector<std::vector<Cell>>& playGround = map.getMap();

    while (true) {
        std::getline(std::cin, line);

        if (line == "DONE")
            break;

        try {
            std::istringstream iss(line);
            std::string x_str, y_str, field_str;

            if (!std::getline(iss, x_str, ',') || !std::getline(iss, y_str, ',') || !std::getline(iss, field_str))
                throw std::invalid_argument("Invalid format.");

            int x = std::stoi(x_str);
            int y = std::stoi(y_str);
            int field = std::stoi(field_str);

            CellValue cell_value = CellValue::NONE;
            if (field == 1)
                cell_value = CellValue::PLAYER1;
            else if (field == 2)
                cell_value = CellValue::PLAYER2;
            else
                throw std::invalid_argument("Invalid data.");

            playGround[x][y].setValue(cell_value);

            std::ofstream outputFile("output.log", std::ios_base::app);
            if (outputFile.is_open()) {
                outputFile << "Case of Map [" << x << "] | [" << y << "] <- [" << field << "] Player" << std::endl;
                outputFile.close();
            }
            outputFile.close();
        } catch (const std::exception& e) {
            std::ofstream outputFile("output.log", std::ios_base::app);
            if (outputFile.is_open()) {
                outputFile << "Error in format of data : " << line << std::endl;
            }
            outputFile.close();
            continue;
        }
    }
    map.play();
}

void Parser::_handleInfo(std::string key, std::size_t value, GameRules& rules)
{
    static const std::map<std::string, void (GameRules::*)(int)> keyMapping = {
        {"timeout_match", &GameRules::setTimeoutMatch},
        {"timeout_turn", &GameRules::setTimeoutTurn},
        {"max_memory", &GameRules::setMaxMemory},
        {"time_left", &GameRules::setTimeLeft},
        {"game_type", &GameRules::setGameType},
        {"rule", &GameRules::setRule}
    };

    auto it = keyMapping.find(key);
    if (it != keyMapping.end())
        (rules.*(it->second))(value);
}

void Parser::_handleEnd(void)
{
    std::exit(0);
}

void Parser::_handleAbout(void)
{
    std::cout << "name=\"SomeBrain\", version=\"1.0\", author=\"FPP\", country=\"FR\"" << std::endl;
}

bool Parser::parseCommand(std::string command, Map& map, GameRules& rules)
{
    (void) rules;
    std::istringstream ss(command);
    std::string cmd;
    ss >> cmd;

    for (auto& charactere : cmd)
        charactere = std::toupper(charactere);

    std::ofstream log_file("output.log", std::ios::app);
    std::string cleaned_command = command;
    cleaned_command.erase(std::remove(cleaned_command.begin(), cleaned_command.end(), '\r'), cleaned_command.end());
    log_file << "\nCurrent command: [" << cleaned_command << "]\n";
    log_file.close();
    map.shouldStop = false;

    if (cmd == "START") {
        std::vector<std::string> parts;
        std::string part;
        while (ss >> part)
            parts.push_back(part);

        if (parts.size() == 1)
            _handleStart(std::stoi(parts[0]), map);
    } else if (cmd == "TURN") {
        std::vector<std::string> parts;
        std::string part;
        while (ss >> part)
            parts.push_back(part);

        if (parts.size() == 1) {
            std::istringstream ss(parts[0]);
            std::size_t x, y;
            char delimiter;
            ss >> x >> delimiter >> y;
            _handleTurn(x, y, map, rules.getTimeoutTurn());
        }
    } else if (cmd == "BEGIN") {
        _handleBegin(map);
    } else if (cmd == "BOARD") {
        _handleBoard(map);
    } else if (cmd == "INFO") {
        std::vector<std::string> parts;
        std::string part;
        while (ss >> part)
            parts.push_back(part);

        if (parts.size() == 2) {
            _handleInfo(parts[0], std::stoi(parts[1]), rules);
        }
    } else if (cmd == "END") {
        _handleEnd();
    } else if (cmd == "ABOUT") {
        _handleAbout();
    } else {
        std::cerr << "Unrecognized command : " << cmd << "\n";
        return false;
    }

    return true;
}
