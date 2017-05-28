#include "FactorCalculator.h"


FactorCalculator::FactorCalculator(map<int, Vector<FileRecord*>> lengthPhraseMap)
{
	this->lengthPhraseMap = lengthPhraseMap;
}

int FactorCalculator::processText(string sentence)
{
	vector<string> text = this->textToVector(sentence);
	int mostWordInText;
	string currSearchPhrase;
	int counter = 0;
	int currVectorIndex = 0;
	int sumEval = 0;

	while (currVectorIndex < text.size())
	{
		currSearchPhrase = "";
		counter = 0;
		mostWordInText = this->getMostWordInPhrase();
		while (counter < mostWordInText && currVectorIndex <= text.size() - 1)
		{
			currSearchPhrase += text[currVectorIndex];			
			currVectorIndex++;
			counter++;
			if (counter < mostWordInText && currVectorIndex <= text.size() - 1)
			{
				currSearchPhrase += ' ';
			}
		}

		while (!currSearchPhrase.empty())
		{
			FileRecord* result = this->searchCurrPhraseInMap(currSearchPhrase, mostWordInText);
			if (result != NULL)
			{
				sumEval += result->getEval();
				break;
			}
			else
			{
				int pos = currSearchPhrase.find_last_of(' ');
				if (pos < 0 )
				{
					break;
				}
				currSearchPhrase = currSearchPhrase.substr(0, pos);
				mostWordInText--;
				currVectorIndex--;
			}
		}
	}

	return sumEval / text.size();

}
vector<string> FactorCalculator::textToVector(string text)
{
	vector<string> result;
	istringstream iss(text);
	string word;
	while (iss >> word) {
		result.push_back(word);
	}
	return result;
}

int FactorCalculator::getMostWordInPhrase()
{
	int mostWordsInPhrase = 0;
	for (map<int, Vector<FileRecord*>>::iterator it = lengthPhraseMap.begin(); it != lengthPhraseMap.end(); it++)
	{
		if (it->first > mostWordsInPhrase)
		{
			mostWordsInPhrase = it->first;
		}
	}

	return mostWordsInPhrase;
}

FileRecord* FactorCalculator::searchCurrPhraseInMap(string phrase, int key)
{
	Vector<FileRecord*> currPhrases;
	map<int, Vector<FileRecord*>>::iterator it = this->lengthPhraseMap.find(key);
	if (it != this->lengthPhraseMap.end())
	{
		currPhrases = it->second;
	}

	return binarySearch(currPhrases, phrase);
}

FileRecord* FactorCalculator::binarySearch(Vector<FileRecord*> phrases, string phrase)
{
	size_t mid, left = 0;
	size_t right = phrases.getSize();
	while (left < right) {
		mid = left + (right - left) / 2;
		if (phrase.compare(phrases[mid]->getPhrase()) > 0){
			left = mid + 1;
		}
		else if (phrase.compare(phrases[mid]->getPhrase()) < 0){
			right = mid;
		}
		else {
			return phrases[mid];
		}
	}

	return NULL;
}