#ifndef Iterator_h
#define Iterator_h


class Iterator;

#include "Node.h"
#include "Tuple.h"

class Iterator
{
public:
	Iterator(Node* pStart);

	Node* getCurrent();
	void setCurrent(Node* currNode);
	bool  isLast();

	void moveNext();
	void rewind();
	bool endReached() const;

private:
	Node* pStart;
	Node* pCurrent;
};

#endif