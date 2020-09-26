#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void generate_arr(int*, int);

void out_arr(int* arr, int len);

void insert_sort(int* arr, int len);

void merge_sort(int* arr, int len);

//sort insert and sort merge
int main()
{
	srand(time_t(NULL));
	int len;
	cout << "Input size of array: ";
	cin >> len;
	int* arr = new int[len];

	generate_arr(arr, len);

	insert_sort(arr, len);

	out_arr(arr, len);
	cout << "\n\n";

	//merge_sort(arr, len);

	delete[] arr;
	return 0;
}
// generate array
void generate_arr(int* arr, int len)
{
	int lower = 100, upper = 1000, step = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() / (upper - lower);
		cout << arr[i] << " ";
	}
	//--generate array
	cout << "\n";
}
//output array
void out_arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}
//bubble sorting
void insert_sort(int* arr, int len)
{
	int count = 0, change = 0;

	int temp, item;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		item = i - 1;
		while (item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];
			arr[item] = temp;
			item--;

			count++;
		}
		change++;
	}
	cout << "Insert sorting:\n";
	cout << "Count of operations: " << count << endl;
	cout << "Count of change: " << change << endl;
	
}

void merge_sort(int* arr, int len)
{
	int count = 0, change = 0;
	for (int i = 0; i < len; i++)
	{
		
	}
	cout << "Buble sorting, count of operations: " << count << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}
