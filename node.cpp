#include "node.h"

Node::Node() {
	this->type = 0;
	this->x = 0;
	this->y = 0;

	this->next = nullptr;
}

Node::Node(int x, int y, int type) {
	this->type = type;
	this->x = x;
	this->y = y;

	this->next = nullptr;
}

Node::~Node() {

}

int Node::getX() {
	return this->x;
}

int Node::getY() {
	return this->y;
}

int Node::getType() {
	return this->type;
}

void Node::setLocation(int new_x, int new_y) {
	this->x = new_x;
	this->y = new_y;
}

