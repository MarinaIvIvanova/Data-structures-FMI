#ifndef Tuple_h
#define Tuple_h


class Tuple
{
public:
	Tuple();
	Tuple(int key, char value);
	~Tuple();

	int getKey();
	char getValue();

	void setKey(int key);
	void setValue(char value);

	char* decodeTuple();

private: 
	int key;
	char value;
};




#endif

