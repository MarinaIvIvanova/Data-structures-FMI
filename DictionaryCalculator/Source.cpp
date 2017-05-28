#include "FileReader.h"
#include "LengthPhraseGrouper.h"
#include "FactorCalculator.h"


int main(int argc, char* argv[])
{
	Vector<string> textsToCheck;
	for (int i = 2; i < argc; i++)
	{
		FileReader reader(argv[i]);
		textsToCheck.push_back(reader.getText());
	}

	LengthPhraseGrouper test(argv[1]);
	FactorCalculator test1(test.getLengthPhraseMap());


	for (int i = 0; i < textsToCheck.getSize(); i++)
	{
		cout << test1.processText(textsToCheck[i]);
	}

	                                                                                                                                                                                                              
	                                    
 	return 0;
}