#include "Money.h"

int make_file(const char* fname) {
	fstream stream(fname, ios::out | ios::trunc);
	if (!stream)
		return -1;
	int count;
	Money temp;
	cout << "Number Of elements: ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> temp;
		stream << temp << "\n";
	}
	stream.close();
	return count;
}

int print_file(const char* fname) {
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	Money temp;
	int i = 0;
	while (stream >> temp) {
		cout << temp;
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* fname, int K) {
	fstream temp("temp.txt", ios::out);
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	int i = 0;
	Money m;
	while (stream >> m) {
		if (stream.eof())
			break;
		i++;
		if (i != K)
			temp << m;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp.txt", fname);
	return i;
}

int add_file(const char* fname, int K, Money newM) {
	fstream temp("temp.txt", ios::out);
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	Money m;
	int i = 0, count = 0;
	while (stream >> m) {
		if (stream.eof())
			break;
		i++;
		if (i == K) {
			temp << newM;
			count++;
		}
		temp << m;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp.txt", fname);
	return count;
}

int add_end(const char* fname, Money newM) {
	fstream stream(fname, ios::app);
	if (!stream)
		return -1;
	stream << newM;
	return 1;
}

int change_file(const char* fname, int K, Money newM) {
	fstream temp("temp.txt", ios::out);
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	Money m;
	int i = 0, count = 0;
	char choice;
	while (stream >> m) {
		if (stream.eof())
			break;
		i++;
		if (i == K) {
			cout << m << " - changing... Continue[y/n]\n";
			cin >> choice;
			if (choice == 'n' || choice == 'N')
				break;
			temp << newM;
			count++;
		}
		else
			temp << m;
	}
	stream.close();
	temp.close();
	remove(fname);
	rename("temp.txt", fname);
	return count;
}

int delete_range(const char* fname, const Money& k1, const  Money& k2) {
	fstream temp("temp.txt", ios::out);
	fstream stream(fname, ios::in);
	if (!stream)
		return -1;
	Money m;
	int i = 0;
	while (stream >> m) {
		if (stream.eof())
			break;

	}
}