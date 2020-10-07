#ifndef MyList
#define MyList

#include <string>
#include <vector>
using namespace std;

static struct NewList
{
	string surname; // information field
	string name;
	string secondName;

	NewList* next = nullptr; // address field

	inline bool space(char c) {
		return isspace(c);
	}

	inline bool notspace(char c) {
		return !isspace(c);
	}
	//break a sentence into words
	vector<string> split(string s) {
		typedef string::const_iterator iter;
		vector<string> res;
		iter i = s.begin();
		while (i != s.end()) {
			i = find_if(i, s.end(), notspace); // find the beginning of a word
			iter j = find_if(i, s.end(), space); // find the end of the same word
			if (i != s.end()) {
				res.push_back(string(i, j)); //insert the word into vector
				i = j; // repeat 1,2,3 on the rest of the line.
			}
		}
		return res;
	}
	//ConvertToNewList
	static NewList ConvertToNewList(List* root, int len)
	{
		string FIO = split(root->FIO);
		NewList edit_root = NewList();

		return edit_root;
	}

	//print list
	static void print(NewList* beg)
	{
		NewList* p = beg;
		p = p->next;
		while (p != 0)
		{
			cout << p->surname << " "
				<< p->name << " "
				<< p->secondName << "\n";

			p = p->next;
		}
		cout << "\n";
	}
};

static struct List
{
	public:
		string FIO;

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
			cout << "Input " << i + 1 << " FIO:\n";

			cin >> r->FIO;

			r->next = 0;
			p->next = r;
			// put the pointer p(the last element) on r
			p = r;
		}
		return beg;
	}
	static void print_adr_infoPart_adrPart(List* root)
	{
		root = root->next;
		while(root)
		{
			cout << root << endl;
			cout << root->FIO << endl;
			cout << root->next << endl;
			root = root->next;
		}

	}
	
	//Add element to list
	static List* add_point(List* root, int k)
	{
		List* p = root;
		List* New = new(List);
		cout << "FIO:\n";
		cin >> New->FIO;

		if (k == 0)
		{
			New->next = root;
			root = New;
			return root;
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
		return root;
	}
	//delete element with number (k)
	static List* del_point(List* root, int k)
	{
		List* p = root;
		if (k == 0)
		{
			root = root->next;
			delete p;
			return root;
		}

		for (int i = 1; i < k && p->next; i++)
		{
			p = p->next;
		}

		if (p->next == 0) 
			return root;
		List* r = p->next;
		p->next = r->next;
		delete r;
		return root;
	}
	//print list
	static void print(List* root)
	{
		List* p = root;
		p = p->next;
		while (p != 0)
		{
			cout << p->FIO << "\n";

			p = p->next;
		}
		cout << "\n";
	}
};
#endif