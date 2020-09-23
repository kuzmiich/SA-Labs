#ifndef MyList
#define MyList

#include <string>
using namespace std;

static struct List
{
	string data; //информационное поле
	List* next; //адресное поле

	static List* make_list(int n)
	{
		List* beg;
		List* p, * r;//вспомогательные указатели
		beg = new(List);//выделяем память под первый элемент

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
		List* p = beg;//встали на первый элемент
		List* New = new(List);//создали новый элемент
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

	static List* del_point(List* beg, int k)
		//удаление элемента с номером k из списка
	{
		List* p = beg;
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