#ifndef Node_H
#define Node_H

#include<iostream>


#include "Tuple.h"

using namespace std;

class Node
{
public:

	Node(Tuple* data, Node* next);
	Node(Node* next);

	void setData(Tuple* data);
	void setNext(Node* nextNode);
	Node * getNext();
	/*string decodeTuple();*/
public:
	Tuple* data;	
	Node* next;

};


#endif