#include"LinkedList.h"
LinkedList::LinkedList()
{
	this->pFirst = NULL;
	this->pLast = NULL;
	this->size = 0;
}

LinkedList::LinkedList(Node* start)
{
	this->pFirst = start;
	this->pLast = start;
	this->size = 1;
}

LinkedList::LinkedList(LinkedList const& listObj)
{
	*this = listObj;
}
void LinkedList:: incrementSize(){
	size ++;
}

LinkedList& LinkedList::operator=(LinkedList const& listObj)
{
	if (this != &listObj)
	{

		destroyChain(this->pFirst);
		this->pFirst = NULL;
		this->pLast = NULL;
		this->size = 0;

		append(listObj);
	}

	return *this;
}


LinkedList::~LinkedList()
{
	destroyChain(this->pFirst);
	this->pFirst = NULL;
	this->pLast = NULL;
}

bool LinkedList::append(LinkedList const & list)
{
	if (list.isEmpty())
	{
		return true;
	}
	else
	{

		Node* pNewChain = cloneChain(list.pFirst, this->pFirst, this->pLast);
		this->pFirst = pNewChain;
		this->size = list.getSize();

		return pNewChain != NULL;
	}
}


int LinkedList::getSize() const
{
	return this->size;
}

Node* LinkedList::getFirst()
{
	return this->pFirst;
}

Node* LinkedList::getLast()
{
	Node * tmp = this->pFirst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return tmp;
}

void::LinkedList::setSize(int size)
{
	this->size = size;
}

void LinkedList::addToHead(Tuple* data)
{
	Node* newNode = new Node(data, this->pFirst);

	if (this->isEmpty())
	{
		this->pLast = newNode;
	}

	this->pFirst = newNode;
	this->size++;
}

void LinkedList::addToTail(Tuple* data)
{
	Node* newNode = new Node(data, NULL);

	if (this->isEmpty())
	{
		this->pFirst = newNode;
		this->pLast = newNode;
	}
	else
	{
		Node * tmp = this->pFirst;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
		this->pLast = tmp;
	}

	this->size++;
}

void LinkedList::deleteHead()
{
	if (!(this->isEmpty()))
	{
		Node* oldHead = this->pFirst;
		this->pFirst = this->pFirst->next;

		if (this->pFirst == NULL)
		{
			this->pLast = NULL;
		}

		this->size--;
		delete oldHead;
	}


}

void LinkedList::deleteAt(int index)
{
	if (index == 0)
	{
		this->deleteHead();	
	}

	Node* pNodeBeforeIndex = findNodeAt(index - 1);

	Node* pNodeAtIndex = pNodeBeforeIndex->next;

	if (index == this->size - 1)
	{
		this->pLast = pNodeBeforeIndex;
	}

	pNodeBeforeIndex->next = pNodeAtIndex->next;

	delete pNodeAtIndex;

	this->size--;

	
}

Node* LinkedList::findNodeAt(int index) const
{
	if (index < 0 || index >= this->size)
	{
		return NULL;
	}
	else
	{
		Node* p = this->pFirst;

		for (int i = 0; i < index; i++)
		{
			p = p->next;
		}

		return p;
	}
}

bool LinkedList::isEmpty() const
{
	return this->size == 0;
}

Iterator LinkedList::getIterator() const
{
	return Iterator(this->pFirst);
}


void LinkedList::printLinkedList()
{

	while (pFirst != NULL)
	{
		cout << pFirst->data << endl;
		pFirst = pFirst->next;
	}


}


Node* LinkedList::cloneChain(Node* pFirstNode, Node * first, Node* last)
{
	if (pFirstNode)
	{
		Tuple* newTuple = new Tuple(pFirstNode->data->getKey(), pFirstNode->data->getValue());
		// Pointer to the start of the new chain
		Node* pNewChain = new Node(newTuple, NULL);
		first = pNewChain;
		Node* pNext = pNewChain;
		while (pFirstNode->next){
			pFirstNode = pFirstNode->getNext();
			newTuple = new Tuple(pFirstNode->data->getKey(), pFirstNode->data->getValue());
			Node * nextNode = new Node(newTuple, NULL);
			pNewChain->setNext(nextNode);
			pNewChain = nextNode;			
		}
		this->pLast = pFirstNode;
		last = pFirstNode;
		
		return first;
	}

	return NULL;
}


void LinkedList::destroyChain(Node* pFirstNode)
{
	Node* pCurrent = pFirstNode;
	Node* pOld =  pFirstNode;

	while (pCurrent)
	{
		pOld = pCurrent;
		pCurrent = pCurrent->next;
		delete pOld;
	}
	this->pFirst = NULL;
	this->pLast = NULL;
}

Node* LinkedList::findEndOfChain(Node* pFirstNode)
{
	Node* pCurrent = pFirstNode;

	if (pCurrent)
	{
		while (pCurrent->next)
		{
			pCurrent = pCurrent->next;
		}
	}

	return pCurrent;
}


