//вариант 14
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void max_index(int* , int);

int main()
{
	srand(time(NULL));
	int len;
	cout << "Input size of array: ";
	cin >> len;
	int* arr = new int[len];

	int lower = -100, upper = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() / (upper - lower);
		cout << arr[i] << " ";
	}
	//--generate array
	cout << "\n";

	max_index(arr, len);
    

	delete[] arr;
	return 0;
}

void max_index(int* arr, int len)
{
	int max = arr[0];
	int ind = 0;
	for (int i = 0; i < len; i++)
	{
		if (abs(arr[i]) > max)
		{
			max = abs(arr[i]);
			ind = i;
		}
	}
	cout << "Min index = " << ind << endl;
}