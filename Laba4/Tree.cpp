#include<iostream>

using namespace std;

struct Point
{
public:
	int data;//информационное поле
	int key;
	Point* left;//адрес левого поддерева
	Point* right;//адрес правого поддерева

private:
	//обход слева направо
	void Run(Point* p)
	{
		if (p)
		{
			//<обработка p->data>
			Run(p->left);//переход к левому поддереву
			Run(p->right);//переход к правому поддереву
		}
	}

	//построение дерева поиска

	Point* first(int d)//формирование первого элемента дерева
	{
		Point* p = new Point;
		p->key = d;
		p->left = 0;
		p->right = 0;
		return p;
	}

	//добавление элемента d в дерево поиска

	Point* Add(Point* root, int d)
	{
		Point* p = root;//корень дерева
		Point* r;
		//флаг для проверки существования элемента d в дереве
		bool ok = false;
		while (p && !ok)
		{
			r = p;
			if (d == p->key)ok = true;//элемент уже существует
			else
				if (d < p->key)p = p->left;//пойти в левое поддерево
				else p = p->right;//пойти в правое поддерево
		}

		if (ok) return p;//найдено, не добавляем
		//создаем узел
		Point* New_point = new Point();//выделили память
		New_point->key = d;
		New_point->left = 0;
		New_point->right = 0;
		// если d<r->key, то добавляем его в левое поддерево
		if (d < r->key)r->left = New_point;
		// если d>r->key, то добавляем его в правое поддерево
		else r->right = New_point;

		return New_point;
	}

	//построение идеально сбалансированного дерева

	Point* Tree(int n, Point* p)
	{
		Point* r;
		int nl, nr;

		if (n == 0) { p = NULL; return p; }

		nl = n / 2;
		nr = n - nl - 1;
		r = new Point;
		cout << "?";
		cin >> r->data;
		r->left = Tree(nl, r->left);
		r->right = Tree(nr, r->right);
		p = r;
		return p;
	}
};



int main()
{
	Point* tree;
	//Point.Add(tree, 10);





	return 0;
}