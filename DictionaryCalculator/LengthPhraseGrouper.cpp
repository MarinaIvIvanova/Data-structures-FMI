#include "LengthPhraseGrouper.h"

LengthPhraseGrouper::LengthPhraseGrouper(string filePath)
{
	Vector<FileRecord*> result = readDictionary(filePath);
	fillMap(result);
	sortMap();
}


Vector<FileRecord*> LengthPhraseGrouper::readDictionary(string filePath)
{
	Vector<FileRecord*> dictionaryPhraseList;
	ifstream file;
	file.open(filePath, ios::in);

	if (!file)
	{
		cerr << "Error.";
		return dictionaryPhraseList;
	}

	string lineFromFile;
	while (getline(file, lineFromFile))
	{
		dictionaryPhraseList.push_back(parsedFileLineToDictionaryRecord(lineFromFile));
	}

	return dictionaryPhraseList;
}

FileRecord* LengthPhraseGrouper::parsedFileLineToDictionaryRecord(string lineFromFile)
{
	string phrase;
	int eval;

	int pos = lineFromFile.find_last_of(" ");
	phrase = lineFromFile.substr(0, pos);
	eval = atoi(lineFromFile.substr(pos + 1).c_str());

	return new FileRecord(phrase, eval);
}

void LengthPhraseGrouper::fillMap(Vector<FileRecord*> dictionaryPhraseList)
{
	for (int i = 0; i < dictionaryPhraseList.getSize(); i++)
	{
		this->addRecord(dictionaryPhraseList[i]);
	}

}

void LengthPhraseGrouper::addRecord(FileRecord* record) 
{
	int numWordsInPhrase = record->getNumWordsInPhrase();
	map<int, Vector<FileRecord*>>::iterator it = this->lengthPhraseMap.find(numWordsInPhrase);
	if (it != this->lengthPhraseMap.end()) {
		it->second.push_back(record);
	}
	else {
		Vector<FileRecord*> fileRecords;
		fileRecords.push_back(record);
		this->lengthPhraseMap.insert(pair<int, Vector<FileRecord*>>(numWordsInPhrase, fileRecords));
	}
}

void LengthPhraseGrouper::sortMap()
{
	for (map<int, Vector<FileRecord*>>::iterator it = lengthPhraseMap.begin(); it != lengthPhraseMap.end(); it++)
	{
		sortVector(it->second);
	}
}

void LengthPhraseGrouper::sortVector(Vector<FileRecord*>& arrayToSort)
{
	Vector<FileRecord*> aux;
	for (int i = 0; i < arrayToSort.getSize(); i++)
	{
		aux.push_back(new FileRecord());
	}
	radixSort(arrayToSort, aux, 0, arrayToSort.getSize() - 1, 0);
}

void LengthPhraseGrouper::radixSort(Vector<FileRecord*>& arrayToSort, Vector<FileRecord*> aux, int lo, int hi, int d)
{
	int R = 256;
	if (hi <= lo)
	{
		return;
	}
	int* count = new int[R + 2];
	for (int i = 0; i < R + 2; i++)
	{
		count[i] = 0;
	}
	for (int i = lo; i <= hi; i++)
	{
		count[charAt(arrayToSort[i]->getPhrase(), d) + 2]++;
	}
	for (int r = 0; r < R + 1; r++)
	{
		count[r + 1] += count[r];
	}
	for (int i = lo; i <= hi; i++)
	{
		aux[count[charAt(arrayToSort[i]->getPhrase(), d) + 1]++] = new FileRecord(arrayToSort[i]->getPhrase(), arrayToSort[i]->getEval());
	}
	for (int i = lo; i <= hi; i++)
	{
		arrayToSort[i] = aux[i - lo];
	}
	for (int r = 0; r < R; r++)
	{
		radixSort(arrayToSort, aux, lo + count[r], lo + count[r + 1] - 1, d + 1);
	}
}

int LengthPhraseGrouper::charAt(string s, int d)
{
	if (d < s.length()) return s.at(d);
	else return -1;
}

map<int, Vector<FileRecord*>> LengthPhraseGrouper::getLengthPhraseMap()
{
	return this->lengthPhraseMap;
}