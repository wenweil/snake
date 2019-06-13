#ifndef FIELD_H
#define FIELD_H

#include "snake.h"
#include <cstdlib>
#include <ctime>

#define N 500
// #define Ntypes 5 0 = empty, 1 = snake/fruit, 2 = powerup, etc...

class Field {

private:
	Snake snake;
	int x, y;
	int direction; // 4 directions, haven't decided which is which
	bool collision;

	int field[N][N];

public:
	Field();
	~Field();

	void spawn();
	void consume(Node* item);

};

#endif
