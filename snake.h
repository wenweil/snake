#ifndef SNAKE_H
#define SNAKE_H

#include <cstdlib>
#include "node.h"

#define N 500
// #define Ntypes 5 0 = empty, 1 = snake/fruit, 2 = no collision, etc...



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
