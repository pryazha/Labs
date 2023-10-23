#include <iostream>
using namespace std;

int n = 8;
int board[8][8];

void setQueen(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		++board[k][j];
		++board[i][k];

		int foo = j - i + k;
		if (foo >= 0 && foo < 8)
			++board[k][foo];

		foo = j + i - k;
		if (foo >= 0 && foo < 8)
			++board[k][foo];
	}
	board[i][j] = -1;
}

void deleteQueen(int i, int j)
{
	for (int k = 0; k < 8; k++)
	{
		--board[k][j];
		--board[i][k];

		int foo = j - i + k;
		if (foo >= 0 && foo < 8)
			--board[k][foo];

		foo = j + i - k;
		if (foo >= 0 && foo < 8)
			--board[k][foo];
	}
	board[i][j] = 0;
}

bool trySetQueen(int i)
{
	bool result = false;
	for (int j = 0; j < n; j++)
	{
		if (board[i][j] == 0)
		{
			setQueen(i, j);
			if (i == 7)
				result = true;
			else
				if (!(result = trySetQueen(i + 1)))
					deleteQueen(i, j);
		}
		if (result)
			break;
	}
	return result;
}

void OutputBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == -1)
				cout << "Q ";
			else
				cout << ". ";
		}
		cout << endl;
	}
}

int main()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;

	trySetQueen(0);
	OutputBoard();

	return 0;
}