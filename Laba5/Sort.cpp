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
template<typename T>
void merge_sort(T* arr, int len)
{
	int count = 0, changes = 0;
	int mid = len / 2;
	if (len % 2 == 1)
		mid++;
	int h = 1; // step
	int* sequence = new int[len];
	int step;
	while (h < len)
	{
		step = h;
		int i = 0;   // индекс первого пути
		int j = mid; // индекс второго пути
		int k = 0;   // индекс элемента в результирующей последовательности
		while (step <= mid)
		{
			while ((i < step) && (j < len) && (j < (mid + step)))
			{ // пока не дошли до конца пути
			  // заполняем следующий элемент формируемой последовательности
			  // меньшим из двух просматриваемых
				if (arr[i] < arr[j])
				{
					sequence[k] = arr[i];
					i++; k++;
				}
				else {
					sequence[k] = arr[j];
					j++; k++;
				}
				count++;
			}
			while (i < step)
			{ // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
				sequence[k] = arr[i];
				i++; k++;
				count++;
			}
			while ((j < (mid + step)) && (j < len))
			{  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
				sequence[k] = arr[j];
				j++; k++;
				count++;
			}
			step = step + h; // переходим к следующему этапу
			
		}
		h = h * 2;
		// Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
		for (i = 0; i < len; i++)
			arr[i] = sequence[i];
		changes++;
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

	insert_sort(arr, len);

	output_arr(arr, len);
	cout << "\n\n";
	merge_sort(arr, len);

	output_arr(arr, len);
	cout << "\n";
	delete[] arr;
	return 0;
}