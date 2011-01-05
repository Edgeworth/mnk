#include <cstring>
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include "ai.hpp"

int bestR, bestC, D;

int h() {
	int total = 0;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (b[r][c] == 0) continue;

			for (int i = 0; i < 4; ++i) {
				int len = count(r, c, i);
				total += b[r][c]*len*len;
			}
		}
	}
	return total;
}

struct Node {
	Node() : score(0), r(0), c(0) {}
	Node(int _score, int _r, int _c) : score(_score), r(_r), c(_c) {}
	int score, r, c;
	bool operator<(const Node& n) const {return score<n.score;}
};

int negamax(int colour, int alpha, int beta, int depth) {
	if (fill == N*N) return 0;
	if (depth == D) return (h()+D-depth)*colour;

	int value;
	std::priority_queue<Node> negascout;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (b[r][c] != 0) continue;
			negascout.push(Node(sumadj(r, c), r, c));
		}
	}

	while (!negascout.empty()) {
		int r = negascout.top().r, c = negascout.top().c;
		negascout.pop();

		b[r][c] = colour;
		++fill;
		if (maxlen(r, c) >= K) value = 1000+D-depth;
		else value = -negamax(-colour, -beta, -alpha, depth+1);
		b[r][c] = 0;
		--fill;

		if (value > alpha && depth == 0) {
			bestR = r; bestC = c;
		}

		alpha = std::max(alpha, value);
		if (alpha >= beta) return alpha;
	}
	if (depth == 0) ++fill;
	return alpha;
}
