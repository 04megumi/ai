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
        checkIsGameOver(row, col);
        is_black_turn_ = !is_black_turn_;
        return true;
    }

    void Board::print(bool use_unicode) {
        std::cout << "  ";
        for (int i = 0; i < BOARD_SIZE; i++)
            std::cout << std::setw(3) << i;
        for (int i = 0; i < BOARD_SIZE; i++) {
            std::cout << std::endl << std::setw(2) << i << " ";
            unsigned char w = use_unicode ? 4 : 3;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (grid_[i][j] == PointState::EMPTY)
                    std::cout << std::setw(w) << (use_unicode ? "· " : "  ");
                else if (grid_[i][j] == PointState::BLACK)
                    std::cout << std::setw(w) << (use_unicode ? " ⚫" : "B ");
                else if (grid_[i][j] == PointState::WHITE)
                    std::cout << std::setw(w) << (use_unicode ? " ⚪" : "W ");
            }
        }
    }

    void Board::checkIsGameOver(int row, int col) {
        unsigned char dx=0, dy=0, count=1;
        for(int i=0;i<4;i++) {
            int rt = row, ct = col;
            dx = i%2, dy=i/2, count=1;
            if(!dx&&!dy) { dx=-1, dy=1; }
            while(rt+dx>=0&&ct+dy>=0&&rt+dx<BOARD_SIZE&&ct+dy<BOARD_SIZE&&grid_[rt+dx][ct+dy]==(is_black_turn_?PointState::BLACK:PointState::WHITE)) { count++;rt+=dx,ct+=dy; }
            rt = row, ct = col, dx=-dx, dy=-dy;
            while(rt+dx>=0&&ct+dy>=0&&rt+dx<BOARD_SIZE&&ct+dy<BOARD_SIZE&&grid_[rt+dx][ct+dy]==(is_black_turn_?PointState::BLACK:PointState::WHITE)) { count++;rt+=dx,ct+=dy; }
            if(count==5) { game_over_ = true, is_black_win_ = is_black_turn_; break;}
        }
    }
}