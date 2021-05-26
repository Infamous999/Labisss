#include <iostream>
#include <math.h>

using namespace std;

double getDouble();
long long int factorial(int value);

class sinx {
public:
    sinx() {
        cout << "Введите x: ";
        x = getDouble();
        x = fmod(x, rad);
    }
    double getSinx() {
        solve();
        return sum;
    }
    double getX() {
        return x;
    }
private:
    double x = 0;
    const double rad = 2 * 3.1415;
    double sum = 0;
    void solve() {
        double term = 0;
        for (int i = 0; i < 10; i++) {
            term = pow(-1, i) * (pow(x, 2 * i + 1) / factorial(2 * i + 1));
            sum += term;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    sinx sin;
    cout << "Sin(" << sin.getX() << ") = " << sin.getSinx();
}

double getDouble() {
    while (true) {
        double value;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Повторите ввод." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return value;
        }
    }
}

long long int factorial(int value)
{
    if (value < 0)
        return 0;
    if (value == 0)
        return 1;
    else
        return value * factorial(value - 1);
}