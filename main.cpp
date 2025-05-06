#include <iostream>
#include <cstdlib> 
#include "alpha_beta.h"
#include "mcts.h"
#include "board.h"

int main() {
    Common::Board board;
    int row, col;

    while (true) {
        #if defined(_WIN32) || defined(_WIN64)
            system("cls");
        #else
            system("clear");
        #endif
        
        board.print(false);  // 使用 Unicode 打印
        std::cout << "\n输入落子位置 (row col): ";
        std::cin >> row >> col;
        if (!board.placeStone(row, col)) {
            std::cout << "非法落子，请重试。\n";
        }
    }

    return 0;
}