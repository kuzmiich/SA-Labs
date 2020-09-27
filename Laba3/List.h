#ifndef MyList
#define MyList

#include <string>
using namespace std;

static struct List
{
	public:
		string data; // information field
		List* next = nullptr; // address field
	
	// create start list
	static List* make_list(int n)
	{
		List* beg;
		List* p, * r;
		beg = new(List);
		// putting the pointer p on the last element
		p = beg;
		for (int i = 0; i < n; i++)
		{
			r = new(List);
			cout << "Input " << i + 1 << " string:";
			cin >> r->data;
			r->next = 0;
			p->next = r;
			// put the pointer p(the last element) on r
			p = r;
		}
		return beg;
	}
	//buble sort
	static void buble_sort(List* beg, int len)
	{
		List* first = beg, * second = beg;
		while(first)
		{
			while(second)
			{
				if (beg->data < beg->next->data)
				{
					string tmp = first->next->data;
					first->data = second->next->data;
					second->data = tmp;
				}
			}
		}
	}
	//Add element to list
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

		if (p != 0)
		{
			New->next = p->next;
			p->next = New;
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
	//print list
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