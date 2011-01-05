#include "board.hpp"

int N, K, fill;
int b[MAX_N][MAX_N];
int dirs[8][2] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}};


int len(int sr, int sc, int d) {
	int total = 0;
	int r = sr, c = sc;
	while (r >= 0 && r < N && c >= 0 && c < N && b[r][c] == b[sr][sc]) {
		++total;
		r += dirs[d][0];
		c += dirs[d][1];
	}
	return total;
}

int sumadj(int sr, int sc) {
	int sum = 0;
	for (int i = 0; i < 8; ++i)
		sum += (b[sr+dirs[i][0]][sc+dirs[i][1]] != 0 ? len(sr+dirs[i][0], sc+dirs[i][1], i) : 0);
	return sum;
}

int maxlen(int sr, int sc) {
	int max = -1000000000;
	for (int i = 0; i < 4; ++i) {
		int val = len(sr, sc, i)+len(sr, sc, i+4)-1;
		if (val > max) max = val;
	}
	return max;
}

int count(int sr, int sc, int d) {
	int total = 0, moves = 0;
	int r = sr, c = sc;
	while (moves < K-1) {
		if (r < 0 || r >= N || c < 0 || c >= N || b[r][c] == -b[sr][sc]) return 0;
		if (b[r][c] == b[sr][sc]) ++total;
		++moves;
		r += dirs[d][0];
		c += dirs[d][1];
	}
	return total;
}

bool won(int colour) {
	for (int r = 0; r < N; ++r)
		for (int c = 0; c < N; ++c)
			if (b[r][c] == colour && maxlen(r, c) >= K) return true;
	return false;
}

bool done() {
	for (int r = 0; r < N; ++r)
		for (int c = 0; c < N; ++c)
			if (b[r][c] == 0) return false;
	return true;
}
