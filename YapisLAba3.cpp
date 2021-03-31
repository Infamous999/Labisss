﻿#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int quantity()
{
	while (true)
	{
		cout << "Enter the quantity of elments array";
		int n;
		cin >> n;

		if (cin.fail() || n <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error Enter again please";
		}
		else
		{
			return n;
		}
	}
}
int main()
{
	srand(time(NULL));

	int value = quantity();
	double a = 0;
	int x;

	for (int i = 0; i < value; i++)
	{
		x = rand() % 100;
		cout << x << endl;
		a += pow(x, 2);
	}

	double rmsvalue = sqrt(a / value);
	cout << "Root mean square value " << rmsvalue << endl;
}
