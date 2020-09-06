// вариант 4
#include<iostream>
#include<fstream>
using namespace std;
enum{ Enter = 1, Read, Sorting, Search };

const int n = 40;
const int name_size = 20, number_size = 6, type_size = 5;

struct Aeroflot
{
    char name[name_size] = {};
    char number[number_size] = {};
    char type[type_size] = {};
};
void menu();

void entry_obj(Aeroflot* );

void sort_name(Aeroflot* , int );

void search_identical(Aeroflot* , int );

void fprint(Aeroflot* , int , int );

int main()
{
    int size = 1;
    Aeroflot* air = {};
    air = new Aeroflot[size];

    int key = true;
    while (key)
    {
        system("cls");
        menu();
        cin >> key;

        switch(key)
        {
        case Enter:
        {
            for (int i = 0; i < size; i++)
            {
                entry_obj(&air[i]);
            }
            fstream out("aeroflot.txt", ios_base::out | ios_base::trunc);
            if (!out.is_open()) // если файл не был открыт
            {
                cout << "The file cannot be opened or created\n";
                return 1;
            }
            for (int i = 0; i < size; i++)
            {
                out << "Name of flight destionation:";
                out.write((char*)&air[i].name, sizeof air[i].name);
                out << "Flight number:";
                out.write((char*)&air[i].number, sizeof air[i].number);
                out << "Aircraft type:";
                out.write((char*)&air[i].type, sizeof air[i].type);
                out << '\n';
            }
            out.close();
            system("pause");
            break;
        }
        case Read:
        {
            fstream out("aeroflot.txt", ios_base::out | ios_base::trunc);
            if (!out.is_open()) // если файл не был открыт
            {
                cout << "The file cannot be opened or created\n";
                return 1;
            }
            for (int i = 0; i < size; i++)
            {
                out << "Name of flight destionation:";
                out.write((char*)&air[i].name, sizeof air[i].name);
                out << "Flight number:";
                out.write((char*)&air[i].number, sizeof air[i].number);
                out << "Aircraft type:";
                out.write((char*)&air[i].type, sizeof air[i].type);
                out << '\n';
            }
            out.close();
            system("pause");
            break;
        }
        case Sorting:
        {
            sort_name(air, size);
            fstream fout("aeroflot1.txt", ios_base::out | ios_base::trunc);
            if (!fout.is_open()) // если файл не был открыт
            {
                cout << "The file cannot be opened or created\n";
                return 1;
            }
            for (int i = 0; i < size; i++)
            {
                fout << "Name of flight destionation:";
                fout.write((char*)&air[i].name, sizeof air[i].name);
                fout << "Flight number:";
                fout.write((char*)&air[i].number, sizeof air[i].number);
                fout << "Aircraft type:";
                fout.write((char*)&air[i].type, sizeof air[i].type);
                fout << '\n';
            }
            fout.close();
            system("pause");
            break;
        }
        case Search:
            search_identical(air, size);
            break;
        default:
            break;
        }
    }
    delete[] air;
	return 0;
}

void menu()
{
    cout << "1.Enter data to file\n";
    cout << "2.Read data from file\n";
    cout << "3.Sorting of the flights in alphabetical order\n";
    cout << "4.Search for flight numbers and aircraft types\n";
    cout << "0.Exit\n";
}

void entry_obj(Aeroflot* air)
{
    cout << "Enter the name of your flight destination:\n";
    cin.ignore();
    cin.getline(air->name, name_size, '\n');
    cout << "Enter your flight number:\n";
    cin.getline(air->number, number_size, '\n');
    cout << "Enter aircraft type:\n";
    cin.getline(air->type, type_size, '\n');
}

//selection sort
void sort_name(Aeroflot* air, int size)
{
    int change = 0, compare = 0;
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(air[j].name, air[min_index].name) < 0)
            {
                min_index = j;
                compare++;
            }
        }
        swap(air[i], air[min_index]);
        change++;
    }
    cout << "Count compares: " << compare << endl;
    cout << "Count changes: " << change << endl;
    cout << "Selection sorting completed successfully\n";
}

void search_identical(Aeroflot* arr, int size)
{
    char arr_new[n];
    cout << "Input name place: ";
    cin.ignore();
    cin.getline(arr_new, n);
    system("cls");

    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr_new, arr[i].name) == 0)
        {
            cout << "Query: " << arr_new << "\n\nSearch result: \n";
            fprint(arr, size, i);
            flag = false;
        }
    }
    if (flag)
    {
        cout << "There are no such flights";
    }
}

void fprint(Aeroflot* info, int size, int i) {
    cout << "Name place: " << info[i].name << endl;
    cout << "Aircraft number: " << info[i].number << endl;
    cout << "Aircraft time: " << info[i].type << endl;
    cout << endl;
}