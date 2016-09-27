#include "Tree.h"


Tree::Tree()
{
	this->levelsCnt = 0;
}


Tree::~Tree()
{
	delete root;
	root = NULL;
}

Node* Tree::getRoot()
{
	return this->root;
}


void Tree::setRoot(Node* root)
{
	this->root = root;
}


void Tree::processNode(vector<Node*>& result, int level, Node* currNode)
{


	if (currNode->getLevel() == level)
	{
		result.push_back(currNode);
	}
	else
	{
		vector<Node*> children = currNode->getChildren();
		for (size_t i = 0; i < children.size(); i++)
		{
			processNode(result, level, children[i]);
		}

	}

}

vector<Node*> Tree::getLvlNodes(int level)
{
	vector<Node*> nodesPerLevel;
	processNode(nodesPerLevel, level, root);

	return nodesPerLevel;
}


bool Tree::isExternal(Node* node)
{
	if (node->getChildren().size() == 0)
	{
		return true;
	}

	return false;
}

int Tree::getLevelsCnt(Node* node)
{
	if (this->isExternal(node))
	{
		return 1;
	}

	int h = 0;
	vector<Node*> ch = node->getChildren();
	vector<Node*>::iterator it;
	for (it = ch.begin(); it < ch.end(); it++)
	{
		h = max(h, getLevelsCnt(*it));
	}

	return 1 + h;
}