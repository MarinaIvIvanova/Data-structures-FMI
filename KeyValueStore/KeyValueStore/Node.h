#ifndef Node_h
#define Node_h

#include<iostream>
using namespace std;

class Node
{
public:

	Node();
	Node(char* content, const int size, Node* next, int id);
	~Node();
	Node& operator=(Node const&);
	Node(const Node &);

	int getId();

	void setId(int id);

public:
	Node* next;
	char* content;
	int size;
	int id;
};



#endif