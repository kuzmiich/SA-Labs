//вариант 14
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void generate_arr(int*, int);

void buble_sort(int* , int);

void max_abs_index_seqen(int*, int);

void max_abs_index_binary(int*, int);

int main()
{
	srand(time(NULL));
	int len;
	cout << "Input size of array: ";
	cin >> len;
	int* arr = new int[len];

	generate_arr(arr, len);

	buble_sort(arr, len);

	max_abs_index_seqen(arr, len);

	max_abs_index_binary(arr, len);

	delete[] arr;
	return 0;
}

void generate_arr(int* arr, int len)
{
	int lower = -100, upper = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() / (upper - lower);
		cout << arr[i] << " ";
	}
	//--generate array
	cout << "\n";
}
//bubble sorting
void buble_sort(int* arr, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (arr[i] < arr[j])
			{
				swap(arr[i], arr[j]);
				count++;
			}
		}
	}
	cout << "Buble sorting, count of operations: " << count << endl;
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

//finding the maximum index in the module using a sequential search
void max_abs_index_seqen(int* arr, int len)
{
	int max = abs(arr[0]);
	int ind = 0, count = 0;
	for (int i = 0; i < len; i++)
	{
		if (abs(arr[i]) > max)
		{
			max = arr[i];
			ind = i;
		}
		count++;
	}
	cout << "Index element " << max << " in array equal = " << ind << endl;
	cout << "Count of iterations: " << count << endl;
}

//finding the maximum index in the module using a binary search
void max_abs_index_binary(int* arr, int len)
{
	int max = abs(arr[0]);
	int count = 0;

	bool flag = false;
	int l = 0;
	int r = len;
	int mid;

	while ((l <= r) && (flag != true)) {
		mid = round((l + r) / 2);

		if (abs(arr[mid]) == max)
			flag = true;

		count++;
		if (abs(arr[mid]) < max)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	if (flag) 
		cout << "Index element " << max << " in array equal = " << mid << endl;
	else 
		cout << "Sorry, but there is no such element in the array\n";

	cout << "Count of iterations: " << count << endl;
}