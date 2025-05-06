#ifndef COMMON_BOARD_H
#define COMMON_BOARD_H

#include <array>
#include <iostream>
#include "point_state.h"

namespace Common {

    // 棋盘大小常量
    constexpr int BOARD_SIZE = 15;

    /**
     * @class Board
     * @brief 表示五子棋的棋盘
     */
    class Board {
    public:
        /**
         * @brief 默认初始情况，棋盘为空
         */
        Board();

        /**
         * @brief 在指定位置落子
         * @param row 行坐标
         * @param col 列坐标
         * @return 是否落子成功（true 表示成功，false 表示失败）
         */
        bool placeStone(int row, int col);

        /**
         * @brief 打印当前棋盘状态到控制台
         * @param use_unicode 是否打印 ⚫ ⚪ 
         */
        void print(bool use_unicode);

    private:
        std::array<std::array<PointState, BOARD_SIZE>, BOARD_SIZE> grid_; ///< 棋盘数据，二维数组表示每个格点状态
        bool is_black_turn_ = true; ///< 当前是否轮到黑子落子
    };

} // namespace Common

#endif // COMMON_BOARD_H