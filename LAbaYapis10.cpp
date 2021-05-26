#include <iostream>

using namespace std;
double getDouble();
int getInt();

class Qn {
public:
    void solve() {
        result = 0;
        for (int i = 0; i < n; i++) {
            result += a[i] * sin(i * x) + b[i] * cos(i * x);
        }
    }
    void input() {
        cout << "Введите n: ";
        n = getInt();
        a = new double[n];
        b = new double[n];
        cout << "Введите x: ";
        x = getDouble();
        cout << "Введите массив a, состоящий из " << n << " элементов: " << endl;
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            a[i] = getDouble();
        }
        cout << "Введите массив b, состоящий из " << n << " элементов: " << endl;
        for (int i = 0; i < n; i++) {
            cout << "Элемент " << i + 1 << ": ";
            b[i] = getDouble();
        }
    }
    Qn operator^(int number) {
        result = 0;
        if (number == 0)
            solve();
        switch (number % 4) {
        case 1:
            for (int i = 0; i < n; i++) {
                result += a[i] * pow(i, number) * cos(i * x) - b[i] * pow(i, number) * sin(i * x);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                result += -a[i] * pow(i, number) * sin(i * x) - b[i] * pow(i, number) * cos(i * x);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                result += -a[i] * pow(i, number) * cos(i * x) + b[i] * pow(i, number) * sin(i * x);
            }
            break;
        case 0:
            for (int i = 0; i < n; i++) {
                result += a[i] * pow(i, number) * sin(i * x) + b[i] * pow(i, number) * cos(i * x);
            }
            break;
        default:
            result = -1;
            break;
        }
        return *this;
    }
    void print() {
        cout << "Qn(x) = " << result << endl;
    }
private:
    int n;
    double* a, * b, x;
    double result;
};

int main() {
    setlocale(LC_ALL, "Ru");
    Qn qn;
    qn.input();
    qn.solve();
    qn.print();
    cout << "Введите порядок производной: ";
    int power = getInt();
    qn = qn ^ power;
    qn.print();
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

int getInt() {
    while (true) {
        int value;
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