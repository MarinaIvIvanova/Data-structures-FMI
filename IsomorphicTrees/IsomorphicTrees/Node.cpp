#include "Node.h"


Node::Node(int data)
{
	this->data = data;
	this->check = false;
	this->level = 0;
}

Node::Node(int data, int level)
{
	this->data = data;
	this->level = level;
}

Node::Node(int data, Node* parent)
{
	this->data = data;
	this->parent = parent;
	this->check = false;
	this->level = 0;

}

Node::~Node(void)
{
}


bool Node::isChecked()
{
	return this->check;
}

void Node::setCheking(bool check)
{
	this->check = check;
}

vector<Node*> Node::getChildren()
{
	return this->children;
}

void Node::addChild(Node* child)
{
	this->children.push_back(child);
}

int Node::getData()
{
	return this->data;
}

int Node::getLevel()
{
	return this->level;
}

void Node::setLevel(int level)
{
	this->level = level;
}

void Node::printChilds()
{
	std::vector<Node*>::iterator iter;

	for (iter = children.begin(); iter != children.end(); ++iter)
	{
		Node* node = *iter;
		cout << node->data << endl;
	}
	std::cout << std::endl;
}

void Node::printNode()
{
	cout << this->data << ' ';
}

