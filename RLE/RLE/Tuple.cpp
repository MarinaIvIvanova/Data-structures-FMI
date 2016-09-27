#include "Tuple.h"

#include<iostream>
using namespace std;


Tuple::Tuple()
{
	this->key = 0;
	this->value = ' ';
}

Tuple::Tuple(int key, char value)
{
	this->key = key;
	this->value = value;
}

Tuple::~Tuple()
{
	this->key = 0;
	this->value = ' ';
}

int Tuple::getKey()
{
	return this->key;
}

char Tuple::getValue()
{
	return this->value;
}

void Tuple::setKey(int key)
{
	this->key = key;
}

void Tuple::setValue(char value)
{
	this->value = value;
}

char* Tuple::decodeTuple()
{
	int key = 3;
	char value = 'c';
	char* result = "";
	for (int i = 0; i < key; i++)
	{
		result += value;
	}

	return result;
}