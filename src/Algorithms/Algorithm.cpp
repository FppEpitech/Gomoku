#include "Algorithms/Algorithm.hpp"
#include "Map/Map.hpp"

std::vector<std::pair<int, int>> Algorithm::getValidMoves(int radius) {
    std::set<std::pair<int, int>> candidates;

    for (std::size_t x = 0; x < _size; ++x) {
        for (std::size_t y = 0; y < _size; ++y) {
            if (_map[x][y].getValue() != CellValue::NONE) {
                for (int dx = -radius; dx <= radius; ++dx) {
                    for (int dy = -radius; dy <= radius; ++dy) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < (int)_size && ny >= 0 && ny < (int)_size && _map[nx][ny].getValue() == CellValue::NONE) {
                            candidates.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }
    return std::vector<std::pair<int, int>>(candidates.begin(), candidates.end());
}
