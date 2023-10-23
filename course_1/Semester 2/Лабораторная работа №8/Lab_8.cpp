#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>

using namespace std;

struct CarOwner
{
	string FullName;
	string VechicleNumber;
	int TechPasNumber = 0;
	string DepOfReg;
};

void showFile(FILE* file, int size)
{
	if (file == NULL)
	{
		cout << "File opening error";
		return;
	}

	CarOwner* arr = new CarOwner[size];
	fread(arr, sizeof(CarOwner), size, file);

	for (int i = 0; i < size; i++)
	{
		cout << "FullName: " << arr[i].FullName << endl;
		cout << "Vechicle number: " << arr[i].VechicleNumber << endl;
		cout << "Registration number: " << arr[i].TechPasNumber << endl;
		cout << "Department of registration: " << arr[i].DepOfReg << endl;
		cout << endl;
	}

	delete[] arr;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* file;

	int NumOfElem;
	cout << "Enter number of elements to be added to the file: ";
	cin >> NumOfElem;

	CarOwner* Drivers = new CarOwner[NumOfElem];

	file = fopen("file.txt", "w");
	for (int i = 0; i < NumOfElem; i++)
	{
		cout << "Fullname: ";
		cin >> Drivers[i].FullName;
		cout << "Vechicle number: ";
		cin >> Drivers[i].VechicleNumber;
		cout << "Registration number: ";
		cin >> Drivers[i].TechPasNumber;
		cout << "Department of registration: ";
		cin >> Drivers[i].DepOfReg;
		cout << endl;
	}
	fwrite(Drivers, sizeof(CarOwner), NumOfElem, file);
	fclose(file);

	// Удаление элемента с заданным номером

	string NumOfVechicle;
	cout << "Enter the number of the vehicle to be deleted: ";
	cin >> NumOfVechicle;
	cout << endl;

	int* index = new int[NumOfElem];
	int tempNum = 0;
	for (int i = 0; i < NumOfElem; i++)
		if (Drivers[i].VechicleNumber != NumOfVechicle)
		{
			index[i] = 1;
			tempNum++;
		}

	CarOwner* tempArr = new CarOwner[tempNum];
	int tempNum_index = 0;
	for (int i = 0; i < NumOfElem && tempNum_index < tempNum; i++)
		if (index[i] == 1)
		{
			tempArr[tempNum_index] = Drivers[i];
			tempNum_index++;
		}
		
	NumOfElem = tempNum;
	file = fopen("file.txt", "w");
	fwrite(tempArr, sizeof(CarOwner), NumOfElem, file);
	fclose(file);
	delete[] index;
	delete[] tempArr;
	delete[] Drivers;
	cout << "	File data: " << endl;
	file = fopen("file.txt", "r");
	showFile(file, NumOfElem);
	fclose(file);

	// Добавление двух элементов с заданной фамилией

	string surname;
	cout << "Enter the last name of the element before which 2 elements will be added: ";
	cin >> surname;

	tempArr = new CarOwner[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "Fullname: ";
		cin >> tempArr[i].FullName;
		cout << "Vechicle number: ";
		cin >> tempArr[i].VechicleNumber;
		cout << "Registration number: ";
		cin >> tempArr[i].TechPasNumber;
		cout << "Department of registration: ";
		cin >> tempArr[i].DepOfReg;
		cout << endl;
	}

	Drivers = new CarOwner[NumOfElem];
	file = fopen("file.txt", "r");
	fread(Drivers, sizeof(CarOwner), NumOfElem, file);
	fclose(file);

	int ind = 0;
	for (int i = 0; i < NumOfElem; i++)
	{
		string tempStr = Drivers[i].FullName;
		string name = "";
		int j = 0;
		while (tempStr[j] != '_')
		{
			name += tempStr[j];
			j++;
		}
		if (name == surname)
		{
			cout << "ind = " << ind << endl;
			ind = i;
		}
		name = "";
	}
	
	NumOfElem += 2;
	CarOwner* temp = new CarOwner[NumOfElem];
	int i = 0;
	while (i < ind)
	{
		temp[i] = Drivers[i];
		i++;
	}
	i += 2;
	temp[i - 1] = tempArr[1];
	temp[i - 2] = tempArr[0];
	while (i < NumOfElem)
	{
		temp[i] = Drivers[i - 2];
		i++;
	}

	file = fopen("file.txt", "w");
	fwrite(temp, sizeof(CarOwner), NumOfElem, file);
	fclose(file);

	cout << "	File data: " << endl;
	file = fopen("file.txt", "r");
	showFile(file, NumOfElem);
	fclose(file);

	return 0;
}