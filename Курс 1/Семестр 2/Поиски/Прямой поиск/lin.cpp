#include <iostream>
#include <string>

using namespace std;

void linSearch(string text, string pattern)
{
	for (int i = 0; i < text.length() - pattern.length() + 1; i++)
		for (int j = 0; j < pattern.length(); j++)
			if (pattern[j] != text[i + j])
				break;
			else if (j == pattern.length() - 1)
			{
				cout << "Found pattern at index: " << i << endl;
				break;
			}
}

int main()
{
	string str, substr;
	cout << "Enter text: ";
	cin >> str;
	cout << "Enter pattern: ";
	cin >> substr;

	linSearch(str, substr);

	return 0;
}