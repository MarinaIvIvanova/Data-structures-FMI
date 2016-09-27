#include<iostream>
#include<list>
#include "Node.h"
#include "AllPathsFinder.h"

using namespace std;

int main()
{

	int N, M;
	cout << "Add M: ";
	cin >> M;
	cout << "Add N: ";
	cin >> N;

	Node** matrix = new Node*[M];
	for (int i = 0; i < M; i++)
	{
		matrix[i] = new Node[N];
	}

	AllPathsFinder findPaths(matrix, M, N);
	vector<Node> allAvailableNodes = findPaths.getAllAvailableNodes();
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N; col++)
		{
			char value;
			cout << "matrix[" << row << "][" << col << "] = ";
			cin >> value;

			matrix[row][col].setX(row);
			matrix[row][col].setY(col);
			matrix[row][col].setValue(value);

			if (value == '.')
			{
				allAvailableNodes.push_back(matrix[row][col]);
			}
		}
	}

	for (int i = 0; i < allAvailableNodes.size(); i++)
	{
		cout << allAvailableNodes[i].getX() << " " << allAvailableNodes[i].getY() << endl;
	}

	int startX;
	int startY;
	cout << "Add startX and startY: ";
	cin >> startX >> startY;

	Node start(startX, startY, '.');
	findPaths.setStartNode(start);
	vector<Node>::iterator it;
	for (it = allAvailableNodes.begin(); it != allAvailableNodes.end(); it++)
	{
		if (!(*it == start))
		{

			cout << "(" << it->getX() << "," << it->getY() << ")" << endl;
			findPaths.setTarget(*it);
			findPaths.dfs(start);

			auto allPaths = findPaths.sortPaths();

			int i, j;
			for (i = 0; i < allPaths.size(); i++)
			{
				for (j = 0; j < allPaths[i].size(); j++)
				{
					cout << "(" << allPaths[i][j].getX() << "," << allPaths[i][j].getY() << ")" << " ";
				}
				cout << endl;

			}
		}

		findPaths.deleteAllPaths();

	}

	return 0;
}


