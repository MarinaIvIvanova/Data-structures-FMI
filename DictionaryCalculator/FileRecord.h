#ifndef FileRecord_H
#define FileRecord_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class FileRecord
{
public:
	FileRecord(string, int);
	FileRecord();

	void printRecord() const;

	string getPhrase();
	int getEval();

	void setPhrase(string);
	void setEval(int);

	int getNumWordsInPhrase();

private:
	string phrase;
	int eval;
};

#endif
