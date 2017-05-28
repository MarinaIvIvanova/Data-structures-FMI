#include "FileRecord.h"


FileRecord::FileRecord(string phrase, int eval)
{
	this->phrase = phrase;
	this->eval = eval;
}

FileRecord::FileRecord()
{
	this->phrase = "";
	this->eval = 0;
}

string FileRecord::getPhrase()
{
	return this->phrase;
}

int FileRecord::getEval()
{
	return this->eval;
}

int FileRecord::getNumWordsInPhrase()
{
	int count = 0;
	string word;
	stringstream ss(this->phrase);
	while (getline(ss, word, ' ')) {
		count++;
	}

	return count;
}

void FileRecord::setPhrase(string phrase)
{
	this->phrase = phrase;
}

void FileRecord::setEval(int eval)
{
	this->eval = eval;
}

void FileRecord::printRecord() const
{
	cout << this->phrase << " " << this->eval << endl;
}
