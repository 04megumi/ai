#ifndef COMMON_POINT_STATE_H
#define COMMON_POINT_STATE_H
#include <cstdint>

namespace Common {

    /**
     * @class PointState
     * @brief 表示棋子状态
     */
    enum class PointState : uint8_t {
        EMPTY = 0, 
        BLACK = 1, 
        WHITE = 2
    };

}

#endif