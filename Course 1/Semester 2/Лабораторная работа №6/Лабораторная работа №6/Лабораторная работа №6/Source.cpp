#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

char Alphabet[26][2] = { {'A', 'э'}, {'B', 'б'}, {'C', 'с'}, {'D', 'д'}, {'E', 'е'}, {'F', 'ф'}, {'G', 'г'}, {'H', '\0'}, {'I', 'и'}, {'J', 'ж'}, {'K', 'к'}, {'L', 'л'}, {'M', 'м'}, {'N', 'н'}, {'O', 'о'}, {'P', 'п'}, {'Q', 'к'}, {'R', 'р'}, {'S', 'с'}, {'T', 'т'}, {'U', 'у'}, {'V', 'в'}, {'W', 'в'}, {'X', 'кс'}, {'Y', 'й'}, {'Z', 'з'} };

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

	cout << "Введите предложение на английском языке: \n";
	getline(cin, Sentence);
	
	TranscriptionOfSentence(Sentence);

	return 0;
}