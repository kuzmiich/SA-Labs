#include<iostream>
#include<ctime>

using namespace std;

void gen_arr(int* arr, int len);

void sum_more_zero(int* arr, int len);

void min_and_max_ind(int* arr, int len);

void out_arr(int* arr, int len);

int main()
{
	srand(time(NULL));
	const unsigned int len = 20;
	int* arr = new int[len];
	
	gen_arr(arr, len);

	sum_more_zero(arr, len);

	min_and_max_ind(arr, len);
	
	out_arr(arr, len);
	delete[]arr;
	return 0;
}

void gen_arr(int* arr, int len)
{
	int lower = -100, upper = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() % (upper - lower);
		cout << arr[i] << " ";
	}
	cout << "\n";
	//--generate array
}

void sum_more_zero(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > 0)
		{
			sum += arr[i];
		}
	}
	cout << "Sum even number(s):" << sum << endl;
}

void min_and_max_ind(int* arr, int len)
{
	int min_ind = 0, max_ind = 0, sum = 0;
	int min = arr[0], max = arr[0];
	for (int i = 0; i < len; i++)
	{
		//--sum
		if (arr[i] < min)
		{
			min = arr[i];
			min_ind = i;
		}
		else if (arr[i] > max)
		{
			max = arr[i];
			max_ind = i;
		}
		//--min, max
	}

	cout << "Min " << min << endl;
	cout << "Max " << max << endl;

	swap(arr[min_ind], arr[max_ind]);
}

void out_arr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	//-Output array
}