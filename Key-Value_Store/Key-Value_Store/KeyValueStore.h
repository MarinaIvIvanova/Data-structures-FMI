#ifndef KeyValueStore_H
#define KeyValueStore_H

#include "Node.h"

class KeyValueStore
{
public:
	KeyValueStore();
	KeyValueStore(int initialCapacity);
	~KeyValueStore();
	KeyValueStore(const KeyValueStore &);
	KeyValueStore& operator=(const KeyValueStore &);

	void destroyArray();

	int hashFunction(const char*, int);
	int indexOf(int, int);

	char* store(char*, size_t);
	bool load(char* key, char*& pBlock, size_t& size);
	void erase(char*);

	

private:
	char* getKeyString(int hash, int id);
	void writeInFile(char* key, char* value);
	void eraseFromFile(char* key);

	Node** buckets;
	int capacity;
	int size;

	static int id;

};


#endif