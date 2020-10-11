#ifndef Haffman
#define Haffman

using namespace std;

const int MAX_SYM = 256;

class Huf
{
public:
	int count;
	char symbol;
	Huf* left;
	Huf* right;

	Huf() { }

	Huf(char __symbol, int __count)
	{
		symbol = __symbol;
		count = __count;
	}

	Huf(Huf* l, Huf* r) // create parent
	{
		symbol = 0;
		left = l;
		right = r;
		count = l->count + r->count;
	}
};

void Print(Huf* root, int depth = 0)
{
	if (!root) return;

	if (root->symbol)
	{
		for (int i = 0; i < depth; i++)
			cout << ".";
		cout << root->symbol << endl;
	}
	else depth++;
	Print(root->left, depth);
	Print(root->right, depth);
}

void BuildTable(Huf* root, vector<bool>& code, map<char, vector<bool>>& table) // dfs
{
	if (root->left)
	{
		code.push_back(0); // left
		BuildTable(root->left, code, table);
	}

	if (root->right)
	{
		code.push_back(1); // right
		BuildTable(root->right, code, table);
	}

	if (root->symbol)
		table[root->symbol] = code;
	if (code.size())
		code.pop_back();
}

bool SortHuf(const Huf* a, const Huf* b)
{
	return a->count < b->count;
}

string Decode(string& str, map<vector<bool>, char>& table) // flipped table: code - char pairs
{
	string out = "";
	vector<bool> code;
	for (int i = 0; i < str.length(); i++)
	{
		code.push_back(str[i] == '0' ? false : true);
		if (table[code])
		{
			out += table[code];
			code.clear();
		}
	}
	return out;
}

void enterFile(string path, string str)
{
    fstream fout(path, ios::out | ios::trunc);
    if (!fout.is_open())
    {
        cout << "Error, file not open.";
        exit(1);
    }
    fout << str;
    fout.close();
}
string readFile(string path)
{
    string value;
    fstream fout(path, ios::in);
    if (!fout.is_open())
    {
        cout << "Error, file not open.\n";
        return "";
    }
    getline(fout, value);
    fout.close();

    return value;
}
#endif