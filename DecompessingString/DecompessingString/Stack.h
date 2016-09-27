#ifndef Stack_h
#define Stack_h

#include<iostream>
using namespace std;


template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

	void Push(const T& value);
	bool Pop();
	T& Top();
	bool IsEmpty();
	void PrintElements();
	//void DisplayStack();

private:
	T* data;
	int top;
	int capacity;
	void Resize(int newCapacity);



};

#endif

template<typename T>
Stack<T>::Stack()
{
	this->capacity = 2;
	this->top = 0;
	this->data = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] data;

}

template<typename T>
void Stack<T>::Push(const T& value)
{
	if (top >= capacity)
	{
		Resize(2 * capacity);
	}
	data[top++] = value;
}

template<typename T>
bool Stack<T>::Pop()
{
	if (IsEmpty())
	{
		return false;
	}

	--top;
	return true;
}
template<typename T>
T& Stack<T>::Top()
{
	return data[top - 1];
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return top == 0;
}

template <typename T>
void Stack<T>::Resize(int newCapacity) {
	T* newData = new T[newCapacity];
	for (int i = 0; i < top; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
	capacity = newCapacity;
}




