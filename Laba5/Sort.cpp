#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int input_num()
{
	char n[255];
	cin.getline(n, 255);
	return atoi(n);
}
// generate array
template<typename T>
void generate_arr(T* arr, int len)
{
	int lower = 100, upper = 1000, step = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = round((lower + rand() % (upper - lower)) / step) * step;
		cout << arr[i] << " ";
	}
	//--generate array
	cout << "\n";
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
//bubble sorting
template<typename T>
void insert_sort(T* arr, int len)
{
	int count = 0, change = 0;

	int temp, j;
	for (int i = 1; i < len; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			arr[j] = temp;
			j--;

			count++;
		}
		change++;
	}
	cout << "Insert sorting:\n";
	cout << "Count of operations: " << count << endl;
	cout << "Count of change: " << change << endl;

}

template <typename T>
void merge(T* arr, int left, int right, int mid)
{
	int j = left;
	int k = mid + 1;
	int len = right - left + 1;

	if (len <= 1) return;

	T* tmp = new T[len];

	for (int i = 0; i < len; ++i) {
		if (j <= mid && k <= right) {
			if (arr[j] < arr[k])
				tmp[i] = arr[j++];
			else
				tmp[i] = arr[k++];
		}
		else {
			if (j <= mid)
				tmp[i] = arr[j++];
			else
				tmp[i] = arr[k++];
		}
	}

	j = 0;
	for (int i = left; i <= right; ++i) {
		arr[i] = tmp[j++];
	}
	delete[] tmp;
}

// A function of the rising of the merger
template <typename T>
void merge_sort(T* arr, int l, int r)
{
	int count = 0, change = 0;
	while (l < r) {
		int m = l + (r - l) / 2;
		while ()
		{
			l = m;
			l = m + 1;

			merge(arr, l, m, r);

		}
	}
	/*cout << "Merge sorting:\n";
	cout << "Count of operations: " << count << endl;
	cout << "Count of change: " << change << endl;*/
}
//sort insert and sort merge
int main()
{
	srand(time(NULL));
	int len;
	cout << "Input size of array: ";
	len = input_num();
	int* arr = new int[len];

	generate_arr(arr, len);

	insert_sort(arr, len);

	output_arr(arr, len);
	cout << "\n\n";
	merge_sort(arr, 1, len+1);

	output_arr(arr, len);
	cout << "\n";
	delete[] arr;
	return 0;
}