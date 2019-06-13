#ifndef FIELD_H
#define FIELD_H

#include "snake.h"
#include <cstdlib>
#include <ctime>

#define N 500
// #define Ntypes 5 0 = empty, 1 = snake/fruit, 2 = no collision, etc...

class Field {

private:
	Snake snake;
	int x, y;
	int direction;
	int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // [up, down, left, right]
	bool collision;
	bool modulo;

	int field[N][N];

public:
	Field();
	~Field();

	void setDirection(int d); // Call on key press

	void updateSnake(); // For when snake moves
	void updateField(); // For updating field after snake moves

	void spawn();
	void consume(Node* item);

};

#endif
