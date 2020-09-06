//������� 4
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct point
{
	int data; //�������������� ����
	point* next; //�������� ����
};

void menu()
{
	cout << "1.�������� ������.\n";
	cout << "2.���������� �������� � ������.\n";
	cout << "3.�������� �������� �� ������.\n";
	cout << "4.����� ������.\n";
	cout << "5.�����.\n";
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
	point* p, * r;//��������������� ���������
	beg = new(point);//�������� ������ ��� ������ �������
	cout << "������ �������� ��������������� ����.\n";
	cin >> beg->data;//������ �������� ��������������� ����
	beg->next = 0;//�������� �������� ����
	//������ �� ���� ������� ��������� p (��������� �������)
	p = beg;
	for (int i = 0; i < n; i++)
	{
		r = new(point);//������� ����� �������
		cout << "������� " << i + 1 << " �����:";
		cin >> r->data;
		r->next = 0;
		p->next = r;//��������� p � r
		//������ �� r ��������� p (��������� �������)
		p = r;
	}
	return beg;
}

point* add_point(point* beg, int k)
{
	point* p = beg;//������ �� ������ �������
	point* New = new(point);//������� ����� �������
	cout << "Key?"; cin >> New->data;

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

point* del_point(point* beg, int k)
//�������� �������� � ������� k �� ������
{
	point* p = beg;
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
	point* r = p->next;//������ ��������� r �� k-� �������
	p->next = r->next;//��������� k-1 � k+1 �������
	delete r;//������� k-� ������� �� ������
	return beg;
}

void print_list(point* beg)
{
	point* p = beg;
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;
	}
	system("pause");
}

int main()
{
	system("chcp 1251 > nul");
	point* beg = nullptr;
	int k;
	bool flag = true;
	while (flag)
	{
		menu();
		int key = input();
		system("cls");

		switch (key)
		{
		case 1:
			cout << "����������� ������.������� ���������� ��������� ������.\n";
			k = abs(input_num());
			beg = make_list(k);
			break;
		case 2:
			cout << "������� ����� ������, ������� �� ������ ��������.\n";
			k = abs(input_num());
			add_point(beg, k);
			break;
		case 3:
			cout << "������� ������, ������� �� ������ �������.\n";
			k = abs(input_num());
			del_point(beg, k);
			break;
		case 4:
			cout << "����� ��������� ������.\n";
			print_list(beg);
			break;
		case 5:
			flag = false;
			break;
		default:
			break;
		}
		system("cls");
	}
}