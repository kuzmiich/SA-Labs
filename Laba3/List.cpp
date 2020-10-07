#include <iostream>
#include <cmath>
#include <string>
#include "List.h"
#include "MenuMethods.h"

using namespace std;

int main()
{
	List* listMethods = new List;
	List* beg = nullptr;
	int k, len;
	bool flag = true;
	while (flag)
	{
		menu();
		int key = input();
		system("cls");

		switch (key)
		{
		case 1:
			cout << "Create a list.Enter the number of items in the list:\n";
			k = abs(input_num());
			len = k;
			beg = listMethods->make_list(k);
			break;
		case 2:
			cout << "Enter the number of the list you want to add:\nCount: ";
			k = abs(input_num());
			listMethods->add_point(beg, k);
			break;
		case 3:
			cout << "Enter the number of the list you want to delete:\n";
			k = abs(input_num()) - 1;
			listMethods->del_point(beg, k);
			break;
		case 4:
			cout << "Output elements of the list:\n";
			listMethods->print(beg);
			system("pause");
			break;
		case 5:
			cout << "Sort elements:\n";
			listMethods->print_adr_infoPart_adrPart(beg);
			system("pause");
			break;
		case 6:
			flag = false;
			break;
		default:
			break;
		}
		system("cls");
	}
}