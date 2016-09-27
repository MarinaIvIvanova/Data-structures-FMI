#ifndef AllPathsFinder_h
#define AllPathsFinder_h

#include<iostream>
#include<stack>
#include<vector>
#include "Node.h"

using namespace std;

class AllPathsFinder
{
public:
	AllPathsFinder(Node** matrix, int rows, int cols);
	~AllPathsFinder();

	void dfs(Node current);

	void setTarget(Node target);
	void setStartNode(Node start);
	void deleteAllPaths();

	vector<Node> getAllAvailableNodes();
	vector<Node> getPath();
	vector<vector<Node>> getAllPaths();

	vector<vector<Node>> sortPaths();

	bool contains(vector<Node> path, Node node);


private:
	Node** matrix;
	int rows;
	int cols;
	Node target;
	vector<vector<Node>> allPaths;
	vector<Node> allAvailableNodes;
	vector<Node> path;

};


#endif