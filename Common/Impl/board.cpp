#include "board.h"
#include <iostream>
#include <iomanip>

namespace Common {

    Board::Board() {
        for (int i=0;i<BOARD_SIZE;i++) for (int j=0;j<BOARD_SIZE;j++) grid_[i][j] = PointState::EMPTY;
    }

    bool Board::placeStone(int row, int col) {
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) return false;
        if (grid_[row][col] != PointState::EMPTY) return false;
        grid_[row][col] = is_black_turn_ ? PointState::BLACK : PointState::WHITE;
        is_black_turn_ = !is_black_turn_;
        return true;
    }

    void Board::print(bool use_unicode)
    {
        std::cout << "   ";
        for (int i = 0; i < BOARD_SIZE; i++)
            std::cout << std::setw(2) << i;
        for (int i = 0; i < BOARD_SIZE; i++) {
            std::cout << std::endl << std::setw(2) << i << " ";
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (grid_[i][j] == PointState::EMPTY)
                    std::cout << (use_unicode ? "· " : "E ");
                else if (grid_[i][j] == PointState::BLACK)
                    std::cout << (use_unicode ? "⚫ " : "B ");
                else if (grid_[i][j] == PointState::WHITE)
                    std::cout << (use_unicode ? "⚪ " : "W ");
            }
        }
    }
}