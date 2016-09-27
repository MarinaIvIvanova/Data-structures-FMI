#include<iostream>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;


int charAt(string s, int d)
{
	if (d < s.length()) return s.at(d);
	else return -1;
}

void radixSort(string* arrayToSort, string* aux, int lo, int hi, int d)
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
		count[charAt(arrayToSort[i], d) + 2]++;
	}
	for (int r = 0; r < R + 1; r++)
	{
		count[r + 1] += count[r];
	}
	for (int i = lo; i <= hi; i++)
	{
		aux[count[charAt(arrayToSort[i], d) + 1]++] = arrayToSort[i];
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

void sort(string* arrayToSort, int count)
{

	string* aux = new string[count];
	radixSort(arrayToSort, aux, 0, count - 1, 0);
}

int searchPrefix(string* names, string prefix, int size)
{
	int count = 0;
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (names[i].length() >= prefix.length())
		{
			bool check = true;
			while (j < prefix.length())
			{
				if (names[i].at(j) != prefix.at(j))
				{
					check = false;
					break;
				}
				j++;
			}

			if (check == true)
			{
				count++;
			}

			j = 0;
		}
		else
		{
			break;
		}

	}

	return count;
}

string* splitString(string queryString)
{
	int i = 0;
	string* result = new string[3];
	string word = "";
	stringstream stream(queryString);
	while (getline(stream, word, ' '))
	{
		result[i] = word;
		i++;
	}

	return result;

}

int toInt(string num)
{
	stringstream ss(num); //string buffer, v koito slagame nqkakvo chislo i toi go vrsyhta kato string
	int x;
	ss >> x;

	return x;
}

void clearStringArray(string* arrayForClear, int size)
{
	for (int i = 0; i < size; i++)
	{
		arrayForClear[i].clear();
	}
}

string* copyString(string* copyString, string* originalString, int startIndex, int endIndex)
{
	int j = 0;
	for (int i = startIndex; i < endIndex; i++)
	{
		copyString[j] = originalString[i];
		j++;
	}

	return copyString;
}


int main()
{
	int T;
	cout << "Number of test scenarios: ";
	cin >> T;

	int N, Q;
	string query = "";

	for (int i = 1; i <= T; i++)
	{
		do
		{
			cout << "Add N and Q: ";
			cin >> N >> Q;
		} while (N > 1000000 || Q > 500000);

		string* names = new string[N];
		for (int j = 0; j < N; j++)
		{
			cout << "Add name: ";
			cin >> names[j];
		}

		sort(names, N);
		int M = N;
		string* copyNames = new string[M];
		for (int j = 0; j < M; j++)
		{
			copyNames[j] = names[j];
		}

		for (int k = 0; k < M; k++)
		{
			cout << copyNames[k] << " ";
		}

		for (int k = 0; k < Q; k++)
		{
			cout << "Add query: ";
			cin.clear();
			cin.sync();
			std::getline(std::cin, query);
			string queryParamter = splitString(query)[0];
			//cout << "QUERY GIVEN:" << queryParameter << endl;
			if (splitString(query)[0] == "ENTER")
			{

				clearStringArray(copyNames, M);
				int startIndex = toInt(splitString(query)[1]);
				int endIndex = toInt(splitString(query)[2]) + 1;
				M = endIndex - startIndex;

				copyNames = copyString(copyNames, names, startIndex, endIndex);

			}
			if (splitString(query)[0] == "QUERY")
			{
				cout << searchPrefix(copyNames, splitString(query)[1], M);
			}
		}

	}

	return 0;
}