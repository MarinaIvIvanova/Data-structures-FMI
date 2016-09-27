#ifndef Node_h
#define Node_h

#include<iostream>
using namespace std;

class Node
{

public:
	Node();
	Node(int x, int y, char value);
	~Node();
	bool operator==(Node &ob);
	Node &operator=(Node &ob);

	//Node* nodeAt(int index);

	int getX();
	int getY();
	char getValue();
	bool getVisited();

	void setX(int x);
	void setY(int y);
	void setValue(char value);
	void setVisited(bool visited);

	bool isTarget(Node* current);

	void printNode();

private:
	char value;
	int x;
	int y;
	bool visited;
};

#endif

