#include<iostream>
#include<string>
#include <sstream>
//#include<stack>
#include<queue>
#include "Stack.h"

using namespace std;

queue<string> shuntingYardAlgorithm(string inputString)
{
	Stack<string> operatorStack;
	queue<string> output;

	size_t i = 0;
	string num = "";
	string alpha = "";
	while (i < inputString.length())
	{
		if (isdigit(inputString[i]))
		{
			while (isdigit(inputString[i]))
			{
				num += inputString[i];
				i++;
			}

			output.push(num);
			num = "";
		}

		if (isalpha(inputString[i]))
		{
			while (isalpha(inputString[i]))
			{
				alpha += inputString[i];
				i++;
			}

			output.push(alpha);
			alpha = "";
		}

		if (inputString[i] == '(')
		{
			operatorStack.Push("*");
			i++;
		}

		if (inputString[i] == ')')
		{
			output.push(operatorStack.Top());
			operatorStack.Pop();
			i++;
		}
	}

	return output;

}

bool isNumber(string num)
{
	size_t i = 0;
	while (i < num.length())
	{
		if (isdigit(num[i]))
		{
			i++;
		}
		else
		{
			return false;
		}
	}

	return true;
}

int convertStringToNumber(string stringNum)
{
	istringstream buffer(stringNum);
	int value;
	buffer >> value;

	return value;
}

string calculateReversePolishNotation(queue<string> input)
{
	string alpha = "";
	string num = "";

	Stack<string> resultStack;
	string result = "";

	while (!input.empty())
	{
		if (input.front() != "*")
		{
			resultStack.Push(input.front());
			input.pop();
		}
		else
		{
			while (!(isNumber(resultStack.Top())))
			{
				alpha.insert(0, resultStack.Top());
				resultStack.Pop();
			}

			string tempAlpha = alpha;

			num = resultStack.Top();
			resultStack.Pop();
			int numInt = convertStringToNumber(num);

			for (int i = 0; i < numInt - 1; i++)
			{
				alpha += tempAlpha;
			}

			resultStack.Push(alpha);

			alpha = "";
			tempAlpha = "";

			input.pop();

		}
	}

	while (!resultStack.IsEmpty())
	{
		result.insert(0, resultStack.Top());
		resultStack.Pop();
	}



	return result;
}

bool validateInput(string input)
{
	int count = 0;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			count++;
		}
		if (input[i] == ')')
		{
			count--;
		}
	}

	if (count == 0)
	{
		return true;
	}

	return false;
}



int main()
{

	string str;

	do
	{
		cout << "Insert appropriate string: ";
		getline(cin, str);

	} while (!validateInput(str));


	queue<string> input;

	input = shuntingYardAlgorithm(str);

	cout << calculateReversePolishNotation(input) << endl;

	return 0;
}