#include "KeyValueStore.h"
#include "Functions.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace::std;

int KeyValueStore::id = 0;

KeyValueStore::KeyValueStore()
{
	this->capacity = 16;
	this->size = 0;
	this->buckets = new Node*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		buckets[i] = new Node();
	}
}

KeyValueStore::KeyValueStore(int initialCapacity)
{
	this->capacity = initialCapacity;
	this->size = 0;
	this->buckets = new Node*[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		buckets[i] = NULL;
	}
}

KeyValueStore::~KeyValueStore()
{
	destroyArray();
}

KeyValueStore::KeyValueStore(KeyValueStore const &obj)
{
	this->buckets = new Node*[obj.capacity];
	for (int i = 0; i < obj.size; i++)
	{


		buckets[i] = new Node();
		buckets[i]->content = obj.buckets[i]->content;
		buckets[i]->id = obj.buckets[i]->id;
		buckets[i]->next = obj.buckets[i]->next;
		buckets[i]->size = obj.buckets[i]->size;
	}

	this->capacity = obj.capacity;
	this->size = obj.size;
}

KeyValueStore& KeyValueStore::operator=(KeyValueStore const &obj)
{
	if (this != &obj)
	{
		destroyArray();

		this->buckets = new Node*[obj.capacity];
		for (int i = 0; i < obj.capacity; i++)
		{
			buckets[i] = new Node();
			buckets[i]->content = obj.buckets[i]->content;
			buckets[i]->id = obj.buckets[i]->id;
			buckets[i]->next = obj.buckets[i]->next;
			buckets[i]->size = obj.buckets[i]->size;
		}

		this->capacity = obj.capacity;
		this->size = obj.size;
	}

	return *this;
}

void KeyValueStore::destroyArray()
{
	for (int i = 0; i < this->capacity; i++)
	{
		Node* pCurrent = this->buckets[i];
		Node* pOld = this->buckets[i];

		while (pCurrent)
		{
			pOld = pCurrent;
			pCurrent = pCurrent->next;
			delete pOld;
			pOld = NULL;
		}
		buckets[i] = NULL;
	}

	delete[] buckets;
	buckets = NULL;
}

int KeyValueStore::hashFunction(const char* key, int size)
{
	int h = 0;
	int i;

	for (i = 0; i < size; i++)
	{
		h ^= (h << 5) + (h >> 2) + key[i];
	}

	return h;
}

int KeyValueStore::indexOf(int hash, int capacity)
{
	return capacity - 1 & hash;
}

char* KeyValueStore::store(char* value, size_t valueSize)
{
	int index = 0;
	if (size >= capacity * 0.75)
	{
		int newCapacity = capacity * 2;

		Node** newBuckets = new Node*[newCapacity];
		for (int i = 0; i < newCapacity; i++)
		{
			newBuckets[i] = NULL;
		}

		for (int i = 0; i < capacity; i++)
		{
			Node* curr = buckets[i];
			if (curr != NULL)
			{
				buckets[i] = NULL;

				do
				{
					Node* next = curr->next;
					int hash = hashFunction(value, valueSize);
					index = indexOf(hash, newCapacity);
					curr->next = newBuckets[index];
					newBuckets[index] = curr;
					curr = next;
				} while (curr != NULL);
			}
		}

		delete[] this->buckets;
		this->buckets = newBuckets;
		this->capacity = newCapacity;
	}

	int hash = this->hashFunction(value, valueSize);
	index = indexOf(hash, this->capacity);
	cout << index << endl;
	Node* newNode = new Node(value, valueSize, NULL, id);
	Node* currBucket = buckets[index];
	
	if (currBucket == NULL)
	{
		if (newNode != NULL)
		{
			size++;
		}
		this->buckets[index] = newNode;

	}
	else
	{
		while (currBucket)
		{
			if (strcmp(currBucket->content, newNode->content) == 0)
			{
				return getKeyString(hash, currBucket->id);
			}
			
			if (currBucket->next == NULL)
			{
				currBucket->next = newNode;
				break;
			}

			currBucket = currBucket->next;
		}
	}



	char* result = getKeyString(hash, id++);
	writeInFile(result, value);


	return result;
}

bool KeyValueStore::load(char* key, char*& pBlock, size_t& size)
{
	int hash = 0, id = 0;
	sscanf(key, "%d:%d", &hash, &id);
	
	int index = indexOf(hash, capacity);
	Node* current = buckets[index];
	while (current)
	{
		if (current->id == id)
		{
			pBlock = new char[current->size + 1];
			size = current->size;
			strncpy_s(pBlock, size + 1, current->content, size + 1);

			return true;
		}
		current = current->next;
	}
	
	return false;
}

void KeyValueStore::erase(char* key)
{
	int hash = 0, id = 0;
	sscanf(key, "%d:%d", &hash, &id);


	eraseFromFile(key);
	int index = indexOf(hash, capacity);
	Node* current = buckets[index];
	Node* previous = current;
	while (current)
	{
		if (current->id == id)
		{
			previous->next = current->next;
			current = NULL;
			return;
		}
		previous = current;
		current = current->next;
	}
}

char* KeyValueStore::getKeyString(int hash, int id)
{
	stringstream ss;
	ss << hash << ":" << id;
	std::string output = ss.str();
	char* str = new char[output.size() + 1];
	strncpy_s(str, output.size() + 1, output.c_str(), output.size() + 1);

	return str;
}

void KeyValueStore::writeInFile(char* key, char* value)
{
	fstream file;
	file.open("key_value_store.txt", ios::out | ios::in | ios::app);
	if (!file)
	{
		cerr << "File cannot be open!" << endl;
		return;
	}

	
	file.seekg(0, std::ios::beg);	
	string recordToCheck;
	while (!file.eof())
	{
		getline(file, recordToCheck);
		int index = recordToCheck.find(' ');
		string recordKey = recordToCheck.substr(0, index);

		if (strcmp(recordKey.c_str(), key) == 0)
		{
			return;
		}
	}
	/*file.clear();
	cin.sync();*/
	file << key;
	file << ' ';
	file << value;
	file << endl;
	file.close();
}

void KeyValueStore::eraseFromFile(char* key)
{
	fstream file;
	file.open("key_value_store.txt", ios::out | ios::in);

	std::ofstream tempFile("tmpKeyValuesList.txt", std::ios::app);

	string lineFromFile;

	while (getline(file,lineFromFile))
	{
		int found = lineFromFile.find(" ");
		string currKey;
		if (found != string::npos)
		{
			currKey = lineFromFile.substr(0, found);
		}

		if (strcmp(currKey.c_str(), key) != 0)
		{
			tempFile << lineFromFile;
			tempFile << endl;
		}
	
	} 

	file.close();
	tempFile.close();
	std::remove("key_value_store.txt");
	std::rename("tmpKeyValuesList.txt", "key_value_store.txt");

}