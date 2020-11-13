#include <iostream>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include "huffman.h"
#include "lzw.h"
using namespace std;

string convert_to_string(vector<int> vect)
{
	string res;
	for (int i = 0; i < vect.size(); i++)
	{
		res += vect[i];
	}
	return res;
}
string vector_to_str(vector<int> vect)
{
	ostringstream res;
	if (!vect.empty())
	{
		// Convert all but the last element to avoid a trailing ","
		copy(vect.begin(), vect.end() - 1, ostream_iterator<int>(res, ","));
		// Now add the last element with no delimiter
		res << vect.back();
	}

	return res.str();
}

void enter_file(string path, vector<int> vect)
{
	fstream fout(path, ios::out | ios::trunc);
	if (!fout.is_open())
	{
		cout << "Error, file not open.";
		exit(1);
	}
	for (int i = 0; i < vect.size(); i++)
	{
		fout << vect[i];
	}
	fout.close();
}

void enter_file(string path, string str)
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
		exit(1);
	}
	getline(fout, value);
	fout.close();

	return value;
}

long filesize(string path) {
	fstream fin(path, ios::in);
	if (!fin)
	{
		cout << "Error, file not found.\n";
		exit(1);
	}
	fin.seekg(0, ios::end);
	long size = fin.tellg();
	fin.close();
	return size;
}

double compression_rate(string path1, string path2) {
	return (double)filesize(path1) / filesize(path2);// no compression data / compression data
}

int main()
{
	string path_src = "source.txt";

	string raw = readFile(path_src);
	cout << "Source text: " << raw << endl;
	map<char, int> symbols;

	//init
	for (int i = 0; i < raw.length(); i++)
	{
		symbols[raw[i]]++;
	}
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
		{
			cout << table[itr->first][j];
		}
		cout << endl;
	}

	// print coded string
	string out = "";
	for (int i = 0; i < raw.length(); i++)
	{
		for (int j = 0; j < table[raw[i]].size(); j++)
		{
			out += table[raw[i]][j] + '0';
		}
	}
	string path1 = "out1.bat";

	// decode
	map<vector<bool>, char> ftable;
	for (auto i = table.begin(); i != table.end(); i++)
	{
		ftable[i->second] = i->first;
	}

	enter_file(path1, out);

	cout << "Compression rate: " << compression_rate(path_src, path1) << endl;

    //------------------------~ LWZ ~------------------------------
	string path2 = "out2.bat";
	string str = readFile(path_src);

	cout << "Source text: " << str << endl;

	cout << "Coded:\n";
    vector<int> output_code = encoding(str);

	cout << "Decoded: "; 
	decoding(output_code);

	enter_file(path2, output_code);

	cout << endl;

	cout << "Compression rate: " << compression_rate(path_src, path2) << endl;

    return 0;
}