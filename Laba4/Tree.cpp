#include<iostream>

using namespace std;

struct Point
{
public:
	int data;//�������������� ����
	int key;
	Point* left;//����� ������ ���������
	Point* right;//����� ������� ���������

private:
	//����� ����� �������
	void Run(Point* p)
	{
		if (p)
		{
			//<��������� p->data>
			Run(p->left);//������� � ������ ���������
			Run(p->right);//������� � ������� ���������
		}
	}

	//���������� ������ ������

	Point* first(int d)//������������ ������� �������� ������
	{
		Point* p = new Point;
		p->key = d;
		p->left = 0;
		p->right = 0;
		return p;
	}

	//���������� �������� d � ������ ������

	Point* Add(Point* root, int d)
	{
		Point* p = root;//������ ������
		Point* r;
		//���� ��� �������� ������������� �������� d � ������
		bool ok = false;
		while (p && !ok)
		{
			r = p;
			if (d == p->key)ok = true;//������� ��� ����������
			else
				if (d < p->key)p = p->left;//����� � ����� ���������
				else p = p->right;//����� � ������ ���������
		}

		if (ok) return p;//�������, �� ���������
		//������� ����
		Point* New_point = new Point();//�������� ������
		New_point->key = d;
		New_point->left = 0;
		New_point->right = 0;
		// ���� d<r->key, �� ��������� ��� � ����� ���������
		if (d < r->key)r->left = New_point;
		// ���� d>r->key, �� ��������� ��� � ������ ���������
		else r->right = New_point;

		return New_point;
	}

	//���������� �������� ����������������� ������

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