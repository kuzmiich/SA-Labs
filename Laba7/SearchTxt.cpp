#include <iostream>
using namespace std;

int intDirectSearch(char* string, char* substring) {
    int sl, ssl;
    int res = -1;
    sl = strlen(string);
    ssl = strlen(substring);
    if (sl == 0)
    {
        cout << "The string set incorrectly\n";
    }
    else if (ssl == 0)
    {
        cout << "The substring set incorrectly\n";
    }
    else
    {
        for (int i = 0; i < sl - ssl + 1; i++)
        {
            for (int j = 0; j < ssl; j++)
            {
                if (substring[j] != string[i + j])
                {
                    break;
                }
                else if (j == ssl - 1) {
                    res = i;
                    break;
                }
            }
        }
    }
    return res;
}

int main()
{
    char* str = new char[];
    char* substr = new char[];

    delete[] str, substr;
    return 0;
}
