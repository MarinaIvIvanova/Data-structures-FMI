#include "Functions.h"

int writeInFile(fstream& file, Node* elem)
{
	file << elem->content;
	file << endl;
	while (elem->next != NULL)
	{

		elem = elem->next;
		file << elem->content;
		file << endl;
	}

	if (!file)
	{
		cerr << "Error" << endl;
		return -1;
	}

	return 0;
}


char* intToChar(int num)
{

	int tmpNum = num;
	int digits = 1;
	while (tmpNum /= 10)
	{
		digits++;
	}

	char* result = new char[digits + 1];
	int i;
	for (i = digits - 1; i >= 0; i--)
	{
		int n = num % 10;
		result[i] = char(n + '0');
		num = num / 10;
	}
	result[digits] = '\0';

	return result;

}

//int OfDegree(int sqr, int base)
//{
//	int result = 1;
//	for (int i = 0; i < sqr; i++)
//	{
//		result *= base;
//	}
//
//	return result;
//}
//
//
//
//int MakeInputNumberTo10System(char* number, int fromSystem)
//{
//	int digit = 0;
//	int result = 0;
//	int count = strlen(number) - 1;
//	for (int i = 0; i < strlen(number); i++)
//	{
//		switch (number[i])
//		{
//		case 'A':
//			digit = 10;
//			break;
//		case 'B':
//			digit = 11;
//			break;
//		case 'C':
//			digit = 12;
//			break;
//		case 'D':
//			digit = 13;
//			break;
//		case 'E':
//			digit = 14;
//			break;
//		case 'F':
//			digit = 15;
//			break;
//		default:
//			digit = number[i] - '0';
//			break;
//		}
//
//		result += digit * OfDegree(count, fromSystem);
//		count--;
//
//	}
//
//	return result;
//
//}
//
//string ConvertToAnyNumericSystem(char* number, int fromBase, int toBase)
//{
//	int resultTo10System = MakeInputNumberTo10System(number, fromBase);
//	string digit;
//	while (resultTo10System)
//	{
//
//		switch (resultTo10System % toBase)
//		{
//		case 9:
//			digit = '9' + digit;
//			break;
//		case 8:
//			digit = '8' + digit;
//			break;
//		case 7:
//			digit = '7' + digit;
//			break;
//		case 6:
//			digit = '6' + digit;
//			break;
//		case 5:
//			digit = '5' + digit;
//			break;
//		case 4:
//			digit = '4' + digit;
//			break;
//		case 3:
//			digit = '3' + digit;
//			break;
//		case 2:
//			digit = '2' + digit;
//			break;
//		case 1:
//			digit = '1' + digit;
//			break;
//		case 0:
//			digit = '0' + digit;
//			break;
//		case 10:
//			digit = 'A' + digit;
//			break;
//		case 11:
//			digit = 'B' + digit;
//			break;
//		case 12:
//			digit = 'C' + digit;
//			break;
//		case 13:
//			digit = 'D' + digit;
//			break;
//		case 14:
//			digit = 'E' + digit;
//			break;
//		case 15:
//			digit = 'F' + digit;
//			break;
//
//		}
//		resultTo10System = resultTo10System / toBase;
//	}
//
//	return digit;
//
//}