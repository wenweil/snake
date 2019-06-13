#include "field.h"

Field::Field() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = 0;
		}
	}

	this.x = rand() % N;
	this.y = rand() % N;
	this.snake = Snake(this.x, this.y, 1);
	this.direction = rand() % 4;
	this.collision = true;

	field[x][y] = 1;
}

Field::~Field() {

}

void Field::spawn() {
	// Spawn a weighted random item on the ground.
}

void Field::consume(Node* item) {
	if (item == nullptr)
		throw "consume() cannot take nullptr item.";
	
	int type = item->type;

	switch(type) {
		case 1:
			snake.prepend(item);
			snake.incrementLength();
	}
}
