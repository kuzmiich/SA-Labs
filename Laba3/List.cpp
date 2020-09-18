//������� 4
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct List
{
	string data; //�������������� ����
	List* next; //�������� ����
};

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

List* make_list(int n)
{
	List* beg;
	List* p, * r;//��������������� ���������
	beg = new(List);//�������� ������ ��� ������ �������

	//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	for (int i = 0; i < n; i++)
	{
		r = new(List);//������� ����� �������
		cout << "Input " << i + 1 << " string:";
		cin >> r->data;
		r->next = 0;
		p->next = r;//��������� p � r
		//������ �� r ��������� p (��������� �������)
		p = r;
	}
	return beg;
}

List* sort_insert(List* beg, int len)
{
	List* res = new List;
	res->next = NULL;
	res->data = beg->data;
	while (res->data.find(res->data))
	{
		res->next;
	}
	return res;
}

List* add_point(List* beg, int k)
{
	List* p = beg;//������ �� ������ �������
	List* New = new(List);//������� ����� �������
	cin >> New->data;

	if (k == 0)
	{
		New->next = beg;
		beg = New;
		return beg;
	}

	for (int i = 0; i < k - 1 && p != 0; i++)
	{
		p = p->next;//�������� �� ������ ��(k-1) �������� ��� �� �����
	}

	if (p != 0)//���� k-� ������� ����������
	{
		New->next = p->next;//��������� New � k-� �������
		p->next = New;//��������� (k-1)������� � New
	}
	return beg;
}

List* del_point(List* beg, int k)
//�������� �������� � ������� k �� ������
{
	List* p = beg;
	if (k == 0)//�������� ������� ��������
	{
		beg = beg->next;
		delete p;
		return beg;
	}
	//�������� �� ������ �� �������� � ������� k-1
	for (int i = 1; i < k && p->next != 0; i++)
	{
		p = p->next;
	}

	/*���� ������ �������� � ������ ���, �� ���������� ��������� �� ������ ������ � �������� ���������� �������*/
	if (p->next == 0) return beg;
	List* r = p->next;
	p->next = r->next;
	delete r;
	return beg;
}

void print(List* beg)
{
	List* p = beg;
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
			beg = make_list(k);
			break;
		case 2:
			cout << "Enter the number of the list you want to add:\n";
			k = abs(input_num());
			add_point(beg, k);
			break;
		case 3:
			cout << "Enter the number of the list you want to delete:\n";
			k = abs(input_num());
			del_point(beg, k);
			break;
		case 4:
			cout << "Output elements of the list:\n";
			print(beg);
			break;
		case 5:
			cout << "Sort elements:\n";
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