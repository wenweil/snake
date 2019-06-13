#ifndef SNAKE_H
#define SNAKE_H

#include <cstdlib>

#define N 500
// #define Ntypes 5 0 = empty, 1 = snake/fruit, 2 = no collision, etc...

class Node {

private:
	int type;
	int x, y;

public:
	Node* next;

	Node();
	Node(int x, int y, int type);
	~Node();

	int getX();
	int getY();
	int getType();
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
	Node* getHead();
	void incrementLength();

	void prepend(Node* aNode);

};

#endif
