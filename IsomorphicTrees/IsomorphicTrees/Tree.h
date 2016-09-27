#ifndef TREE_H
#define TREE_H
#include<iostream>
#include "Node.h"
#include<vector>
#include<algorithm>

using namespace std;

class Tree
{
public:
	Tree();
	~Tree();

	Node* getRoot();
	void setRoot(Node*);
	void processNode(vector<Node*>&, int, Node*);
	vector<Node*> getLvlNodes(int);
	bool isExternal(Node* node);
	int getLevelsCnt(Node* node);

private:
	Node* root;
	int levelsCnt; //broq na nivata na dyrvoto

};

#endif