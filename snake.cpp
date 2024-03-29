#include "snake.h"

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


Snake::Snake() {
	this->length = 0;
	this->head = nullptr;
}

Snake::Snake(int x, int y, int type) {
	this->length = 1;
	this->head = new Node(x, y, type);

	if (this->head == nullptr)
		throw "created an empty snake->";
}

Snake::~Snake() {
	Node* curr = head;
	Node* next;

	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
}

int Snake::getLength() {
	return this->length;
}

Node* Snake::getHead() {
	return this->head;
}

void Snake::incrementLength() {
	this->length++;
}

void Snake::prepend(Node* aNode) {
	Node* temp = head;
	this->head = aNode;
	aNode->next = temp;
}
