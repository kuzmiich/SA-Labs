#include <iostream>
using namespace std;

int intDirectSearch(char* str, char* substring) {
    int n, m;
    int res = -1;
    n = strlen(str);
    m = strlen(substring);
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
            Slide[i] = m;// таблица сдвигов заполняется длинной образца
        for (int l = 0; l < m - 1; l++)// в ТС 
        {
            Slide[str[l]] = m - 1 - l;
        }
        int i = m - 1;//позиция правого конца образца

        while (i <= (n - 1))// пока првый конец не достигнет правого конца строки
        {
            int k = 0;// количество совпавших символов
            while (k <= m - 1 && str[m - 1 - k] == substring[i - k])// пока количество совпадений меньше образца и           
            {
                k++;
            }

            if (k == m)                  // проверяем чего это из предыдущего цикла вывалилась программа- на совпадение 
                return i - m + 1;          // если совпадение полное то  возвращаем  позицию первого совпавшего симовола в строке 

            else                       // если не все совпали 
            {
                res = Slide[str[i]] - 1;
                i = i + Slide[str[i]];    //  сдвигаем i(позиция правого конца шаблона) по таблице сдвигов
            }
        }
    }
    return res;
}

int main()
{
    char str[] = "daaga";
    char substr[] = "aga";
    cout << intDirectSearch(str, substr);
    return 0;
}
