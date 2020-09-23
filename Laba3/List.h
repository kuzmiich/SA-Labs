#ifndef MyList
#define MyList

#include <string>
using namespace std;

static struct List
{
	string data; //�������������� ����
	List* next; //�������� ����

	static List* make_list(int n)
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

	static List* sort_insert(List* beg, int len)
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

	static List* add_point(List* beg, int k)
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

	static List* del_point(List* beg, int k)
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

	static void print(List* beg)
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
};

#endif