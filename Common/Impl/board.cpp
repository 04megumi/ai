#include "board.h"
#include <iostream>
#include <iomanip>
#include <cstdlib> 

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
        const PointState curr = is_black_turn_ ? PointState::BLACK : PointState::WHITE;
        const int directions[4][2] = {
            {1, 0},   // →
            {0, 1},   // ↓
            {1, 1},   // ↘
            {1, -1}   // ↗
        };
        for (auto& dir : directions) {
            int dx = dir[0], dy = dir[1];
            int count = 1;
            int x = row + dx, y = col + dy;
            while (x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE && grid_[x][y] == curr) {
                count++;
                x += dx;
                y += dy;
            }
            x = row - dx;
            y = col - dy;
            while (x >= 0 && y >= 0 && x < BOARD_SIZE && y < BOARD_SIZE && grid_[x][y] == curr) {
                count++;
                x -= dx;
                y -= dy;
            }
            if (count >= 5) {
                game_over_ = true;
                is_black_win_ = is_black_turn_;
                break;
            }
        }
    }
    
    void Board::play(int mode) {
        int row, col;
        while(!game_over_) {
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");
            #else
                system("clear");
            #endif
            this->print(mode==1);
            std::cout << "\n轮到: " << (is_black_turn_?"⚫ ":"⚪ ") << "输入落子位置 (row col): ";
            std::cin >> row >> col;
            if (!placeStone(row, col)) std::cout << "非法落子，请重试。\n";
        }
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #else
            system("clear");
        #endif
        this->print(true);
        std::cout << std::endl << "游戏结束::获胜方::" << (isBlackWin()?"黑方":"白方") << std::endl;
    }
}