#include <GL/gl.h>
#include "draw.hpp"
#include "board.hpp"

void drawBoard() {
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (b[r][c] == 0) continue;
			if (b[r][c] == MINE) glColor3f(1.0, 0.6, 0.6);
			else glColor3f(0.6, 0.6, 1.0);
			glRectf(float(c)/N, (1-float(r+1)/N), float(c+1)/N, (1-float(r)/N));
		}
	}
	glColor3f(0.0, 0.0, 0.0);
	for (float i = 0; i <= 1.0; i += 1/float(N)) {
		glBegin(GL_LINES);
			glVertex2f(i, 0.0);
			glVertex2f(i, 1.0);
			glVertex2f(0.0, i);
			glVertex2f(1.0, i);
		glEnd();
	}
}
