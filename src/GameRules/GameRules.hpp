/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** GameRules
*/

#include <string>
#include <iostream>

#pragma once

class GameRules {

    public:

        GameRules(void);

        /**
         * @brief Get the Timeout Turn object.
         *
         * @return int Timeout of the trun.
         */
        int getTimeoutTurn(void) const;

        /**
         * @brief Get the Timeout Match object.
         *
         * @return int of the match.
         */
        int getTimeoutMatch(void) const;

        /**
         * @brief Get the Max Memory object
         *
         * @return int Max autorized to play.
         */
        int getMaxMemory(void) const;

        /**
         * @brief Get the Time Left object.
         *
         * @return int Time left.
         */
        int getTimeLeft(void) const;

        /**
         * @brief Get the Game Type object.
         *
         * @return int What Game we play.
         */
        int getGameType(void) const;

        /**
         * @brief Get the Rule object.
         *
         * @return int Rules of the game.
         */
        int getRule(void) const;

        /**
         * @brief Get the Evaluate object.
         *
         * @return int Evaluation.
         */
        int getEvaluate(void) const;

        /**
         * @brief Get the Folder object.
         *
         * @return int Number of file.
         */
        int getFolder(void) const;

        /**
         * @brief Set the Timeout Turn object.
         *
         * @param timeoutTurn New timeout turn.
         */
        void setTimeoutTurn(int timeoutTurn);

        /**
         * @brief Set the Timeout Match object.
         *
         * @param timeoutMatch New timeout match.
         */
        void setTimeoutMatch(int timeoutMatch);

        /**
         * @brief Set the Max Memory object.
         *
         * @param maxMemory New max Memory.
         */
        void setMaxMemory(int maxMemory);

        /**
         * @brief Set the Time Left object.
         *
         * @param timeLeft New time left.
         */
        void setTimeLeft(int timeLeft);

        /**
         * @brief Set the Game Type object.
         *
         * @param gameType New game type.
         */
        void setGameType(int gameType);

        /**
         * @brief Set the Rule object.
         *
         * @param rule New rule.
         */
        void setRule(int rule);

        /**
         * @brief Set the Evaluate object.
         *
         * @param evaluate New evaluation.
         */
        void setEvaluate(int evaluate);

        /**
         * @brief Set the Folder object.
         *
         * @param folder New folder.
         */
        void setFolder(int folder);

    private:
        std::size_t _timeoutTurn;
        std::size_t _timeoutMatch;
        std::size_t _maxMemory;
        std::size_t _timeLeft;
        std::size_t _gameType;
        std::size_t _rule;
        std::size_t _evaluate;
        std::size_t _folder;
};