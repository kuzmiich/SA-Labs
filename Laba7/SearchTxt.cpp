#include <iostream>
using namespace std;

int sequenSearch(char* string, char* substring) {
    int count = 0;
    int res = -1;
    int size_str = strlen(string);
    int size_substr = strlen(substring);
    if (size_str == 0)
    {
        cout << "The string set incorrectly\n";
    }
    else if (size_substr == 0)
    {
        cout << "The substring set incorrectly\n";
    }
    else
    {
        for (int i = 0; i < size_str - size_substr + 1; i++) {
            for (int j = 0; j < size_substr; j++) {
                if (substring[j] != string[i + j])
                {
                    break;
                }
                else if (j == size_substr - 1) {
                    res = i;
                    count++;
                    break;
                }
            }
        }
    }
             
    return count;
}

int BMXSearch(char* str, char* substring) {
    int count = 0;
    int res = -1;
    int n = strlen(str);
    int m = strlen(substring);
    if (n == 0)
    {
        cout << "The string set incorrectly\n";
    }
    else if (m == 0)
    {
        cout << "The substring set incorrectly\n";
    }
    else
    {
        const int N = 255;
        int Slide[N];
        for (int i = 0; i < N; i++)
        {
            Slide[i] = m;// таблица сдвигов заполняется длинной образца
        }

        for (int l = 0; l < m - 1; l++)
        {
            Slide[str[l]] = m - 1 - l;
        }
        int right = m - 1;//позиция правого конца образца

        while (right <= (n - 1))// пока првый конец не достигнет правого конца строки
        {
            int k = 0;// количество совпавших символов
            while (k <= m - 1 && str[m - 1 - k] == substring[right - k])
            {
                k++;
            }

            if (k == m)
            {
                return right - m + 1;          // если совпадение полное то  возвращаем  позицию первого совпавшего симовола в строке 
            }
            else                       // если не все совпали 
            {
                res = Slide[str[right]] - 1;
                right = right + Slide[str[right]];    //  сдвигаем i(позиция правого конца шаблона) по таблице сдвигов    
            }
            count++;
        }
    }
    return count;
}

int main()
{
    int size_str = 255;
    char* str = new char[size_str];
    cout << "Input string:";
    cin.getline(str, size_str);

    const int size_substr = 50;
    char* substr = new char[size_substr];
    cout << "Input substring:";
    cin.getline(substr, size_substr);

    cout << "Counting the number of character comparisons: " << sequenSearch(str, substr) << endl;
    cout << "Counting the number of character comparisons: " << BMXSearch(str, substr) << endl;
    delete str, substr;
    return 0;
}
