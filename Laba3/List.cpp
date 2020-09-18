//Вариант 4
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct point
{
	string data; //информационное поле
	point* next; //адресное поле
};

void menu()
{
	cout << "1.Создание списка.\n";
	cout << "2.Добавление элемента в список.\n";
	cout << "3.Удаление элемента из списка.\n";
	cout << "4.Вывод списка.\n";
	cout << "5.Сортировка элементов по алфавиту и по длинне строки\n";
	cout << "6.Выход.\n";
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

point* make_list(int n)
{
	point* beg;
	point* p, * r;//вспомогательные указатели
	beg = new(point);//выделяем память под первый элемент

	//ставим на этот элемент указатель p (последний элемент)
	p = beg;
	for (int i = 0; i < n; i++)
	{
		r = new(point);//создаем новый элемент
		cout << "Введите " << i + 1 << " число:";
		cin >> r->data;
		r->next = 0;
		p->next = r;//связываем p и r
		//ставим на r указатель p (последний элемент)
		p = r;
	}
	return beg;
}

point* sort_insert(point* beg, int len)
{
	for (int i = 0; i < len; i++)
	{

	}
	return beg;
}

point* add_point(point* beg, int k)
{
	point* p = beg;//встали на первый элемент
	point* New = new(point);//создали новый элемент
	cin >> New->data;

	if (k == 0)
	{
		New->next = beg;
		beg = New;
		return beg;
	}

	for (int i = 0; i < k - 1 && p != 0; i++)
	{
		p = p->next;//проходим по списку до(k-1) элемента или до конца
	}

	if (p != 0)//если k-й элемент существует
	{
		New->next = p->next;//связываем New и k-й элемент
		p->next = New;//связываем (k-1)элемент и New
	}
	return beg;
}

point* del_point(point* beg, int k)
//удаление элемента с номером k из списка
{
	point* p = beg;
	if (k == 0)//удаление первого элемента
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//проходим по списку до элемента с номером k-1
	for (int i = 1; i < k && p->next != 0; i++)
	{
		p = p->next;
	}

	/*если такого элемента в списке нет, то возвращаем указатель на начало списка в качестве результата функции*/
	if (p->next == 0) return beg;
	point* r = p->next;
	p->next = r->next;
	delete r;
	return beg;
}

void print(point* beg)
{
	point* p = beg;
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	cout << "\n";
	system("pause");

}

int main()
{
	system("chcp 1251 > nul");
	point* beg = nullptr;
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
			cout << "Сформируйте список.Введите количество элементво списка.\n";
			k = abs(input_num());
			len = k;
			beg = make_list(k);
			break;
		case 2:
			cout << "Введите номер списка, который вы хотите добавить.\n";
			k = abs(input_num());
			add_point(beg, k);
			break;
		case 3:
			cout << "Введите номер списка, который вы хотите удалить.\n";
			k = abs(input_num());
			del_point(beg, k);
			break;
		case 4:
			cout << "Вывод элементов списка.\n";
			print(beg);
			break;
		case 5:
			cout << "Сортировка элементов";
			sort_insert(beg, len);
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