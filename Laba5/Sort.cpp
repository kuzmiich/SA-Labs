#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

// generate array
template<typename T>
void generate_arr(T* arr, int len)
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
template<typename T>
void out_arr(T* arr, int len)
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
	if (l < r) {
		int m = l + (r - l) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
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
	merge_sort(arr, 1, len+1);

	out_arr(arr, len);
	cout << "\n";
	delete[] arr;
	return 0;
}