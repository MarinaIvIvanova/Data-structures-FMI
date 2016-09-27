#ifndef RLEString_H
#define RLEString_h

#include<iostream>
class RLEString;
#include "LinkedList.h"
#include "Tuple.h"
#include "Iterator.h"
using namespace std;


class RLEString
{
public:
	RLEString();
	~RLEString();
	RLEString(RLEString const & rhs);
	RLEString& operator=(RLEString const & rhs);

	RLEString(LinkedList& list);

	RLEString(char const*);
	friend ostream& operator<<(ostream& os, const RLEString&);
	size_t length() const;
	char& operator[](int i);
	RLEString operator+(RLEString const & right) const;
	void splice(int start, int length);
//	void insert(const RLEString& rles, int pos);

 

private:
	 LinkedList list;

	 void removeFromList(int start, int length);
	 void removeFromMiddleOfNode(int currNodePosition, int countToBeRemovedFromCurrNode, int remainingToBeRemovedFromOtherNodes);
};

#endif