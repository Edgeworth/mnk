#ifndef BOARD_HPP_
#define BOARD_HPP_

const int MAX_N = 200, MINE = 1, THEIRS = -1;
extern int N, K, fill;
extern int b[MAX_N][MAX_N];

int len(int sr, int sc, int d);
int sumadj(int sr, int sc);
int maxlen(int sr, int sc);
int count(int sr, int sc, int d);
bool won(int colour);
bool done();
#endif
