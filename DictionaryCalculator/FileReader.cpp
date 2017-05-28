#include "FileReader.h"


FileReader::FileReader(string filePath)
{
	ifstream file;
	file.open(filePath, ios::in);

	if (!file)
	{
		cerr << "Errorrrr";
		return;
	}

	string lineFromFile;
	while (getline(file, lineFromFile))
	{
		this->text += lineFromFile;
	}

}

string FileReader::getText()
{
	return this->text;
}