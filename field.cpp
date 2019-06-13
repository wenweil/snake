#include "field.h"

Field::Field() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = 0;
		}
	}

	this->x = rand() % N;
	this->y = rand() % N;
	this->snake = Snake(this->x, this->y, 1);
	this->direction = rand() % 4;
	this->collision = true;
	this->modulo = false;

	field[x][y] = 1;
}

Field::~Field() {

}

void Field::setDirection(int d) {
	this->direction = d;
}

void Field::updateSnake() {
	Node* curr = snake.getHead();
	int x, y, temp_x, temp_y, new_x, new_y;

	x = curr->getX();
	y = curr->getY();
	new_x = x + d[direction][0];
	new_y = y + d[direction][1];
	curr->setLocation(new_x, new_y);

	curr = curr->next;
	while (curr != nullptr) {
		temp_x = curr->getX();
		temp_y = curr->getY();
		curr->setLocation(x, y);
		x = temp_x;
		y = temp_y;
		curr = curr->next;
	}
}

void Field::updateField() {
	Node* curr = snake.getHead();
	int x, y;

	while (curr != nullptr) {
		x = curr->getX();
		y = curr->getY();

		field[x][y] = 1;
		curr = curr->next;
	}
}

void Field::spawn() {
	// Spawn a weighted random item on the ground.
}

void Field::consume(Node* item) {
	if (item == nullptr)
		throw "consume() cannot take nullptr item.";
	
	int type = item->getType();

	switch(type) {

		case 1:
			snake.prepend(item);
			snake.incrementLength();

		case 2:
			this->collision = false;

		case 3:
			this->modulo = true;

	}
}
