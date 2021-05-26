#include <iostream>
#include <math.h>

using namespace std;

class Vect;

double getValue();
void printEquality(Vect vector1, char symbol, Vect vector2, Vect result);

class Complex {
public:
    void input() {
        cout << "Комплексное число имеет вид: a + b * i" << endl;;
        cout << "Введите действительную часть a: ";
        a = getValue();
        cout << "Введите мнимую часть b: ";
        b = getValue();
    };
    void print() {
        if (b < 0)
            cout << a << b << "*i";
        else
            cout << a << "+" << b << "*i";
    };
    void changeSing() {
        a = -a;
        b = -b;
    }
    Complex operator+(Complex number) {
        Complex result;
        result.a = a + number.a;
        result.b = b + number.b;
        return result;
    };
    Complex operator-(Complex number) {
        Complex result;
        result.a = a - number.a;
        result.b = b - number.b;
        return result;
    };
    Complex operator*(Complex number) {
        Complex result;
        result.a = a * number.a - b * number.b;
        result.b = a * number.b + b * number.a;
        return result;
    };
private:
    double a, b;
};


class Vect {
public:
    void input() {
        for (int i = 0; i < 3; i++) {
            component[i].input();
        }
    };
    void print() {
        cout << "(";
        component[0].print();
        cout << ", ";
        component[1].print();
        cout << ", ";
        component[2].print();
        cout << ")";
    };
    Vect operator*(Vect vect) {
        Vect result;
        result.component[0] = component[1] * vect.component[2] - component[2] * vect.component[1];
        result.component[1] = component[0] * vect.component[2] - component[2] * vect.component[0];
        result.component[1].changeSing();
        result.component[2] = component[0] * vect.component[1] - component[1] * vect.component[0];
        return result;
    };
private:
    Complex component[3];
};


int main() {
    setlocale(LC_ALL, "Ru");
    Vect vector1, vector2, result;
    cout << "Введите первый вектор (вектор должен содержать 3 компоненты: x,y,z):" << endl;
    vector1.input();
    cout << endl;
    cout << "Введите второй вектор (вектор должен содержать 3 компоненты: x,y,z):" << endl;
    vector2.input();
    cout << endl;
    printEquality(vector1, '*', vector2, vector1 * vector2);
    return 0;
}

double getValue() {
    while (true) {
        double number;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Повторите ввод." << endl;
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

void printEquality(Vect vector1, char symbol, Vect vector2, Vect result) {
    vector1.print();
    cout << " " << symbol << " ";
    vector2.print();
    cout << " = ";
    result.print();
    cout << endl;
}
