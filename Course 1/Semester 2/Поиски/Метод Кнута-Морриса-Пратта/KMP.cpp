#include <iostream>
#include <string>
using namespace std;

void pref_func(string pattern, int* d)
{
    d[0] = 0;                   
    int j = 0;
    int i = 1;
    while (i < pattern.length())
    {
        if (pattern[i] == pattern[j])
        {   
            d[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            { 
                d[i] = 0;
                i++;
            }
            else
                j = d[j - 1];
        }
    }
}

void KMP_search(string pattern, string text)
{
    int* d = new int[pattern.length()];
    pref_func(pattern, d);
    
    int i = 0, j = 0;
    while (i < text.length())
    {
        if (pattern[j] == text[i])
        {
        	i++;
        	j++;
        }

        if (j == pattern.length())
        { 
            cout << "Found pattern at index: " << i - pattern.length() << endl;
            j = d[j - 1]; 
        } 
        else if (i < text.length() && pattern[j] != text[i]) 
        {
            if (j == 0)
                i++;
            else
                j = d[j - 1];
        }
    }
}

int main()
{
	string str, substr;

	cout << "Text: ";
	cin >> str;
	cout << "Pattern: ";
	cin >> substr;
	
	KMP_search(substr, str);

	return 0;
}