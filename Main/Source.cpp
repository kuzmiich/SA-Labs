// вариант 14
#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	const unsigned int len = 20;
	int arr[len];
	int lower = -100, upper = 100;
	for (int i = 0; i < len; i++)
	{
		arr[i] = lower + rand() / (upper - lower);
		cout << arr[i] << " ";
	}
	//--generate array
	cout << "\n";

	int min_ind = 0, max_ind = 0, sum = 0;
	int min = arr[0], max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > 0)
		{
			sum += arr[i];
		}
		//--sum
		if (arr[i] < min)
		{
			min = arr[i];
			min_ind = i;
		}
		else if(arr[i] > max)
		{
			max = arr[i];
			max_ind = i;
		}
		//--min, max
	}
	cout << "Sum even number(s):" << sum << endl;
	cout << "Min " << min << endl;
	cout << "Max " << max << endl;

	swap(arr[min_ind], arr[max_ind]);

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	//-Output array
	return 0;
}