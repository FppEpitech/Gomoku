/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** GameRules
*/

#include "GameRules.hpp"

GameRules::GameRules(void)
{
    _timeoutTurn = 0;
    _timeoutMatch = 0;
    _maxMemory = 0;
    _timeLeft = 0;
    _gameType = 0;
    _rule = 0;
    _evaluate = 0;
    _folder = 0;
}

int GameRules::getTimeoutTurn(void) const
{
    return _timeoutTurn;
}

int GameRules::getTimeoutMatch(void) const
{
    return _timeoutMatch;
}

int GameRules::getMaxMemory(void) const
{
    return _maxMemory;
}

int GameRules::getTimeLeft(void) const
{
    return _timeLeft;
}

int GameRules::getGameType(void) const
{
    return _gameType;
}

int GameRules::getRule(void) const
{
    return _rule;
}

int GameRules::getEvaluate(void) const
{
    return _evaluate;
}

int GameRules::getFolder(void) const
{
    return _folder;
}

void GameRules::setTimeoutTurn(int timeoutTurn)
{
    _timeoutTurn = timeoutTurn;
}

void GameRules::setTimeoutMatch(int timeoutMatch)
{
    _timeoutMatch = timeoutMatch;
}

void GameRules::setMaxMemory(int maxMemory)
{
    _maxMemory = maxMemory;
}

void GameRules::setTimeLeft(int timeLeft)
{
    _timeLeft = timeLeft;
}

void GameRules::setGameType(int gameType)
{
    _gameType = gameType;
}

void GameRules::setRule(int rule)
{
    _rule = rule;
}

void GameRules::setEvaluate(int evaluate)
{
    _evaluate = evaluate;
}

void GameRules::setFolder(int folder)
{
    _folder = folder;
}
