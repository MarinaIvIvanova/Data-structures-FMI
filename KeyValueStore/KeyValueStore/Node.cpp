#include "Node.h"

Node::Node()
{
	this->next = NULL;
	this->content = new char[0];
	this->size = 0;
	this->id = 0;

}

Node::~Node()
{
	this->next = NULL;
	delete[] this->content;
	this->content = NULL;
	this->size = 0;
	this->id = 0;
}


Node::Node(char* content, const int size, Node* next, int id)
{
	this->next = next;
	this->content = new char[size];
	this->content = content;
	this->size = size;
	this->id = id;
}

Node& Node::operator=(Node const& obj)
{
	if (this != &obj)
	{
		this->next = obj.next;

		delete[] this->content;
		this->content = new char[obj.size + 1];
		strcpy_s(this->content, obj.size + 1, obj.content);

		this->id = obj.id;
		this->size = obj.size;
	}

	return *this;
}

Node::Node(const Node &obj)
{
	this->next = obj.next;

	delete[] this->content;
	this->content = NULL;

	if (obj.content != NULL)
	{
		this->content = new char[obj.size + 1];
		strcpy_s(this->content, obj.size + 1, obj.content);
	}

	this->id = obj.id;
	this->size = obj.size;
}

int Node::getId()
{
	return this->id;
}


void Node::setId(int id)
{
	this->id = id;
}
