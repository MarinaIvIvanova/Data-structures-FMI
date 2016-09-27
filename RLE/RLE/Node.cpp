#include "Node.h"


Node::Node(Tuple* data, Node* next)
{
	this->data = data;
	this->next = next;
}

Node::Node(Node* next)
{
	this->next = next;
}

void Node::setNext(Node* nextNode){
	this->next = nextNode;
}
Node * Node::getNext(){
	return this->next;
}

//string Node::decodeTuple()
//{
//    return this->data->decodeTuple();
//}

//Node* Node::getNext()
//{
//	return this->next;
//}
//
//Tuple* Node::getData()
//{
//	return this->data;
//}

void Node::setData(Tuple* data)
{
	this->data = data;
}