#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//protection against incorrect input
int input_num()
{
	char n[255];
	cin.getline(n, 255);
	return atoi(n);
}
//output array
template<typename T>
void output_arr(T* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
}
// generate array
template<typename T>
void generate_arr(T* arr, int len)
{
	int lower = -100, upper = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() % (upper - lower);
	}
}
//bubble sorting
template<typename T>
void buble_sort(T* arr, int len)
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
}

//finding the maximum index in the module using a sequential search
template<typename T>
int max_of_seqen(T* arr, int len)
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
	cout << "Index element in absolute value " << max << " in array = " << ind << endl;
	cout << "Count of iterations: " << count << endl;
	return ind;
}

//finding the maximum index in the module using a binary search
template<typename T>
int max_of_binary(T* arr, int len)
{
	int max = abs(arr[0]);
	int count = 0;

	bool flag = false;
	int l = 0;
	int r = len;
	int mid = len/2;

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

	if (flag) {
		cout << "Index element in absolute value " << max << " in array = " << mid << endl;
	}
	else
	{
		cout << "Sorry, but there is no such element in the array\n";
	}
	cout << "Count of iterations: " << count << endl;
	return mid;
}

int main()
{
	srand(time(NULL));
	cout << "Input size of array: ";
	int len = input_num();
	int* arr = new int[len];

	generate_arr(arr, len);
	output_arr(arr, len);

	cout << "\n\n";

	buble_sort(arr, len);
	output_arr(arr, len);

	cout << "\n\n";

	int sequen = max_of_seqen(arr, len);

	cout << "\n\n";

	int binary = max_of_binary(arr, len);

	if (binary != sequen)
	{
		cout << "Binary search work false\n";
	}
	delete[] arr;
	return 0;
}