#include "RLEString.h"


RLEString::RLEString()
{
	this->list = NULL;
}

RLEString::~RLEString()
{
	this->list.destroyChain(this->list.getFirst());
}

RLEString::RLEString(RLEString const & rhs)
{
	*this = rhs;
}

RLEString& RLEString::operator=(RLEString const & rhs)
{
	if (this != &rhs)
	{
		this->list = rhs.list;
	}
	return *this;
}

RLEString::RLEString(LinkedList& list){
	this->list = list;

}

RLEString::RLEString(char const* arg)
{
	int length = strlen(arg) + 1;
	int count = 1;
	char oldSymbol = arg[0];
	for (int i = 1; i<length; i++)
	{
		if (oldSymbol == arg[i])
		{
			count++;
		}
		else
		{
			list.addToTail(new Tuple(count, oldSymbol));
			count = 1;
			oldSymbol = arg[i];
		}
	}

}

ostream& operator<<(ostream& os, const RLEString& rleString)
{
	string result = "";
	for (Iterator iterator = rleString.list.getIterator(); !iterator.endReached(); iterator.moveNext())
	{
		int num = iterator.getCurrent()->data->getKey();
		for (int i = 0; i < num; i++)
		{
			result.append(1, iterator.getCurrent()->data->getValue());
		}

	}

	os << result.c_str();

	return os;
}


size_t RLEString::length() const
{
	int length = 0;
	for (Iterator iterator = this->list.getIterator(); !iterator.endReached(); iterator.moveNext())
	{
		for (int i = 0; i < iterator.getCurrent()->data->getKey(); i++)
		{
			length++;
		}
	}

	return length;
}

char& RLEString::operator[](int i)
{	
	int sumKeys = 0;
	char c = ' ';
	for (Iterator iterator = this->list.getIterator(); !iterator.endReached(); iterator.moveNext())
	{
		sumKeys += iterator.getCurrent()->data->getKey();
		if (sumKeys >= i)
		{
			c = iterator.getCurrent()->data->getValue();
			break;
		}
	}

	return c;
}

RLEString RLEString::operator+(RLEString const & right) const
{

	LinkedList* newList = new LinkedList();
	newList->append(this->list);
	Node * lastNode = newList->getLast();

	Iterator it2 = right.list.getIterator();

	char value1 = lastNode->data->getValue();
	char value2 = it2.getCurrent()->data->getValue();

	int key1 = lastNode->data->getKey();
	int key2 = it2.getCurrent()->data->getKey();

	if (value1 == value2)
	{
		it2.moveNext();
		lastNode->data->setKey(key1 + key2);

		while (!it2.endReached())
		{
			newList->addToTail(new Tuple(it2.getCurrent()->data->getKey(), it2.getCurrent()->data->getValue()));
			it2.moveNext();
		}
	
	}
	else
	{
		while (!it2.endReached())
		{
			newList->addToTail(new Tuple(it2.getCurrent()->data->getKey(), it2.getCurrent()->data->getValue()));
			it2.moveNext();
		}
	}

	return  RLEString(*newList);

}

void RLEString::splice(int start, int length)
{
	int tmp = 0;
	int nodePosition = -1;
	for (Iterator it = this->list.getIterator(); !it.endReached(); it.moveNext())
	{
		nodePosition++;
		tmp += it.getCurrent()->data->getKey();
		if (tmp == start)
		{
			removeFromList(nodePosition, length);
			break;
		}
		else if (tmp > start)
		{
			int countToBeRemovedFromCurrentNode = tmp - start;
			int remainingToBeRemovedFromOtherNodes = length - countToBeRemovedFromCurrentNode;
			removeFromMiddleOfNode(nodePosition, countToBeRemovedFromCurrentNode, remainingToBeRemovedFromOtherNodes);
			break;
		}


	}
}

void RLEString::removeFromList(int nodePosition, int length)
{
	Node* fromNode = this->list.findNodeAt(nodePosition);
	int currKey = fromNode->data->getKey();
	if (currKey > length)
	{
		fromNode->data->setKey(currKey - length);
	}
	else if (currKey == length)
	{
		list.deleteAt(nodePosition);
	}
	else
	{
		while (currKey <= length && nodePosition < this->list.getSize()) 
		{
			Node* nodeToDelete = list.findNodeAt(nodePosition);
			currKey = nodeToDelete->data->getKey();
			this->list.deleteAt(nodePosition);
			length -= currKey;
			nodePosition++;
		}
		Node* finalNode = list.findNodeAt(nodePosition);
		finalNode->data->setKey(finalNode->data->getKey() - length);


	}
}

void RLEString::removeFromMiddleOfNode(int currNodePosition, int countToBeRemovedFromCurrNode, int remainingToBeRemovedFromOtherNodes)
{
	Node* currNode = list.findNodeAt(currNodePosition);
	currNode->data->setKey(currNode->data->getKey() - countToBeRemovedFromCurrNode);
	removeFromList(currNodePosition + 1, remainingToBeRemovedFromOtherNodes);
}