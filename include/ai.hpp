#ifndef AI_HPP_
#define AI_HPP_
#include "board.hpp"

extern int bestR, bestC, D;
int negamax(int colour, int alpha = -1000000000, int beta = 1000000000, int depth = 0);
#endif
