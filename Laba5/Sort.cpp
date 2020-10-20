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
	}
}
//output array
template<typename T>
void rewrite_arr(T* new_arr, T* arr, T len)
{
	for (int i = 0; i < len; i++)
	{
		new_arr[i] = arr[i];
	}
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
	cout << "\nInsert sorting:\n";
	cout << "Count of operations: " << count << endl;
	cout << "Count of change: " << change << endl;

}
template <typename T>
T* merge(T* buf1, T* buf2, int len_1, int len_2)
{
	T* res = new T[len_1 + len_2];
	int n = 0;
	// Сливаем массивы, пока один не закончится
	while (len_1 && len_2) {
		if (*buf1 < *buf2) {
			res[n] = *buf1;
			buf1++;
			--len_1;
		}
		else {
			res[n] = *buf2;
			++buf2;
			--len_2;
		}
		++n;
	}
	// Если закончился первый массив
	if (len_1 == 0) {
		for (int i = 0; i < len_2; ++i) {
			res[n++] = *buf2++;
		}
	}
	else { // Если закончился второй массив
		for (int i = 0; i < len_1; ++i) {
			res[n++] = *buf1++;
		}
	}
	return res;
}

// Функция восходящего слияния
template <typename T>
void mergeSort(T* arr, int len)
{
	int count = 0, changes = 0;
	int n = 1, k, ost;
	T* buf;
	while (n < len) {
		k = 0;
		while (k < len) {
			if (k + n >= len)
			{
				break;
			}
			ost = (k + n * 2 > len) ? (len - (k + n)) : n;

			buf = merge(arr + k, arr + k + n, n, ost);
			count += 2;
			for (int i = 0; i < n + ost; ++i)
			{
				arr[k + i] = buf[i];
			}
			delete[] buf;
			k += n * 2;
			changes++;
		}
		n *= 2;
	}
	cout << "Merge sorting:\n";
	cout << "Count of operations: " << count << endl;
	cout << "Count of change: " << changes << endl;
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
	output_arr(arr, len);

	cout << "\n";

	insert_sort(arr, len);

	output_arr(arr, len);

	cout << "\n\n";

	int* new_arr = new int[len];
	rewrite_arr(new_arr, arr, len);
	delete[] arr;
	mergeSort(new_arr, len);

	output_arr(new_arr, len);

	cout << "\n";
	delete[] new_arr;
	return 0;
}