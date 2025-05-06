---

## ✅ `MCTS/README.md`

```markdown
# MCTS Module (MCTS 模块)

This module implements the Monte Carlo Tree Search (MCTS) algorithm for decision-making in the game of Go (Gomoku). MCTS is a probabilistic method used for exploring possible moves and selecting the best one based on simulations.  
本模块实现了蒙特卡罗树搜索（MCTS）算法，用于在五子棋游戏中做出决策。MCTS 是一种概率方法，用于探索可能的走法并根据模拟选择最佳走法。

## Key Features (主要特点)

- Implements the MCTS algorithm to simulate random games and determine the best move.  
  实现了 MCTS 算法，通过模拟随机游戏来确定最佳走法。
- Works by expanding the game tree, simulating multiple playthroughs (rollouts), and selecting the best outcome.  
  通过扩展游戏树，模拟多次游戏过程（回合模拟），并选择最佳结果。
- Efficiently handles large search spaces by narrowing down possible moves based on random exploration.  
  通过基于随机探索缩小可能的走法范围，有效处理大规模搜索空间。