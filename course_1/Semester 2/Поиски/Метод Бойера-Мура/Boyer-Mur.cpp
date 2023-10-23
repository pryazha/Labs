#include <iostream>
#include <string>

using namespace std;

void Tabl_Smech(string pattern, int* d)
{
	int i;
	for (i = 0; i < 256; i++)
		d[i] = -1;
	for (i = 0; i < pattern.length(); i++)
		d[(int) pattern[i]] = i;
}

void Boer_Mur(string text, string pattern)
{
	int d[256];
	Tabl_Smech(pattern, d);

	int i = 0;
	while (i < (text.length() - pattern.length()))
	{
		int j = pattern.length() - 1;
		while (j >= 0 && pattern[j] == text[i + j])
			j--;
		if (j < 0)
		{
			cout << "Pattern found at index: " << i << endl;
			if (i + pattern.length() < text.length())
				i += pattern.length() - d[text[i + pattern.length()]];
			else
				i += 1;
		}
		else
			if (1 > j - d[text[i + j]])
				i += 1;
			else
				i += j - d[text[i + j]];
	}
}

int main()
{
	string str, substr;
	cout << "Enter text: ";
	cin >> str;
	cout << "Enter pattern: ";
	cin >> substr;

	Boer_Mur(str, substr);

	return 0;
}