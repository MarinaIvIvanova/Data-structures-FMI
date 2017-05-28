#ifndef FileReader_h
#define FileReader_h

#include "FileRecord.h"
#include <vector>
#include <fstream>

class FileReader
{
public:
	FileReader(string);
	string getText();

private:
	string text;
};

#endif