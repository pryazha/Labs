#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

char Alphabet[26][2] = { {'A', '�'}, {'B', '�'}, {'C', '�'}, {'D', '�'}, {'E', '�'}, {'F', '�'}, {'G', '�'}, {'H', '\0'}, {'I', '�'}, {'J', '�'}, {'K', '�'}, {'L', '�'}, {'M', '�'}, {'N', '�'}, {'O', '�'}, {'P', '�'}, {'Q', '�'}, {'R', '�'}, {'S', '�'}, {'T', '�'}, {'U', '�'}, {'V', '�'}, {'W', '�'}, {'X', '��'}, {'Y', '�'}, {'Z', '�'} };

string WordTranscription(string word)
{
	string result;

	for (int i = 0; i < word.length(); i++)
		for (int j = 0; j < 26; j++)
			if (word[i] == Alphabet[j][0])
				result += Alphabet[j][1];

	return result;
}

void TranscriptionOfSentence(string Str)
{
	string result = "";
	int i = 0;
	string tempStr;
	Str += "_";

	while (Str[i] != '\0')
	{
		if (Str[i] != '_')
			tempStr += Str[i];
		else
		{
			cout << tempStr << " - \"";
			tempStr = WordTranscription(tempStr);
			cout << tempStr << "\" -> ";
			string secondTempStr = tempStr;
			getline(cin, tempStr);
			if (tempStr == "")
				result += secondTempStr + " ";
			else
				result += tempStr + " ";
			tempStr = "";
		}
		i++;
	}
	Str.pop_back();
	cout << Str << " -> " << result;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Sentence;

	cout << "������� ����������� �� ���������� �����: \n";
	getline(cin, Sentence);
	
	TranscriptionOfSentence(Sentence);

	return 0;
}