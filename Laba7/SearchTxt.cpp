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
            Slide[i] = m;// ������� ������� ����������� ������� �������
        for (int l = 0; l < m - 1; l++)// � �� 
        {
            Slide[str[l]] = m - 1 - l;
        }
        int i = m - 1;//������� ������� ����� �������

        while (i <= (n - 1))// ���� ����� ����� �� ��������� ������� ����� ������
        {
            int k = 0;// ���������� ��������� ��������
            while (k <= m - 1 && str[m - 1 - k] == substring[i - k])// ���� ���������� ���������� ������ ������� �           
            {
                k++;
            }

            if (k == m)                  // ��������� ���� ��� �� ����������� ����� ���������� ���������- �� ���������� 
                return i - m + 1;          // ���� ���������� ������ ��  ����������  ������� ������� ���������� �������� � ������ 

            else                       // ���� �� ��� ������� 
            {
                res = Slide[str[i]] - 1;
                i = i + Slide[str[i]];    //  �������� i(������� ������� ����� �������) �� ������� �������
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
