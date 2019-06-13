#ifndef SNAKE_H
#define SNAKE_H

#include <cstdlib>

#define N 500
// #define Ntypes 5 0 = empty, 1 = snake/fruit, 2 = powerup, etc...

class Node {

private:
	int type;
	int x, y;

	Node* next;

public:
	Node();
	Node(int x, int y, int type);
	~Node();

	void setLocation(int new_x, int new_y);

};

class Snake {

private:
	int length;
	Node* head;

public:
	Snake();
	Snake(int x, int y, int type);
	~Snake();

	int getLength();
	void incrementLength();

	void prepend(Node* aNode);
	void consume(Node* aNode);

};

#endif
