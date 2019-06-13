#include "snake.h"

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
