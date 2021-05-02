#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    srand((int)time(0));
    int n, m;
    cout << "Enter the amount of rows" << endl;
    cout << "n =";
    cin >> n;
    cout << "Enter the amount of columns" << endl;
    cout << "m =";
    cin >> m;

    double** a = new double* [n];
    for (int i = 0; i < n; i++)
        a[i] = new double[m];

    double** b = new double* [m];
    for (int i = 0; i < m; i++)
        b[i] = new double[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % 9 + 1;
            b[j][i] = a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    a = b;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    for (int i = 0; i < m; i++)
        delete[] b[i];
    delete[] b;
    return 0;
}
