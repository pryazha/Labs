#include <iostream>
using namespace std;

int HanoyskBashnya(int n, int start, int point , int temp)
{
	if (n > 0)
	{
		HanoyskBashnya(n - 1, start, temp, point);
		cout << "Перекладываем диск радиуса: " << n << " со стержня " << start << " на стержень " << temp << endl;
		HanoyskBashnya(n - 1, point, start, temp);
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "Кол-во дисков на первом стержне: 5" << endl;

	HanoyskBashnya(5, 1, 2, 3);

	return 0;
}