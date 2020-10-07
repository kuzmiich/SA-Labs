#ifndef Menu
#define Menu

#include <iostream>
using namespace std;

void menu()
{
	cout << "1.Create list\n";
	cout << "2.Add element for list\n";
	cout << "3.Delete element for list\n";
	cout << "4.Output list\n";
	cout << "5.Sort items alphabetically and by the length of the string\n";
	cout << "6.Exit\n";
}

int input()
{
	char n[255];
	cin.getline(n, 255);
	return atoi(n);
}

int input_num()
{
	char n[255];
	cin.getline(n, 255);
	return atoi(n);
}
#endif