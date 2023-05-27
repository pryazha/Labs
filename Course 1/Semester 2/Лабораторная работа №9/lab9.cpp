#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int StrNumber;
string max_str;
int max_num;
int max_vowels;

void createFile()
{
	ofstream fout("file1.txt");
	for (int i = 0; i < StrNumber; i++)
	{
		string s;
		getline(cin, s);
		fout << s << endl;
	}
	fout.close();
}

void printFile(string filename)
{
	ifstream fin(filename);
	string s;
	fin >> s;
	while (s != "\0" && !fin.eof())
	{
		cout << s << " ";
		if (fin.get() == '\n')
			cout << endl;
		fin >> s;
	}
	fin.close();
}

int numOfVowels(string str)
{
	string vowels = "aeiouy";
	// string vowels = "аоуэыяёюеи";
	int res = 0;
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < vowels.length(); j++)
			if (tolower(str[i]) == vowels[j])
				res++;
	return res;
}

int numWords(string str)
{
	int res = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ')
			res++;
	return res + 1;
}

void copyFile()
{
	ifstream fin("file1.txt");
	ofstream fout("file2.txt");

	string s;
	while (!fin.eof())
	{
		getline(fin, s);
		if (numWords(s) > 2)
			fout << s << '\n';
	}

	fin.close();
	fout.close();
}

void maxElem(string filename)
{
	max_vowels = 0;
	int c;
	int num = 0;
	string str;
	ifstream fin(filename);
	while (!fin.eof())
	{
		num++;
		c = 0;
		fin >> str;
		c = numOfVowels(str);
		if (c > max_vowels)
		{
			max_vowels = c;
			max_num = num;
			max_str = str;
		}
	}
}

int main()
{
	cout << "Enter the number of lines of the file: ";
	cin >> StrNumber;
	cin.get();

	createFile();
	copyFile();

	cout << "\nFile 1: \n";
	printFile("file1.txt");
	cout << "\nFile 2: \n";
	printFile("file2.txt");

	cout << "\n\nElement with the most vowels:\n";
	maxElem("file1.txt");
	cout << "File 1 - " << max_str << " with number " << max_num << ", contains " << max_vowels << " vowels.\n";
	maxElem("file2.txt");
	cout << "File 2 - " << max_str << " with number " << max_num << ", contains " << max_vowels << " vowels.\n";

	return 0;
}