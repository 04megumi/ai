#include <iostream>
#include "alpha_beta.h"
#include "mcts.h"
#include "board.h"

int main() {
    std::cout << "MAIN MODULE START\n";

    Common::Board board;
    board.print();

    AlphaBeta::test();
    MCTS::test();

    return 0;
}