#ifndef LengthPhraseGrouper_H
#define LengthPhraseGrouper_H

#include "FileReader.h"
#include "Vector.h"
#include <map>

class LengthPhraseGrouper
{
public:
	LengthPhraseGrouper(string);

	map<int, Vector<FileRecord*>> getLengthPhraseMap();

private:
	map<int, Vector<FileRecord*>> lengthPhraseMap;

	Vector<FileRecord*> readDictionary(string);
	void fillMap(Vector<FileRecord*>);
	void addRecord(FileRecord*);

	FileRecord* parsedFileLineToDictionaryRecord(string);
	void sortMap();
	void sortVector(Vector<FileRecord*>&);
	void radixSort(Vector<FileRecord*>& arrayToSort, Vector<FileRecord*> aux, int lo, int hi, int d);
	int charAt(string s, int d);
};

#endif