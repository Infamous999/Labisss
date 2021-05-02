#include <iostream>
#include <ctime>

using namespace std;

int amount();
int* arr(int n);
int arr_max(int n, int* arr);
int arr_min(int n, int* arr);
int selection();

int main()
{
	int n = amount();
	int* a = arr(n);
	int choose = selection();

	switch (choose)
	{
	case 1:
		cout << "max value = " << arr_max(n, a) << endl;
		break;
	case 2:
		cout << "min value = " << arr_min(n, a) << endl;
		break;
	default:
		cout << "Error choose 1 or 2" << endl;
		break;
	}
}
int selection()
{
	while (true)
	{
		int choose;
		cout << "Please choose max or min value of array 1 or 2" << endl;
		cin >> choose;

		if (cin.fail() || choose < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter 1 or 2 its max or min value of array" << endl;
		}
		else
			return choose;
	}
}
int amount()
{
	while (true)
	{
		int n;
		cout << "Enter the amount of elements of array " << endl;
		cin >> n;

		if (cin.fail() || n < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error enter the correct count";
		}
		else
			return n;
	}
}
int* arr(int n)
{
	int* arr = new int[n];
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 35;
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	return arr;
	delete[] arr;
}
int arr_max(int n, int* arr)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int arr_min(int n, int* arr)
{
	int min = 1500;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
