#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<vector>

using namespace std;


class Node
{
public:
	Node(int);
	Node(int, int);
	Node(int, Node*);
	~Node();

	void addChild(Node* child);
	vector<Node*> getChildren();
	int getData();
	bool isChecked();
	void setCheking(bool);
	int getLevel();
	void setLevel(int);
	void printChilds();
	void printNode();

private:
	vector<Node*> children;
	int data;
	bool check;
	int level;
	Node* parent;
};

#endif