#include <cassert>
#include <cstdio>
#include "SFML/Graphics.hpp"
#include "board.hpp"
#include "init.hpp"
#include "draw.hpp"
#include "ai.hpp"

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		printf("Usage: board size, line size (3), difficulty (4).\n");
		return 1;
	}
	sscanf(argv[1], "%d", &N);
	argc > 2 ? sscanf(argv[2], "%d", &K) : K = 3;
	argc > 3 ? sscanf(argv[3], "%d", &D) : D = 4;

	sf::RenderWindow window(sf::VideoMode(winW, winH), "m,n,k");
	init(window);

	sf::Event e; bool finished = false;
	while (window.IsOpened() && !finished) {
		while (window.GetEvent(e)) {
			if (e.Type == sf::Event::Closed) window.Close();
			if (e.Type == sf::Event::MouseButtonPressed && e.MouseButton.Button == sf::Mouse::Left) {
				float x = float(e.MouseButton.X)/winW;
				float y = float(e.MouseButton.Y)/winH;
				b[int(y*N)][int(x*N)] = THEIRS;
				++fill;
				negamax(MINE);
				if (done() || won(MINE) || won(THEIRS)) finished = true;
				b[bestR][bestC] = MINE;
				if (done() || won(MINE) || won(THEIRS)) finished = true;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		drawBoard();
		window.Display();
	}
	if (finished) sf::Sleep(1.0);
	printf( won(MINE) ? "I win.\n" : won(THEIRS) ? "You win :(\n" : "Draw.\n");
}
