#ifndef Vector_h
#define Vector_h


template <typename T>
class Vector
{
public:

	Vector();
	Vector(int);
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	~Vector();

	int getSize();

	void push_back(const T&);
	void pop_back();
	T& back();
	bool empty();
	void print() const;

	void resize(int);

	T& operator[](int);

private:
	int size;
	int capacity;
	T* buffer;
};

template<typename T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 1;
	this->buffer = new T[capacity];
}

template<typename T>
Vector<T>::Vector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->buffer = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->buffer = new T[v.capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->buffer[i] = v.buffer[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	if (this != &v)
	{
		this->size = v.size;
		this->capacity = v.capacity;
		this->buffer = new T[v.capacity];

		for (int i = 0; i < this->size; i++)
		{
			this->buffer[i] = v.buffer[i];
		}
	}

	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] buffer;
}

template<typename T>
int Vector<T>::getSize()
{
	return this->size;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	buffer[size++] = value;
}


template<typename T>
void Vector<T>::pop_back()
{
	if (empty())
	{
		return;
	}

	this->size--;
}


template<typename T>
T& Vector<T>::back()
{
	return this->buffer[size - 1];
}

template<typename T>
bool Vector<T>::empty()
{
	return size == 0;
}

template<typename T>
void Vector<T>::resize(int newCapacity)
{
	T* temp = new T[newCapacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->buffer[i];
	}

	delete[] buffer;

	this->buffer = temp;
	this->capacity = newCapacity;
}

template<typename T>
T& Vector<T>::operator[](int index)
{
	return this->buffer[index];
}

template<typename T>
void Vector<T>::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << this->buffer[i] << " ";
	}

	cout << endl;
}

#endif