#include <vector>
#include "AllPathsFinder.h"
#include<algorithm>

AllPathsFinder::AllPathsFinder(Node** matrix, int rows, int cols)
{
	this->matrix = matrix;
	this->rows = rows;
	this->cols = cols;
}

AllPathsFinder::~AllPathsFinder()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->matrix[i];
	}

	delete[] matrix;
}


void AllPathsFinder::setTarget(Node target)
{
	this->target = target;
}

void AllPathsFinder::setStartNode(Node start)
{
	this->path.push_back(start);
}

void AllPathsFinder::deleteAllPaths()
{
	this->allPaths.clear();
}

vector<Node> AllPathsFinder::getAllAvailableNodes()
{
	return this->allAvailableNodes;
}

vector<Node> AllPathsFinder::getPath()
{
	return this->path;
}

vector<vector<Node>> AllPathsFinder::getAllPaths()
{
	return this->allPaths;
}

vector<vector<Node>> AllPathsFinder::sortPaths()
{
	for (int i = 0; i < this->allPaths.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < this->allPaths.size(); j++)
		{
			if (allPaths[j].size() < allPaths[min].size())
			{
				min = j;
			}
		}

		if (min != i)
		{
			swap(allPaths[i], allPaths[min]);
		}
	}

	return this->allPaths;
}




bool AllPathsFinder::contains(vector<Node> path, Node node)
{
	vector<Node>::iterator it;
	for (it = path.begin(); it != path.end(); it++)
	{
		if (*it == node)
		{
			return true;
		}
	}
	return false;
}


void AllPathsFinder::dfs(Node current)
{
	int dirs[4][2] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

	for (int i = 0; i < 4; i++)
	{
		int tempX = dirs[i][0] + current.getX();
		int tempY = dirs[i][1] + current.getY();
		if (tempX >= 0 && tempX < rows && tempY < cols && tempY >= 0 && matrix[tempX][tempY].getValue() == '.')
		{
			Node nextNode = matrix[tempX][tempY];

			int i;
			if (nextNode == target)
			{
				vector<Node> temp;
				for (i = 0; i < path.size(); i++)
				{
					temp.push_back(path[i]);
				}
				temp.push_back(nextNode);
				allPaths.push_back(temp);
				temp.pop_back();
			}
			else if (!(contains(path, nextNode)))
			{
				path.push_back(nextNode);
				dfs(nextNode);
				path.pop_back();

			}


		}
	}
}






