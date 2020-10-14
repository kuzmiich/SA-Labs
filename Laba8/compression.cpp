#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include "huffman.h"
#include "lzw.h"
using namespace std;
string getString(vector<int> vect)
{
	string str = "";
	for (int i = 0; i < vect.size(); i++)
	{
		str += vect[i];
	}
	return str;
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

int filesize(string path) {
	fstream fin(path, ios::in);
	if (!fin)
	{
		cout << "Error, file not found.\n";
		exit(1);
	}
	fin.seekg(0, ios::end);
	int size = fin.tellg();
	fin.close();
	return size;
}

double compressionRate(string path1, string path2) {
	return (double)filesize(path2) / filesize(path1);
}

int main()
{
	string path_src = "source.txt";

	string raw = readFile(path_src);
	cout << raw << endl;
	map<char, int> symbols;

	//init
	for (int i = 0; i < raw.length(); i++)
		symbols[raw[i]]++;
	//!init

	list<Huf*> trees;
	map<char, int>::iterator itr;
	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		Huf* p = new Huf(itr->first, itr->second); // key = symbol;  value = count
		trees.push_back(p);
	}

	while (trees.size() != 1)
	{
		trees.sort(SortHuf);

		Huf* l = trees.front();
		trees.pop_front();
		Huf* r = trees.front();
		trees.pop_front();

		Huf* parent = new Huf(l, r);
		trees.push_back(parent);
	}

	Huf* root = trees.front();
	Print(root);

	vector<bool> code; // buffer
	map<char, vector<bool>> table;
	BuildTable(root, code, table); // generate symbol-code key-value pair

	for (itr = symbols.begin(); itr != symbols.end(); itr++)
	{
		cout << itr->first << " - ";
		for (int j = 0; j < table[itr->first].size(); j++)
			cout << table[itr->first][j];
		cout << endl;
	}

	// print coded string
	string out = "";
	for (int i = 0; i < raw.length(); i++)
		for (int j = 0; j < table[raw[i]].size(); j++)
		{
			out += table[raw[i]][j] + '0';
		}
	string path1 = "out1.txt";

	// decode
	map<vector<bool>, char> ftable;
	for (auto i = table.begin(); i != table.end(); i++)
		ftable[i->second] = i->first;

	enterFile(path1, out);

	cout << "Compression rate: " << compressionRate(path_src, path1) << endl;

	enterFile(path1, out + "\n" + Decode(out, ftable));

    //------------------------~ LWZ ~------------------------------
	string path2 = "out2.txt";
	string str = readFile(path_src);

	cout << str << endl;

    vector<int> output_code = encoding(str);

	enterFile(path2, getString(output_code));

	cout << "Compression rate: " << compressionRate(path_src, path2) << endl;

    decoding(output_code);

	enterFile(path2, "Coded: " + getString(output_code));
	enterFile(path2, "\nDecoded:" + decoding(output_code));
    return 0;
}
