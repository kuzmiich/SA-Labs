#ifndef MyList
#define MyList

#include <string>
using namespace std;

static struct List
{
	private:
		List* tmp = NULL;
	public:
		string data; //информационное поле
		List* next; //адресное поле
	
	//create
	static List* make_list(int n)
	{
		List* beg;
		List* p, * r;
		beg = new(List);

		//ставим на этот элемент указатель p (последний элемент)
		p = beg;
		for (int i = 0; i < n; i++)
		{
			r = new(List);//создаем новый элемент
			cout << "Input " << i + 1 << " string:";
			cin >> r->data;
			r->next = 0;
			p->next = r;//связываем p и r
			//ставим на r указатель p (последний элемент)
			p = r;
		}
		return beg;
	}
	//buble sort
	static List* sort_insert(List* beg, int len)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (beg->data < beg->next)
				{
					tmp = beg->next;
					beg->data = beg->next;
					beg->data = tmp;
				}
			}
		}
	}
	//Add
	static List* add_point(List* beg, int k)
	{
		List* p = beg;
		List* New = new(List);
		cin >> New->data;

		if (k == 0)
		{
			New->next = beg;
			beg = New;
			return beg;
		}

		for (int i = 0; i < k - 1 && p != 0; i++)
		{
			p = p->next;
		}

		if (p != 0)//если k-й элемент существует
		{
			New->next = p->next;//связываем New и k-й элемент
			p->next = New;//связываем (k-1)элемент и New
		}
		return beg;
	}
	//delete element with number (k)
	static List* del_point(List* beg, int k)
	{
		List* p = beg;
		if (k == 0)
		{
			beg = beg->next;
			delete p;
			return beg;
		}

		for (int i = 1; i < k && p->next; i++)
		{
			p = p->next;
		}

		if (p->next == 0) 
			return beg;
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