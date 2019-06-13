#include "snake.h"

Node::Node() {
	this.type = 0;
	this.x = 0;
	this.y = 0;

	this.next = nullptr;
}

Node::Node(int x, int y, int type) {
	this.type = type;
	this.x = x;
	this.y = y;

	this.next = nullptr;
}

Node::~Node() {

}

void Node::setLocation(int new_x, int new_y) {
	this.x = new_x;
	this.y = new_y;
}


Snake::Snake() {
	this.length = 0;
	this.head = nullptr;
}

Snake::Snake(int x, int y, int type) {
	this.length = 1;
	this.head = new Node(x, y, type);

	if (this.head == nullptr)
		throw "created an empty snake.";
}

Snake::~Snake() {
	Node* curr = head;
	Node* next;

	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next
	}
}

int Snake::getLength() {
	return this.length;
}

void Snake::incrementLength() {
	this.length++;
}

void Snake::prepend(Node* aNode) {
	Node* temp = head;
	this.head = aNode;
	aNode->next = temp;
}

void Snake::consume(Node* aNode) {
	if (aNode == nullptr)
		throw "consume() cannot take nullptr aNode.";

	int type = aNode->type;
	switch (type) {

		case 0:
			prepend(aNode);
			incrementLength();
			break;
	}
}
