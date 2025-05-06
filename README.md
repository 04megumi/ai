# 五子棋 AI 项目 (Gomoku AI Project)

本项目实现了两种基于经典算法的五子棋 AI 模型：  
This project implements two Gomoku AI models based on classic algorithms:

1. **Alpha-Beta Pruning AI** (Alpha-Beta 剪枝 AI)  
2. **Monte Carlo Tree Search (MCTS) AI** (蒙特卡罗树搜索 AI)

## 模块介绍 (Module Introduction)

### 1. Alpha-Beta Pruning AI (Alpha-Beta 剪枝 AI)

This module implements the Alpha-Beta Pruning algorithm to improve the efficiency of the minimax search in the game of Gomoku. It helps the AI make decisions by pruning irrelevant branches of the game tree.  
此模块实现了 Alpha-Beta 剪枝算法，以提高在五子棋游戏中 minimax 搜索的效率。它通过剪除游戏树中无关的分支，帮助 AI 做出决策。

### 2. Monte Carlo Tree Search (MCTS) AI (蒙特卡罗树搜索 AI)

The MCTS module uses Monte Carlo Tree Search (MCTS) to simulate random game scenarios and determine the best move for the AI. It explores possible moves and selects the most promising one based on simulated outcomes.  
MCTS 模块使用蒙特卡罗树搜索（MCTS）来模拟随机游戏场景，并为 AI 确定最佳走法。它通过模拟结果来探索可能的走法，并选择最有前景的走法。

### 3. Common Module (公共模块)

The `Common` module contains shared utilities and classes, such as the `Board` class which is used to represent the game state and display the board.  
`Common` 模块包含了共享的工具和类，例如用于表示游戏状态和显示棋盘的 `Board` 类。

## 如何构建 (How to Build)

### 构建步骤 (Build Steps)

1. 确保你的系统上安装了 CMake 和 C++ 编译器。  
   Make sure CMake and a C++ compiler are installed on your system.

2. 在项目根目录下创建一个 `build` 目录并进入该目录：  
   Create a `build` directory in the root project directory and navigate to it:

   ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ./main_executable
    ```