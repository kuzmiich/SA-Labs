#include<iostream>
#include<fstream>

using namespace std;
enum{ Enter = 1, Read, Sorting };

const int name_size = 20, number_size = 6, type_size = 5;

struct Aeroflot
{
    char name[name_size] = {};
    char number[number_size] = {};
    char type[type_size] = {};

    static void fprint(Aeroflot* info, int i) {
        cout << "Name place: " << info[i].name << endl;
        cout << "Aircraft number: " << info[i].number << endl;
        cout << "Aircraft time: " << info[i].type << endl;
        cout << endl;
    }
};

void entry_obj(Aeroflot* );

void sort_name(Aeroflot* , int );

void search_identical(Aeroflot* , int );

void enter_file_obj(Aeroflot*, int, string );

int main()
{
    int size = 2;
    Aeroflot* air = {};
    air = new Aeroflot[size];
    
    for (int i = 0; i < size; i++)
    {
        entry_obj(&air[i]);
    }
    string path = "aeroflot.txt";
    enter_file_obj(air, size, path);

    sort_name(air, size);
    
    search_identical(air, size);

    string path2 = "aeroflot1.txt";
    enter_file_obj(air, size, path2);
           
    delete[] air;
	return 0;
}

void entry_obj(Aeroflot* air)
{
    cout << "Enter the name of your flight destination:\n";
    cin.getline(air->name, name_size + 1, '\n');
    cout << "Enter your flight number:\n";
    cin.getline(air->number, number_size + 1, '\n');
    cout << "Enter aircraft type:\n";
    cin.getline(air->type, type_size + 1, '\n');
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

void search_identical(Aeroflot* air, int size)
{
    char arr_new[name_size] = {};
    cout << "Input name place: ";
    cin.getline(arr_new, name_size, '\n');
    system("cls");

    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr_new, air[i].name) == 0)
        {
            cout << "Query: " << arr_new << "\n\nSearch result: \n";
            air->fprint(air, i);
            flag = false;
        }
    }
    if (flag)
    {
        cout << "There are no such flights\n";
    }
}

void enter_file_obj(Aeroflot* air, int size, string path)
{
    fstream out(path, ios_base::out | ios_base::trunc);
    if (!out.is_open())
    {
        cout << "The file cannot be opened or created\n";
        exit(1);
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
}
