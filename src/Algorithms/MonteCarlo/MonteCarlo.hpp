/*
** EPITECH PROJECT, 2024
** Gomoku
** File description:
** Monte Carlo
*/

#pragma once
#include <Map.hpp>

class MonteCarlo {

    public:
        /**
         * @brief Construct a new Monte Carlo object.
         *
         */
        MonteCarlo();

        /**
         * @brief Destroy the Monte Carlo object.
         *
         */
        ~MonteCarlo();

        /**
         * @brief Compute the best move to play.
         *
         * @param map Map to play.
         * @return std::pair<int, int> Best move to play.
         */
        std::pair<int, int> compute(Map map);
};
