#include "KeyValueStore.h"
#include "Functions.h"
#include <string>


char* substring(char* input, char*& result, char c)
{
	int len = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == c)
		{
			result[len] = '\0';
			return result;
		}

		result[len] = input[i];
		len++;

	}

	return "";

}

int main()
{

	KeyValueStore* table = new KeyValueStore(2);


	char* a = "m1";
	char* b = "11";
	char* c = "t1";
	char* d = "o1";
	char* e = "32";
	char* f = "d1";
	char* g = "81";
	char* h = "n";
	char* i = "g";
	char* j = "l";
	char* k = "s";
	char* l = "x";
	char* m = "q";
	char* n = "2";
	char* o = "s";

	cout << table->store(b, 2);
	cout << endl;
	cout <<	table->store(c, 2);
	cout << endl;
	cout << table->store(d, 2);
	cout << endl;
	cout <<	table->store(e, 2);
	cout << endl;
	cout << table->store(f, 2);
	cout << endl;
	cout <<	table->store(g, 2);
	cout << endl;
	cout <<	table->store(h, 1);
	cout << endl;
	cout <<	table->store(i, 1);
	cout << endl;
	cout <<	table->store(j, 1);
	cout << endl;
	cout <<	table->store(k, 1);
	cout << endl;
	cout <<	table->store(l, 1);
	cout << endl;
	cout <<	table->store(m, 1);
	cout << endl;
	cout <<	table->store(n, 1);
	cout << endl;
	cout <<	table->store(o, 1);
	cout << endl;
	cout << table->store(g, 1);

	cout << endl;
	char* key = new char[1024];
	key = table->store("marina", 6);
	cout << key << endl;
	char* res = new char[10];
	size_t size = 0;


	table->load(key, res, size);
	cout << res << endl;

	table->erase(key);

	return 0;
}