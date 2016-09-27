#ifndef LinkedList_h
#define LinkedList_h

class LinkedList;

#include "Node.h"
#include "Iterator.h"
using namespace std;

class LinkedList
{

public:

	LinkedList(Node* start);

	LinkedList();
	LinkedList(LinkedList const &);
	LinkedList& operator=(LinkedList const &);
	~LinkedList();

	int getSize() const;
	Node* getFirst();
	Node* getLast();

	void setSize(int size);

	//void removeAll();
	bool append(LinkedList const &);


	void addToHead(Tuple* data);
	void addToTail(Tuple* data);

	void deleteHead();
	//void deleteTail();
	void deleteAt(int index);

	Node* findNodeAt(int index) const;

	bool isEmpty() const;
	Iterator getIterator() const;

	void printLinkedList();

	Node* cloneChain(Node* pFirstNode, Node* first, Node * last);
	void destroyChain(Node* pFirstNode);
	Node* findEndOfChain(Node* pFirstNode);

	void incrementSize();

private:

	Node* pFirst;
	Node* pLast;
	int size;


};



#endif
