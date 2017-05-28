#ifndef FactorCalculator_h
#define FactorCalculator_h

#include "FileRecord.h"
#include <map>
#include "Vector.h"
#include <queue>

class FactorCalculator
{
public:
	FactorCalculator(map<int, Vector<FileRecord*>>);

	int processText(string);
	

private:
	map<int, Vector<FileRecord*>> lengthPhraseMap;

	vector<string> textToVector(string);
	string getWord(string);
	FileRecord* searchCurrPhraseInMap(string, int);
	FileRecord* binarySearch(Vector<FileRecord*>, string);
	int getMostWordInPhrase();

};

#endif