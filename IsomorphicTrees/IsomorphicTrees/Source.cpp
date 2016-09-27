#include <iostream>
#include <string>
#include <vector>
#include<stack>
#include "Tree.h"
#include "Node.h"
using namespace std;


int firstIndexOf(string input, char c)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == c)
		{
			return i;
		}
	}

	return -1;
}

int lastIndexOf(string input, char c)
{
	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (input[i] == c)
		{
			return i;
		}
	}

	return -1;
}

int indexOf(string input, char c)
{
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == c)
		{
			return i;
		}
	}

	return -1;
}

int getClosingBracket(int indexOpenBracket, string input)
{
	int opening = 0;
	int index = 0;

	for (int i = indexOpenBracket; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			opening++;
		}

		if (input[i] == ')')
		{
			opening--;
		}

		if (opening == 0)
		{
			index = i;
			break;
		}

	}

	return index;
}
int getClosingCurlyBracket(string input)
{
	int opening = 0;
	int index = 0;

	for (int i = indexOf(input, '{'); i < input.length(); i++)
	{
		if (input[i] == '{')
		{
			opening++;
		}

		if (input[i] == '}')
		{
			opening--;
		}

		if (opening == 0)
		{
			index = i;
			break;
		}

	}

	return index;
}



string subString(string input, int startPos, int endPos)
{
	string result = "";
	for (int i = startPos; i < endPos; i++)
	{
		result += input[i];
	}

	return result;
}

int getRoot(string& input)
{

	input.erase(firstIndexOf(input, '('), 1);
	input.erase(lastIndexOf(input, ')'), 1);

	string root = "";
	int i = 0;
	while (isdigit(input[i]))
	{
		root += input[i];
		i++;
	}

	input.erase(0, i);
	return atoi(root.c_str());
}

Node* getParent(string& input)
{
	int rootValue = getRoot(input);
	Node* parent = new Node(rootValue);

	return parent;
}

Node* processNode(string& input, Node* parent, int level)
{

	int value = getRoot(input);

	input.erase(firstIndexOf(input, '{'), 1);
	input.erase(lastIndexOf(input, '}'), 1);

	Node* newNode = new Node(value, level);

	if (parent == NULL)
	{
		parent = newNode;
	}
	else
	{
		parent->addChild(newNode);
	}

	vector<string> childs;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			int closeBracket = getClosingBracket(i, input);
			string child = input.substr(i, closeBracket - i + 1);
			childs.push_back(child);
			i = closeBracket + 1;

		}
	}

	if (childs.empty())
	{
		return parent;
	}

	for (int i = 0; i < childs.size(); i++)
	{
		processNode(childs[i], newNode, level++);
	}

	return parent;
}



bool isIsomorphic(Tree* t1, Tree* t2)
{
	Node* root1 = t1->getRoot();
	Node* root2 = t2->getRoot();

	int check1 = t1->getLevelsCnt(root1);
	int check2 = t2->getLevelsCnt(root2);

	if (check1 != check2)
	{
		return false;
	}

	for (int i = 0; i < t1->getLevelsCnt(root1); i++)
	{
		vector<Node*> currLvlNodes1 = t1->getLvlNodes(i);
		vector<Node*> currLvlNodes2 = t2->getLvlNodes(i);

		if (currLvlNodes1.size() != currLvlNodes2.size())
		{
			return false;
		}

		bool checkNode = true;
		for (int n1 = 0; n1 < currLvlNodes1.size();)
		{
			if (checkNode == false)
			{
				return false;
			}
			for (int n2 = 0; n2 < currLvlNodes2.size(); n2++)
			{
				if (currLvlNodes1[n1]->getChildren().size() == currLvlNodes2[n2]->getChildren().size() && currLvlNodes2[n2]->isChecked() == false)
				{
					checkNode = true;
					currLvlNodes2[n2]->setCheking(true);
					n1++;
					break;
				}

				checkNode = false;
			}

		}
	}

	return true;

}

int main()
{

	string input = "(5 {(9 {}) (1 {(4 {})(42 {})})})";

	string input1 = "(5 {(9 {}) (1 {(4 {})(5 {})(42 {})})})";


	Node* root1 = processNode(input, NULL, 0);
	Node* root2 = processNode(input1, NULL, 0);

	Tree* tree1 = new Tree();
	tree1->setRoot(root1);

	Tree* tree2 = new Tree();
	tree2->setRoot(root2);

	cout << isIsomorphic(tree1, tree2) << endl;



	return 0;
}