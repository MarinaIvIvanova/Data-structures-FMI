#include "Node.h"


Node::Node()
{
	this->value = ' ';
	this->x = 0;
	this->y = 0;
}

Node::Node(int x, int y, char value)
{

	this->value = value;
	this->x = x;
	this->y = y;

}

Node::~Node()
{

}

bool Node::operator==(Node &ob)
{
	return this->value == ob.value && this->x == ob.x && this->y == ob.y;
}

Node &Node::operator=(Node &ob)
{
	if (this != &ob)
	{
		this->value = ob.value;
		this->x = ob.x;
		this->y = ob.y;
	}

	return *this;
}




int Node::getX()
{
	return this->x;
}

int Node::getY()
{
	return this->y;
}

char Node::getValue()
{
	return this->value;
}

bool Node::getVisited()
{
	return this->visited;
}

void Node::setX(int x)
{
	this->x = x;
}

void Node::setY(int y)
{
	this->y = y;
}

void Node::setValue(char value)
{
	this->value = value;
}

void Node::setVisited(bool visited)
{
	this->visited = visited;
}

bool Node::isTarget(Node* current)
{
	return this->x == current->getX() && this->y == current->getY();
}


void Node::printNode()
{
	cout << this->x << ' ' << this->y << ' ' << this->value << endl;
}



