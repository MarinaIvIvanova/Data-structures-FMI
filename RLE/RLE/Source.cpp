#include <iostream>
#include <string>

#include "LinkedList.h"
#include "Tuple.h"
#include "RLEString.h"

using namespace std;

int main()
{

	Tuple* tuple = new Tuple();
	//Node node(&tuple, NULL);


	LinkedList *  list = new LinkedList();

	list->addToHead(tuple);

	LinkedList * newList = new LinkedList();

	LinkedList*  list1 = new LinkedList();
	list1->addToHead(new Tuple(4, 'f'));
	list1->addToHead(new Tuple(3, 'r'));

	Iterator iterator = list1->getIterator();


	*list = *list1;

	char test[] = "aaavvvfffr";
	char test1[] = "aaavvvfffrrr";

	RLEString  rleString(test);

	RLEString rleString1OPerator(test1);
	//rleString = rleString1OPerator;

	RLEString * copyConst = new RLEString(rleString1OPerator);
	cout << rleString.operator+(rleString1OPerator);


	//cout << rleString << endl;
	//rleString.splice(2, 4);
	//cout << rleString << endl;
	
	/*cout << rleString[1] << endl;

	cout << rleString.length() << endl;*/
	return 0;
} 