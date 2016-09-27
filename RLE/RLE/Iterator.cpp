#include "Iterator.h"

Iterator::Iterator(Node* pStart)
{
	this->pStart = this->pCurrent = pStart;
}

Node* Iterator::getCurrent()
{
	return this->pCurrent;
}

void Iterator::setCurrent(Node* value)
{
	this->pCurrent = value;
}

bool Iterator::isLast()
{
	if (this->pCurrent->next == NULL)
	{
		return true;
	}

	return false;
}

void Iterator::moveNext()
{
	if (this->pCurrent)
	{
		this->pCurrent = this->pCurrent->next;
	}
}

void Iterator::rewind()
{
	this->pCurrent = this->pStart;
}

bool Iterator::endReached() const
{
	return this->pCurrent == NULL;
}